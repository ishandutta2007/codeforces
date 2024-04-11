#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 2005
#define ll long long
ll suma[N],sumb[N],ta[N];
int a[N],b[N],n,m,X,ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),suma[i]=suma[i-1]+a[i];
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),sumb[i]=sumb[i-1]+b[i];
	scanf("%d",&X);
	for(int i=n;i;i--)
	{
		ta[i]=1<<30;
		for(int j=0;i+j<=n;j++)
			ta[i]=min(ta[i],suma[i+j]-suma[j]);
	}ta[n+1]=1<<30;
	for(int i=1;i<=m;i++)
		for(int j=0;i+j<=m;j++)
		{
			int p=upper_bound(ta+1,ta+n+2,X/(sumb[i+j]-sumb[j]))-ta-1;
			ans=max(i*p,ans);
		}
	printf("%d\n",ans);
}