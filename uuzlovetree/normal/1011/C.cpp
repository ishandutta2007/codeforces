#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
const double eps=1e-7;
int n;
double m;
double a[maxn],b[maxn],c[maxn*2];
int main()
{
	scanf("%d",&n);
	scanf("%lf",&m);
	for(int i=1;i<=n;++i)scanf("%lf",&a[i]);
	for(int i=1;i<=n;++i)scanf("%lf",&b[i]);
	for(int i=1;i<=n;++i)c[i*2-2]=b[i],c[i*2-1]=a[i];
	c[0]=0;c[n*2]=b[1];n*=2;
	for(int i=1;i<=n;++i)
	{
		if(c[i]-1<=eps)
		{
			puts("-1");
			return 0;
		}
	}
	double t=0;
	for(int i=n;i;--i)
	{
		t=(m+c[i]*t)/(c[i]-1);
	}
	printf("%.10lf\n",t);
	return 0;
}