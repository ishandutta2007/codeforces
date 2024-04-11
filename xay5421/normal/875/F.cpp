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
class dsu_cycle:public dsu{
public:
	vector<int>vis;
	dsu_cycle(){}
	dsu_cycle(int n):dsu(n),vis(n){}
	void assign(int n_){
		*this=dsu_cycle(n_);
	}
	bool unite(int u,int v){
		int u_=find(u);
		int v_=find(v);
		if(u_!=v_){
			if(vis[u_]&&vis[v_]){
				return 0;
			}
			if(sz[v_]<sz[u_]){
				int tmp=u_;
				u_=v_;
				v_=tmp;
			}
			vis[v_]|=vis[u_];
			sz[v_]+=sz[u_];
			fa[u_]=v_;
			return 1;
		}else{
			if(vis[u_]){
				return 0;
			}else{
				vis[u_]=1;
				return 1;
			}
		}
	}
};
int main(){
	int n,m;
	rd(n),rd(m);
	dsu_cycle o(n);
	vector<tuple<int,int,int> >es;
	rep(i,0,m-1){
		int u,v,w;
		rd(u),rd(v),rd(w);
		--u,--v;
		es.eb(w,u,v);
	}
	sort(es.begin(),es.end());
	reverse(es.begin(),es.end());
	LL ans=0;
	each(x,es){
		int w,u,v;
		tie(w,u,v)=x;
		if(o.unite(u,v)){
			ans+=w;
		}
	}
	printf("%lld\n",ans);
	return 0;
}