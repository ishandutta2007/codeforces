#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int get_power(int a,int n)
{
	int res=1;
	while(n>0)
	{
		res=n&1?1ll*res*a%mod:res;
		a=1ll*a*a%mod;
		n>>=1;
	}
	return res;
}
inline int get_inv(int x)
{
	return get_power(x,mod-2);
}
inline int C2(int x)
{
	return (x*(x-1ll)>>1)%mod;
}
const int max_n=2e3+5;
int power_p[max_n],power_q[max_n];
int f[max_n],g[max_n],h[max_n][max_n];
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int p=1ll*a*get_inv(b)%mod;
	power_p[0]=power_q[0]=1;
	for(int i=1;i<=n;++i)
	{
		power_p[i]=1ll*power_p[i-1]*p%mod;
		power_q[i]=power_q[i-1]*(mod+1ll-p)%mod;
	}
	h[1][0]=h[1][1]=1;
	for(int i=2;i<=n;++i)
		for(int j=0;j<=i;++j)
			h[i][j]=(1ll*h[i-1][j]*power_p[j]+(j>0?1ll*h[i-1][j-1]*power_q[i-j]:0))%mod;
	for(int i=1;i<=n;++i)
	{
		g[i]=1;
		for(int j=1;j<=i-1;++j)
		{
			g[i]-=1ll*g[j]*h[i][j]%mod;
			g[i]+=g[i]<0?mod:0;
		}
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=1ll*g[i]*h[i][i]%mod*C2(i)%mod;
		for(int j=1;j<=i-1;++j)
			f[i]=(f[i]+1ll*g[j]*h[i][j]%mod*(1ll*f[j]+f[i-j]+C2(i)-C2(i-j)+mod))%mod;
		f[i]=1ll*f[i]*get_inv(mod+1-1ll*g[i]*h[i][i]%mod)%mod;
	}
	printf("%d\n",f[n]);
    return 0;
}