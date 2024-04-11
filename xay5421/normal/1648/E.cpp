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
	dsu(){}
	dsu(int n_):n(n_),fa(n_){
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
			fa[u_]=v_;
			return 1;
		}
		return 0;
	}
};
const int N=200005;
int T,n,m,u_[N],v_[N],w_[N];
set<int>e[N];
vector<int>ver[N];
vector<pair<int,int> >ee[N];
void change(int u,int v){
	if(e[u].count(v))e[u].erase(v);
	if(e[v].count(u))e[v].erase(u);
	auto i=e[u].begin(),j=e[v].begin();
	while(1){
		if(i==e[u].end()&&j==e[v].end())break;
		if(j==e[v].end()){
			e[*i].erase(u);
			e[u].erase(i++);
		}else if(i==e[u].end()){
			e[*j].erase(v);
			e[v].erase(j++);
		}else if(*i==*j){
			e[*i].erase(u);
			e[u].erase(i++);
			++j;
		}else if(*i<*j){
			e[*i].erase(u);
			e[u].erase(i++);
		}else{
			e[*j].erase(v);
			e[v].erase(j++);
		}
	}
}
const int K=20;
int dep[N],f[N][K],g[N][K];
int query(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int dt=dep[u]-dep[v],ret=0;
	per(i,K-1,0)if(dt>>i&1)ret=max(ret,g[u][i]),u=f[u][i];
	if(u==v)return ret;
	per(i,K-1,0)if(f[u][i]!=f[v][i])ret=max({ret,g[u][i],g[v][i]}),u=f[u][i],v=f[v][i];
	return max({ret,g[u][0],g[v][0]});
}
void dfs(int k1,int k2,int k3){
	f[k1][0]=k2,g[k1][0]=k3,dep[k1]=dep[k2]+1;
	rep(i,1,K-1)f[k1][i]=f[f[k1][i-1]][i-1],g[k1][i]=max(g[k1][i-1],g[f[k1][i-1]][i-1]);
	each(x,ee[k1])if(get<0>(x)!=k2)dfs(get<0>(x),k1,get<1>(x));
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	rep(tc,1,T){
		// DD(tc);
		rd(n),rd(m);
		rep(i,1,n)ver[i]={i},ee[i].clear();
		vector<tuple<int,int,int> >es;
		rep(i,1,m){
			int u,v,w;
			rd(u),rd(v),rd(w);
			u_[i]=u,v_[i]=v,w_[i]=w;
			e[u].insert(v),e[v].insert(u);
			es.eb(w,u,v);
		}
		sort(es.begin(),es.end());
		dsu o(n+1),o_(n+1);
		vector<tuple<int,int,int> >es_;
		int cnt=0;
		each(x,es){
			// DD(x);
			int u,v,w;
			tie(w,u,v)=x;
			u=o.find(u),v=o.find(v);
			if(u==v)continue;
			each(x,ver[u])each(y,ver[v]){
				++cnt;
				assert(cnt<=m*2+n);
				if(!e[x].count(y)){
					if(o_.unite(x,y)){
						es_.eb(w,x,y);
					}
				}
			}
			vector<int>ver_;
			each(x,ver[u]){
				if(o_.find(x)!=x){
					change(x,o_.find(x));
				}else{
					ver_.pb(x);
				}
			}
			each(x,ver[v]){
				if(o_.find(x)!=x){
					change(x,o_.find(x));
				}else{
					ver_.pb(x);
				}
			}
			ver[u].clear();
			ver[v].clear();
			o.unite(u,v);
			ver[o.find(u)]=move(ver_);
		}
		sort(es_.begin(),es_.end());
		each(x,es_){
			int u,v,w;
			tie(w,u,v)=x;
			ee[u].eb(v,w);
			ee[v].eb(u,w);
		}
		// DD(es_);
		dfs(1,0,0);
		rep(i,1,m){
			printf("%d ",query(u_[i],v_[i]));
		}
		puts("");
	}
	return 0;
}