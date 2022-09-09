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

const int mod=998244353;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}

const int N=1000050;
int dp[N],sum[N],strict[N],ways[N];
const int inv2=(mod+1)/2;
const int inv6=powmod(6,mod-2);
int pref[N];
int main(){
	int n=ri();
	dp[0]=1;
	dp[1]=1;
	sum[0]=1;
	sum[1]=2;
	for(int i=2;i<=n+1;i++){
		dp[i]=mul(dp[i-1],mul((dp[i-1]+1),inv2));
		ckadd(dp[i],mul(dp[i-1],sum[i-2]));
		strict[i]=sub(dp[i],dp[i-1]);
		sum[i]=add(sum[i-1],dp[i]);
		cksub(sum[i-2],1);
		ways[i]=mul(dp[i-1],mul((dp[i-1]+1),mul(dp[i-1]+2,inv6)));
		//printf("%i\n",ways[i]);
		ckadd(ways[i],mul(dp[i-1],mul(dp[i-1]+1,mul(inv2,sum[i-2]))));
		//printf("%i\n",ways[i]);
		ckadd(ways[i],mul(dp[i-1],mul(sum[i-2],mul(sum[i-2]+1,inv2))));
		//printf("%i\n",ways[i]);
		ckadd(sum[i-2],1);
	}
	strict[1]=1;
	for(int i=1;i<=n;i++){
		pref[i]=add(pref[i-1],strict[i]);
	}
	int ans=0;
	for(int x=1;x<=n;x++){
		//for(int y=1;x+y<=n+1;y++){
		//	ckadd(ans,mul(strict[x],strict[y]));
		//}
		ckadd(ans,mul(strict[x],pref[n+1-x]));
	}
	ckadd(ans,mul(2,add(ways[n+1],strict[n+1])));
	printf("%i\n",ans);
	return 0;
}