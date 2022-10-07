#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,s,e;
ll x[5005],a[5005],b[5005],c[5005],d[5005],f[5005][5005];
int main()
{
	scanf("%d%d%d",&n,&s,&e);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&d[i]);
	if(s>e)
	{
		swap(s,e);
		for(int i=1;i<=n;i++)
		{
			swap(a[i],c[i]);
			swap(b[i],d[i]);
		}
	}
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(i-1&&j==0)continue;
			if(j)
			{
				if(i!=s)f[i][j-1]=min(f[i][j-1],f[i-1][j]+a[i]+c[i]+2*x[i]);
				if(i!=s&&i!=e)f[i][j]=min(f[i][j],f[i-1][j]+a[i]+d[i]);
				if(i<=s||i>=e||j>1)f[i][j]=min(f[i][j],f[i-1][j]+b[i]+c[i]);
			}
			if(i!=e)f[i][j+1]=min(f[i][j+1],f[i-1][j]+b[i]+d[i]-2*x[i]);
		}
	}
	ll ans=f[n][0];
	ans-=x[e]-x[s]+c[e]+b[s];
	printf("%lld\n",ans);
	return 0;
}