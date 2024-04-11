#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int mod=1e9+7;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}

const int N=42;
int F[N],I[N];
int binom(int n,int k){return mul(F[n],mul(I[k],I[n-k]));}

map<vector<pii>,int> dp;
int DP(vector<pii> cycles){
	if(dp.count(cycles))return dp[cycles];
	if(cycles.empty())return 1;
	int n=0,ways=1;
	for(pii cs:cycles)n+=cs.first*cs.second,ways*=cs.second+1;
	int ans=0;
	for(int mask=1;mask<ways;mask++){
		vector<pii> go;
		int tmp=mask,cnt=0,now=1,m=0;
		for(pii cs:cycles){
			int rem=tmp%(cs.second+1);
			tmp/=cs.second+1;
			if(rem!=cs.second)go.pb({cs.first,cs.second-rem});
			ckmul(now,binom(cs.second,rem));
			ckmul(now,powmod(F[n-1],rem*cs.first));
			m+=rem*cs.first;
			cnt+=rem;
		}
		ckmul(now,mul(powmod(mul(binom(n,m),F[m]),n-m),DP(go)));
		if(cnt&1)ckadd(ans,now);
		else cksub(ans,now);
	}
	return dp[cycles]=ans;
}

int p[N],was[N];
int main(){
	F[0]=1;for(int i=1;i<N;i++)F[i]=mul(F[i-1],i);
	I[0]=I[1]=1;for(int i=2;i<N;i++)I[i]=mul(mod-mod/i,I[mod%i]);
	for(int i=1;i<N;i++)ckmul(I[i],I[i-1]);
	int n=ri();
	ra(p,n);
	map<int,int> cycles;
	for(int i=1;i<=n;i++)if(!was[i]){
		int sz=0;
		for(int j=i;!was[j];j=p[j]){
			was[j]=1;sz++;
		}
		cycles[sz]++;
	}
	printf("%i\n",DP(vector<pii>(cycles.begin(),cycles.end())));
	return 0;
}