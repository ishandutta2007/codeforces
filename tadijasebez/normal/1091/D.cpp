#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int mod=998244353;
void add(int &x, int y){ x+=y;if(x>=mod) x-=mod;}
void sub(int &x, int y){ x-=y;if(x<0) x+=mod;}
void mul(int &x, int y){ x=(ll)x*y%mod;}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,mul(x,x)) if(k&1) mul(ans,x);return ans;}
int inv(int x){ return powmod(x,mod-2);}
void chp(int &x, int y){ x=(ll)x*inv(y)%mod;}
#define div chp
const int N=1000050;
int F[N],I[N];
void calc()
{
	F[0]=1;for(int i=1;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	I[N-1]=inv(F[N-1]);for(int i=N-2;~i;i--) I[i]=(ll)I[i+1]*(i+1)%mod;
}
int binom(int n, int k){ return (ll)F[n]*I[k]%mod*I[n-k]%mod;}
int main()
{
	calc();
	int n,i;
	scanf("%i",&n);
	int ans=0;
	for(int i=1;i<n;i++)
	{
		add(ans,(ll)binom(n,i+1)*i%mod*F[n-i]%mod);
	}
	add(ans,1);
	printf("%i\n",ans);
	return 0;
}