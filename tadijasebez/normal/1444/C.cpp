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

const int N=500050;
struct DSU{
	int p[N],z[N],w[N];
	DSU(){}
	void init(int n){for(int i=1;i<=n;i++)p[i]=i,z[i]=1,w[i]=0;}
	int Find(int x){return p[x]==x?x:Find(p[x]);}
	int W(int x){return p[x]==x?0:w[x]^W(p[x]);}
	int bad;
	vector<int> stk;
	void Union(int x,int y){
		int v=W(x)^W(y)^1;
		x=Find(x);y=Find(y);
		if(x==y){
			if(v)bad++,stk.pb(-1);
			else stk.pb(0);
		}else{
			if(z[x]>z[y])swap(x,y);
			p[x]=y;
			z[y]+=z[x];
			w[x]=v;
			stk.pb(x);
		}
	}
	void Undo(){
		int o=stk.back();stk.pop_back();
		if(o>0){
			z[p[o]]-=z[o];
			w[o]=0;
			p[o]=o;
		}else bad+=o;
	}
}G;
map<pii,vector<pii>> edges;
int col[N];
bool good_group[N];
int main(){
	int n,m,k;rd(n,m,k);
	ra(col,n);
	for(int i=1;i<=m;i++){
		int u,v;rd(u,v);
		if(col[u]>col[v])swap(u,v);
		edges[{col[u],col[v]}].pb({u,v});
	}
	G.init(n);
	int cnt=0;
	for(int i=1;i<=k;i++){
		for(pii e:edges[{i,i}]){
			G.Union(e.first,e.second);
		}
		if(G.bad>0){
			int sz=edges[{i,i}].size();
			for(int j=0;j<sz;j++){
				G.Undo();
			}
		}else good_group[i]=1,cnt++;
	}
	ll ans=(ll)cnt*(cnt-1)/2;
	for(auto it:edges){
		int A,B;tie(A,B)=it.first;
		if(A==B)continue;
		if(!good_group[A]||!good_group[B])continue;
		for(pii e:it.second){
			G.Union(e.first,e.second);
		}
		if(G.bad>0)ans--;
		for(int i=0;i<it.second.size();i++){
			G.Undo();
		}
	}
	printf("%lld\n",ans);
	return 0;
}