#include <stdio.h>
const int mod=998244353;
const int N=5050;
int min(int a, int b){ return a>b?b:a;}
int pow(int x, int k)
{
	int ans=1;
	for(;k;k>>=1,x=1ll*x*x%mod) if(k&1) ans=1ll*ans*x%mod;
	return ans;
}
int F[N];
int Solve(int a, int b)
{
	int ans=0,x,y,i;
	for(i=0;i<=min(a,b);i++)
	{
		x=1ll*F[a]*pow(F[a-i],mod-2)%mod*pow(F[i],mod-2)%mod;
		y=1ll*F[b]*pow(F[b-i],mod-2)%mod*pow(F[i],mod-2)%mod;
		ans=(1ll*x*y%mod*F[i]%mod+ans)%mod;
	}
	return ans;
}
int main()
{
	int a,b,c,i;
	scanf("%i %i %i",&a,&b,&c);
	F[0]=1;
	for(i=1;i<N;i++) F[i]=1ll*F[i-1]*i%mod;
	printf("%i\n",1ll*Solve(a,b)*Solve(b,c)%mod*Solve(c,a)%mod);
}