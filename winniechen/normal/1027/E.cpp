#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
#define N 505
#define mod 998244353
#define ll long long
ll f[N][N],g[N][N];
int n,K;
int main()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<=min(n,K-1);i++)
	{
		memset(g,0,sizeof(g));
		for(int j=1;j<=n;j++)
		{
			if(j!=1)g[j][1]=g[j-1][1];
			else g[1][1]=2;
			for(int k=2;k<=i;k++)
			{
				g[j][k]=g[j-1][k-1];
				g[j][1]=(g[j][1]+g[j-1][k])%mod;
			}
		}
		for(int j=1;j<=i;j++)f[1][i]=(f[1][i]+g[n][j])%mod;
		for(int j=1;j<i;j++)f[1][i]=(f[1][i]-f[1][j]+mod)%mod;
	}int tmp=min(n,K-1);memset(g,0,sizeof(g));
	for(int i=1;i<=tmp;i++)g[1][i]=f[1][i];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=tmp;j++)
		{
			f[i][j]=(f[i-1][j]*2)%mod;g[i][j]=f[i-1][j];
			int x=K/j;if(x*j<K)x++;//printf("%d\n",g[i-x+1][j]);
			if(i>=x)f[i][j]=(f[i][j]-g[i-x+1][j]+mod)%mod;
			// printf("i=%d j=%d %d x=%d\n",i,j,f[i][j],x);
		}
	}ll ans=0;
	for(int i=1;i<=tmp;i++)ans=(ans+f[n][i])%mod;
	printf("%lld\n",((ans+mod)%mod));return 0;
}