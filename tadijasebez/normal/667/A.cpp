#include <stdio.h>
#include <cmath>
const double PI=acos(-1);
int main()
{
	int d,h,v,e;
	double v1,z,v2;
	scanf("%i %i %i %i",&d,&h,&v,&e);
	v1=d*d*PI/4*e;
	z=d*d*PI/4*h;
	v2=(double) v;
	if(v1>=v2) printf("NO\n");
	else
	{
		printf("YES\n");
		printf("%.12llf\n",z/(v2-v1));
	}
	return 0;
}