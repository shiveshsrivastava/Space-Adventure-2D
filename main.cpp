#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

class enemy
{
    public: GLfloat X1 = 200.0,Y1 = 500.0;

            int genRandoms(int lower, int upper)
            {
                int num = (rand() % (upper - lower + 1)) + lower;
                return num;
            }
            void drawEnemies(void)
            {
                if(Y1 < 0.0)
                {
                    Y1 = 500;
                    X1 = genRandoms(75,450);
                }

                glPointSize(15.0);

                glColor3f(1.0,1.0,1.0);

                glBegin(GL_POINTS);
                    glVertex2f(X1,Y1);
                    Y1-=0.5;
                glEnd();

                glutPostRedisplay();
                //lineGenEqu();
            }
            int collision(void);

}E1,E2;

int genRandoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

GLfloat posX=0.0,posY=0.0,posZ=0.0;
float f=0.0,t=0.0;
const float DEG2RAD = 3.14159/180;
float move1 = 0.0;
float move2 = 500.0;
//GLfloat enX = 0.0, enY = 0.0, enZ = 0.0;
int x,y,c=0;
GLfloat shipNX[3] = {213.0,217.0,215.0}, shipNY[3] = {55.0,55.0,70.0};
GLfloat shipBX[4] = {213.0,217.0,217.0,213.0}, shipBY[4] = {16.0,16.0,55.0,55.0};
GLfloat shipLWX[3] = {200.0,213.0,213.0},shipLWY[3] = {16.0,16.0,55.0};
GLfloat shipRWX[3] = {217.0,230.0,217.0},shipRWY[3] = {16.0,16.0,55.0};
GLfloat shipLBX[4] = {204.5,208.5,208.5,204.5},shipLBY[4] = {9.0,9.0,16.0,16.0};
GLfloat shipRBX[4] = {220.5,224.5,224.5,220.5},shipRBY[4] = {9.0,9.0,16.0,16.0};

void mars(float radius)
{

    glColor3f(1.0,1.0,1.0);
   glBegin(GL_POLYGON);

   for (int i=0; i<=359; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(300+f+cos(degInRad)*radius,500-t+(sin(degInRad)) *radius);
   }

   glEnd();
   t=t+0.1;
   f=f+0.1;
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);
}
/*
void lineGenEqu()
{
    glPointSize(5.0);
    glClear(GL_COLOR_BUFFER_BIT);
    int dx = abs(X2-X1), dy = abs(Y2-Y1);
    int p = 2*dy-dx;
    int twoDy = 2*dy, twoDyDx = 2*(dy-dx);
    int x,y;

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
        glVertex2i(X1,Y1);
    glEnd();

    if(x = X2)
    {
        x = X2;
        y = Y1;
        X2 = X1;
    }
    else
    {
        x = X1;
        y = Y1;
    }
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);

    while(x < X2)
    {
        x++;
        if(p < 0)
            p+=twoDy;
        else
        {
            y++;
            p+=twoDyDx;
        }
        glVertex2i(x,y);
    }
    glEnd();
    glFlush();
}
*/
/*
void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.141592;

	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}
*/

void drawShip(void)
{
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        for(int i= 0;i<3;i++)
            glVertex2f(shipNX[i],shipNY[i]);
    glEnd();

    glColor3f(0.0,0.5,1.0);
    glBegin(GL_POLYGON);
        for(int i=0;i<4;i++)
            glVertex2f(shipBX[i], shipBY[i]);
        glEnd();

    //glColor3f(1.0,0.2,0.1);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        for(int i= 0;i<3;i++)
            glVertex2f(shipLWX[i],shipLWY[i]);
    glEnd();

    glBegin(GL_POLYGON);
        for(int i= 0;i<3;i++)
            glVertex2f(shipRWX[i],shipRWY[i]);
    glEnd();

    glColor3f(0.36,0.36,0.36);
    glBegin(GL_POLYGON);
        for(int i= 0;i<4;i++)
            glVertex2f(shipLBX[i],shipLBY[i]);
    glEnd();

    glBegin(GL_POLYGON);
        for(int i= 0;i<4;i++)
            glVertex2f(shipRBX[i],shipRBY[i]);
    glEnd();
}

void drawStars(void)
{int l;
	glColor3f(1.0,1.0,1.0);
	glPointSize(0.3);
	glBegin(GL_POINTS);

	glVertex2i(50,20);
	glVertex2i(70,100);
	glVertex2i(80,10);
	glVertex2i(65,150);
	glVertex2i(67,80);
	glVertex2i(105,33);
	glVertex2i(450,300);
	glVertex2i(380,110);
	glVertex2i(175,63);
	glVertex2i(113,125);
	glVertex2i(70,10);
	glVertex2i(160,330);
	glVertex2i(490,430);
	glVertex2i(82,65);
	glVertex2i(160,440);
	glVertex2i(440,490);
	glVertex2i(62,90);
	glVertex2i(450,322);
	glVertex2i(420,366);
	glVertex2i(455,400);
	glVertex2i(60,20);
	glVertex2i(111,120);
	glVertex2i(451,200);
	glVertex2i(280,30);
	glVertex2i(220,20);
	glVertex2i(132,378);
	glVertex2i(173,340);
	glVertex2i(325,420);
	glVertex2i(180,360);
	glVertex2i(383,120);
	glVertex2i(200,22);
	glVertex2i(342,11);
	glVertex2i(330,332);
	glVertex2i(283,40);
	glVertex2i(210,418);
	glVertex2i(256,12);
	glVertex2i(288,232);
	glVertex2i(247,36);
	glVertex2i(229,342);
	glVertex2i(257,47);
	glVertex2i(290,63);
	glVertex2i(232,72);
	glVertex2i(243,143);
	glVertex2i(100,200);
	glVertex2i(90,250);
	glVertex2i(80,225);
	glVertex2i(50,333);
	glVertex2i(60,350);
	glVertex2i(243,143);
	glVertex2i(243,143);
	glVertex2i(10,323);
	glVertex2i(5,73);
	glVertex2i(6,74);
	glVertex2i(15,43);
	glVertex2i(13,257);

	glEnd();
	for(l=0;l<=10000;l++)
		;

}

int enemy::collision(void)
{

    if((X1 > shipLBX[0] && X1 < shipRBX[1] && Y1 > shipLWY[0] && Y1 < shipLWY[0]+4.3)
       || (X1 > shipNX[0] && X1 < shipNX[1] && Y1 > shipNY[0] && Y1 < shipNY[2])
       || (X1 > shipLWX[0] && X1 < shipRWX[1] && Y1 > shipLWY[0] && Y1 < shipLWY[0]+1.0))
        return 1;
    return 0;
}



void display(void)
{

    if(/*(E1.X1 > shipLBX[0] && E1.X1 < shipRBX[1] && E1.Y1 > shipLWY[0] && E1.Y1 < shipLWY[0]+4.3)
       || (E2.X1 > shipLBX[0] && E2.X1 < shipRBX[1] && E2.Y1 > shipLWY[0] && E2.Y1 < shipLWY[0]+4.3)
       || (E1.X1 > shipNX[0] && E1.X1 < shipNX[1] && E1.Y1 > shipNY[0] && E1.Y1 < shipNY[2])
       || (E2.X1 > shipNX[0] && E2.X1 < shipNX[1] && E2.Y1 > shipNY[0] && E2.Y1 < shipNY[2])
       || (E1.X1 > shipLWX[0] && E1.X1 < shipRWX[1] && E1.Y1 > shipLWY[0] && E1.Y1 < shipLWY[0]+1.0)
       || (E2.X1 > shipLWX[0] && E2.X1 < shipRWX[1] && E2.Y1 > shipLWY[0] && E2.Y1 < shipLWY[0]+1.0)*/
       E1.collision() || E2.collision())
    {
        //printf("%f > %f\n%f < %f",E1.X1,shipLBX[0],E1.X1,shipRBX[1]);
        //printf("Collision Yo!\n");
        exit(0);
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0,move1,0.0);
        move1 = move1-0.1;
        if(move1 <= -500)
            move1 = 0.0;
        drawStars();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.0,move2,0.0);
        move2 = move2-0.1;
        if(move2 <= 0.0)
            move2 = 500.0;
        drawStars();
    glPopMatrix();



    glPushMatrix();
        E1.drawEnemies();
    glPopMatrix();

    glPushMatrix();
        E2.drawEnemies();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(posX,posY,posZ);
    //c++;

    drawShip();

    //mars(10.0);

    glPopMatrix();
    glFlush();
}

void keys(unsigned char key, int x, int y)
{
    if(key == 'w' || key == 'W')
    {
        //printf("%f\n",shipNY[0]);
        if(shipNY[0] >= 460.0)
            return;

        for(int i=0;i<3;i++)
        {
            shipNY[i] += 10.0;
            shipLWY[i] += 10.0;
            shipRWY[i] += 10.0;
        }
        for(int i = 0;i<4;i++)
        {
            shipBY[i] += 10.0;
            shipLBY[i] += 10.0;
            shipRBY[i] += 10.0;
        }
    }
    if(key == 's' || key == 'S')
    {
        //printf("%f\n",shipNY[0]);
        if(shipNY[0] <= 55.0)
            return;

        for(int i=0;i<3;i++)
        {
            shipNY[i] -= 5.0;
            shipLWY[i] -= 5.0;
            shipRWY[i] -= 5.0;
        }

        for(int i = 0;i<4;i++)
        {
            shipBY[i] -= 5.0;
            shipLBY[i] -= 5.0;
            shipRBY[i] -= 5.0;
        }

    }

    if(key == 'a' || key == 'A')
    {
        //printf("%f\n",shipLBX[0]);
        if(shipLBX[0] <= 14.5)
            return;

        for(int i=0;i<3;i++)
        {
            shipNX[i] -= 5.0;
            shipLWX[i] -= 5.0;
            shipRWX[i] -= 5.0;
        }
        for(int i = 0;i<4;i++)
        {
            shipBX[i] -= 5.0;
            shipLBX[i] -= 5.0;
            shipRBX[i] -= 5.0;
        }

    }
    if(key == 'd' || key == 'D')
    {
        printf("%f\n",shipNX[0]);
        if(shipNX[0] >= 470.0)
            return;

        for(int i=0;i<3;i++)
        {
            shipNX[i] += 5.0;
            shipLWX[i] += 5.0;
            shipRWX[i] += 5.0;
        }
        for(int i = 0;i<4;i++)
        {
            shipBX[i] += 5.0;
            shipLBX[i] += 5.0;
            shipRBX[i] += 5.0;
        }

    }

    if(key == 27)
        exit(0);

    glutPostRedisplay();
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1366,700);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Triangle");
    init();
    glutFullScreen();
    glutDisplayFunc(display);
//    glutTimerFunc(25, lineGenEqu, 0);
    glutKeyboardFunc(keys);
    //glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
