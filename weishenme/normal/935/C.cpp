#include<bits/stdc++.h>
using namespace std;
#define y1 ____y1
typedef double ld;
ld R,x1,y2,x2,y1;
int main()
{
	scanf("%lf%lf%lf%lf%lf",&R,&x1,&y1,&x2,&y2);
	if (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>=R)
	 {
		printf("%.15lf %.15lf %.15lf",x1,y1,R); 
		return 0;
	 }
	ld d=(R+sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))/2;
	ld r=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if (r==0)
	 {
	 	ld x3=(x1+R+x2)/2,y3=(y1+y2)/2;
		printf("%.15lf %.15lf %.15lf",x3,y3,d); 
		return 0;
	 }
	ld x3=x2-d/r*(x2-x1),y3=y2-d/r*(y2-y1);
	printf("%.15lf %.15lf %.15lf",x3,y3,d); 
}