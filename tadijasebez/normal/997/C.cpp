#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int mod=998244353;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
const int N=1000050;
int F[N],I[N];
int binom(int n, int k){ return (ll)F[n]*I[k]%mod*I[n-k]%mod;}
int main()
{
	int i,j;
	F[0]=1;for(i=1;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	I[N-1]=pow(F[N-1],mod-2);for(i=N-2;~i;i--) I[i]=(ll)I[i+1]*(i+1)%mod;
	int ans=0,n;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		int mul=pow(mod-1,i);
		int tmp=(ll)(pow(3,i)-3+mod)%mod*pow(pow(3,n),n-i)%mod;
		tmp+=(ll)3*pow((pow(3,n-i)-1+mod)%mod,n)%mod;
		tmp%=mod;
		int add=(ll)binom(n,i)*tmp%mod;
		//printf("add:%i mul:%i\n",add,mul);
		ans+=(ll)add*mul%mod;
		if(ans>=mod) ans-=mod;
		if(ans<0) ans+=mod;
	}
	ans+=pow((pow(3,n)-3+mod)%mod,n);
	ans%=mod;
	ans=pow(pow(3,n),n)-ans;
	if(ans<0) ans+=mod;
	printf("%i\n",ans);
	return 0;
}