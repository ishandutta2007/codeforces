#include <stdio.h>
#define ll long long
const int N=200050;
const int mod=1000000007;
int F[N],I[N];
int pow(int x, int k){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
int get(int n, int k){ return (ll)F[n]*I[k]%mod*I[n-k]%mod;}
int calc(int n, int k)
{
	if(k>n) return 0;
	int ret=0;
	for(int i=k;i;i--)
	{
		int add=(ll)get(k,i)*pow(i,n)%mod;
		if((k-i)&1) ret=(ret-add+mod)%mod;
		else ret=(ret+add)%mod;
	}
	return (ll)ret*I[k]%mod;
}
int main()
{
	int n,k,x,i,sum=0;
	F[0]=1;for(i=1;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	I[N-1]=pow(F[N-1],mod-2);for(i=N-2;i>=0;i--) I[i]=(ll)I[i+1]*(i+1)%mod;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&x),sum+=x,sum%=mod;
	printf("%i\n",(ll)sum*(calc(n,k)+(ll)(n-1)*calc(n-1,k)%mod)%mod);
	return 0;
}