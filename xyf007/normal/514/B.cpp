#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
std::map<double,int>f;
int n;
double x,y;
struct man
{
	double x,y;
}a[10001];
int main()
{
	scanf("%d%lf%lf",&n,&x,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i].x,&a[i].y);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		double slope=(a[i].x-x)/(a[i].y-y);
		if(fabs(a[i].y-y)<1e-6)
		{
			slope=1e20;
		}
		if(f[slope])
		{
			continue;
		}
		sum++;
		f[slope]=1;
	}
	printf("%d",sum);
	return 0;
}
//fw