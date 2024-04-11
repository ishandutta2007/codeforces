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

struct BIT{
	static const int NSZ=200050;
	ll sum[NSZ];
	int n;
	void init(int _n){n=_n;for(int i=0;i<=n;i++)sum[i]=0;}
	void Set(int i,ll f){for(;i<=n;i+=i&-i)sum[i]+=f;}
	ll Get(int i){ll ans=0;for(i=min(i,n);i;i-=i&-i)ans+=sum[i];return ans;}
	ll Get(int l,int r){return Get(r)-Get(l-1);}
}BT;

const int N=200050;
const int mod=998244353;
int a[N],pos[N],b[N];
int main(){
	for(int t=ri();t--;){
		int n,k;rd(n,k);
		BT.init(n);
		for(int i=1;i<=n;i++)BT.Set(i,1);
		ra(a,n);
		for(int i=1;i<=n;i++)pos[a[i]]=i;
		ra(b,k);
		set<int> idx={0,n+1};
		for(int i=1;i<=k;i++){
			idx.insert(pos[b[i]]);
		}
		int ans=1;
		for(int i=1;i<=k;i++){
			auto it=idx.find(pos[b[i]]);
			int L=*prev(it);
			int R=*next(it);
			int P=*it;
			int X=BT.Get(L+1,P-1);
			int Y=BT.Get(P+1,R-1);
			if(X==0&&Y==0)ans=0;
			if(X>0&&Y>0)ans=ans*2%mod;
			BT.Set(P,-1);
			idx.erase(P);
		}
		printf("%i\n",ans);
	}
	return 0;
}