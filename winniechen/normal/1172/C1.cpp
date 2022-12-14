#include <bits/stdc++.h>
using namespace std;
#define N 55
#define ll long long
#define mod 998244353
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
int f[N][N][N],a[N],w[N],n,m;
int solve(int x)
{
	long long s0=0,s1=0,s=0;
	for(int i=1;i<=n;i++)if(i!=x&&a[i])s1+=w[i];else if(i!=x)s0+=w[i];
	for(int i=1;i<=n;i++)s+=w[i];
	memset(f,0,sizeof(f));f[0][0][0]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=i-j;k++)
			{
				int l=i-j-k;
				ll t0=s0-j,t1=s1+l,tw=w[x]+(a[x]?k:-k);
				if(t0<0||tw<0)continue;
				// printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
				ll inv=q_pow((t0+t1+tw)%mod,mod-2);
				f[i+1][j+1][k]=(f[i+1][j+1][k]+(ll)f[i][j][k]*t0%mod*inv)%mod;
				f[i+1][j][k+1]=(f[i+1][j][k+1]+(ll)f[i][j][k]*tw%mod*inv)%mod;
				f[i+1][j][k]=(f[i+1][j][k]+(ll)f[i][j][k]*t1%mod*inv)%mod;
				// printf("%d %d %d\n",f[i+1][j+1][k],f[i+1][j][k+1],f[]);
			}
	int ans=0;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			ans=(ans+(ll)(w[x]+(a[x]?j:-j))*f[m][i][j])%mod;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)printf("%d\n",solve(i));
}