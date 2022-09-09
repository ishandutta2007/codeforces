#include <stdio.h>
int sol;
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
int min(int a, int b)
{
	if(a>b) return b;
	else return a;
}
int main()
{
	int x,y,i;
	int xx,yy,xxx,yyy;
	scanf("%i %i",&x,&y);
	int tmp=x;
	x=y;
	y=tmp;
	if(x==0 && y==0) printf("0\n");
	else if(x==0 && y==1) printf("0\n");
	else
	{
		xxx=0;
		yyy=0;
		for(i=1;i<=100;i++)
		{
			xx=-(i-1);
			yy=i;
			//printf("%i %i\n",xx,yy,x,y);
			//if(xx==x && yy==y) break;
			if(xxx==xx && xx==x && y<=max(yy,yyy) && y>=min(yy,yyy)) break;
			if(yyy==yy && yy==y && x<=max(xx,xxx) && x>=min(xx,xxx)) break;
			sol++;
			xxx=i;
			yyy=i;
			//printf("%i %i\n",xx,yy,x,y);
			//if(xx==x && yy==y) break;
			if(xxx==xx && xx==x && y<=max(yy,yyy) && y>=min(yy,yyy)) break;
			if(yyy==yy && yy==y && x<=max(xx,xxx) && x>=min(xx,xxx)) break;
			sol++;
			xx=i;
			yy=-i;
			//printf("%i %i\n",xx,yy,x,y);
			//if(xx==x && yy==y) break;
			if(xxx==xx && xx==x && y<=max(yy,yyy) && y>=min(yy,yyy)) break;
			if(yyy==yy && yy==y && x<=max(xx,xxx) && x>=min(xx,xxx)) break;
			sol++;
			xxx=-i;
			yyy=-i;
			//printf("%i %i\n",xx,yy,x,y);
			//if(xx==x && yy==y) break;
			if(xxx==xx && xx==x && y<=max(yy,yyy) && y>=min(yy,yyy)) break;
			if(yyy==yy && yy==y && x<=max(xx,xxx) && x>=min(xx,xxx)) break;
			sol++;
		}
		printf("%i\n",sol);
	}
	return 0;
}