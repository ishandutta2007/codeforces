#include <stdio.h>
#include <cmath>
double max(double a, double b){ return a>b?a:b;}
const int N=1050;
int x[N];
double y[N];
int abs(int x){ return x>0?x:-x;}
int main()
{
	int n,r,i,j;
	scanf("%i %i",&n,&r); r*=2;
	for(i=1;i<=n;i++) scanf("%i",&x[i]);
	for(i=1;i<=n;i++)
	{
		bool ok=1;
		for(j=1;j<i;j++)
		{
			if(abs(x[i]-x[j])<=r)
			{
				double tmp=y[j]+sqrt(r*r-(x[i]-x[j])*(x[i]-x[j]));
				y[i]=max(y[i],tmp);
				ok=0;
			}
		}
		if(ok)
		{
			y[i]=(double)r/2;
		}
		printf("%.15lf ",y[i]);
	}
	return 0;
}