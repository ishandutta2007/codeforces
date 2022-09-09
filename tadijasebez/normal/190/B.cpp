#include <stdio.h>
#include <cmath>
int min(int a, int b){ return a>b? b:a;}
int max(int a, int b){ return a>b? a:b;}
int main()
{
	int x,y,r,X,Y,R;
	scanf("%i %i %i",&x,&y,&r);
	scanf("%i %i %i",&X,&Y,&R);
	double sol=0.5*(sqrt((x-X)*(x-X)+(y-Y)*(y-Y))-r-R);
	//printf("%.12llf\n",sqrt((x-X)*(x-X)+(y-Y)*(y-Y)));
	if(sol<0 && 0.5*max(r,R)>sqrt((x-X)*(x-X)+(y-Y)*(y-Y))) sol=-sol,sol-=min(r,R);
	else if(sol<0) sol=0;
	printf("%.12llf\n",sol);
	return 0;
}