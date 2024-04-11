#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int mod=998244353;
int powmod(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
const int N=100050;
int F[N],I[N];
int binom(int n, int k){ return (ll)F[n]*I[k]%mod*I[n-k]%mod;}
int main()
{
	int n,m,k,i;
	scanf("%i %i %i",&n,&m,&k);
	if(m==1 && k>0) return 0*printf("0\n");
	F[0]=1;for(i=1;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	I[N-1]=powmod(F[N-1],mod-2);
	for(i=N-2;~i;i--) I[i]=(ll)I[i+1]*(i+1)%mod;
	k++;
	int ans=binom(n-1,k-1);
	ans=(ll)ans*m%mod*powmod(m-1,k-1)%mod;
	printf("%i\n",ans);
	return 0;
}