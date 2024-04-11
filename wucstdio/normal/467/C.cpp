#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,m,k,p[5005],sum[5005],f[5005][5005];
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
		sum[i]=sum[i-1]+p[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			f[i][j]=f[i-1][j];
			if(i-m>=0)f[i][j]=max(f[i][j],f[i-m][j-1]+sum[i]-sum[i-m]);
		}
	}
	printf("%lld\n",f[n][k]);
	return 0;
}