#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define mod 998244353
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
int f[3005][3005],a[N],w[N],n,m,ans;ll e0,e1,s0,s1;
void get_f()
{
	for(int i=1;i<=n;i++)if(a[i])s1+=w[i];else s0+=w[i];
	f[0][0]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<=i;j++)
			{
				int k=i-j;
				ll t0=s0-j,t1=s1+k;
				if(t0<0)continue;
				ll inv=q_pow((t0+t1)%mod,mod-2);
				f[i+1][j+1]=(f[i+1][j+1]+(ll)f[i][j]*t0%mod*inv)%mod;
				f[i+1][j]=(f[i+1][j]+(ll)f[i][j]*t1%mod*inv)%mod;
			}
	for(int i=m;~i;i--)
		e0=(e0+(ll)f[m][i]*(s0-i))%mod,e1=(e1+(ll)f[m][i]*(s1+m-i))%mod;
}
int solve(int x)
{
	if(!a[x])return (ll)e0*q_pow(s0,mod-2)%mod*w[x]%mod;
	return (ll)e1*q_pow(s1,mod-2)%mod*w[x]%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);get_f();
	for(int i=1;i<=n;i++)printf("%d\n",solve(i));
}