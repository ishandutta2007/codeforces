#include <cstdio>
#include <cmath>

double PI;

int main()
{
	PI=acos(-1.0);
	int d, h, v, e;
	scanf("%i %i %i %i",&d,&h,&v,&e);
	double area=PI*((double)d*d)/4.0;
	double dec=v/area-e;
	if(dec<=0)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n%.7llf\n",h/dec);
}