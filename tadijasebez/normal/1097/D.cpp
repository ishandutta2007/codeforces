#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int mod=1e9+7;
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
int dp[1000],ad[1000];
int Calc(ll p, int sz, int k)
{
	int all=0;
	dp[sz]=1;for(int i=0;i<sz;i++) dp[i]=0;
	for(int j=1;j<=k;j++)
	{
		for(int i=0;i<=sz;i++)
		{
			ad[i]=(ll)dp[i]*inv(i+1)%mod;
		}
		int sum=0;
		for(int i=sz;i>=0;i--)
		{
			add(sum,ad[i]);
			dp[i]=sum;
		}
	}
	/*for(int i=0;i<=sz;i++)
	{
		dp[i]=binom(i+k-1,i);
		printf("%i : %i\n",i,dp[i]);
		add(all,dp[i]);
		//powmod((ll)(i+1)*inv(sz+1)%mod,k);
	}
	for(int i=0;i<=sz;i++) div(dp[i],all);*/
	//for(int i=sz;i>=0;i--) sub(dp[i],dp[i-1]);
	int ans=0;
	for(int i=0;i<=sz;i++)
	{
		add(ans,(ll)powmod(p%mod,i)*dp[i]%mod);
	}
	return ans;
}
int main()
{
	calc();
	//for(int i=0;i<5;i++) printf("%i ",I[i]);
	ll n;int k;
	scanf("%lld %i",&n,&k);
    vector<pair<ll,int> > pr;
    for(ll i=2;i*i<=n;i++)
	{
		if(n%i) continue;
		int c=0;
		while(n%i==0) n/=i,c++;
		pr.pb(mp(i,c));
	}
	if(n>1) pr.pb(mp(n,1));
    int ans=1;
    for(auto p:pr)
	{
		int exp=Calc(p.first,p.second,k);
		//printf("%lld %i exp:%i\n",p.first,p.second,exp);
		mul(ans,exp);
	}
	printf("%i\n",ans);
	return 0;
}