#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 1005
#define eps 1e-9
double a[N],b[N],k;
int n,num[N];
bool check(long double x)
{
	long double left=x;
	for(int i=1;i<=n;i++)
	{
		long double tmp=(left+k)/a[i];
		left-=tmp;
		if(left<-eps)return 1;
		tmp=(left+k)/b[i+1];
		left-=tmp;
		if(left<-eps)return 1;
	}return 0;
}
int main()
{
	scanf("%d%lf",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lf",&b[i]);b[n+1]=b[1];
	long double l=0,r=1e9+1.0;
	while(l<r-eps)
	{
		long double m=(l+r)/2;
		if(check(m))l=m+eps;
		else r=m;
	}
	if(((l+r)/2)>1e9)puts("-1");
	else printf("%.7f\n",double((l+r)/2));
}