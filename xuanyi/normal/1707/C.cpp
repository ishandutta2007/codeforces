#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
class dsu{
public:
	int n;
	vector<int>fa;
	vector<int>sz;
	dsu(){}
	dsu(int n_):n(n_),fa(n_),sz(n_,1){
		iota(fa.begin(),fa.end(),0);
	}
	void assign(int n_){
		*this=dsu(n_);
	}
	int find(int u){
		return fa[u]==u?u:fa[u]=find(fa[u]);
	}
	bool check(int u,int v){
		return find(u)==find(v);
	}
	bool unite(int u,int v){
		int u_=find(u);
		int v_=find(v);
		if(u_!=v_){
			if(sz[v_]<sz[u_]){
				int tmp=u_;
				u_=v_;
				v_=tmp;
			}
			sz[v_]+=sz[u_];
			fa[u_]=v_;
			return 1;
		}
		return 0;
	}
};
const int N=100005,M=200005,K=20;
int n,m;
bool is[M];
int eu[M],ev[M];
vector<pair<int,int> >e[N];
vector<int>g[N];
int fa[N][K],dep[N];
void dfs1(int k1,int k2){
	fa[k1][0]=k2,dep[k1]=dep[k2]+1;
	rep(i,1,K-1)fa[k1][i]=fa[fa[k1][i-1]][i-1];
	each(x,g[k1])if(x!=k2)dfs1(x,k1);
}
LL cf[N];
LL w[N];
void dfs2(int k1,int k2){
	each(x,g[k1])if(x!=k2)dfs2(x,k1),cf[k1]+=cf[x];
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int dt=dep[u]-dep[v];
	per(i,K-1,0)if(dt>>i&1)u=fa[u][i];
	if(u==v)return u;
	per(i,K-1,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs3(int k1,int k2){
	each(x,g[k1])if(x!=k2)w[x]+=w[k1],dfs3(x,k1);
}
int main(){
	rd(n),rd(m);
	dsu o(n+1);
	rep(i,1,m){
		int u,v;
		rd(u),rd(v);
		e[u].eb(v,i),e[v].eb(u,i);
		eu[i]=u,ev[i]=v;
		if(o.unite(u,v)){
			is[i]=1;
			g[u].pb(v);
			g[v].pb(u);
		}
	}
	dfs1(1,0);
	rep(i,1,m)if(!is[i]){
		int u=eu[i];
		int v=ev[i];
		if(dep[u]<dep[v])swap(u,v);
		int t=LCA(u,v);
		if(t==v){
			cf[fa[u][0]]+=1;
			cf[v]-=1;
			w[u]-=dep[u]-dep[v]-1;
		}else{
			cf[fa[u][0]]+=1;
			cf[fa[v][0]]+=1;
			cf[t]-=1;
			//cf[fa[t][0]]-=1;
			w[u]-=dep[u]-1;
			w[v]-=dep[v]-1;
		}
	}
	dfs2(1,0);
	rep(i,1,n)w[i]+=cf[i];
	dfs3(1,0);
	rep(i,1,n)putchar(w[i]?'0':'1');
	return 0;
}