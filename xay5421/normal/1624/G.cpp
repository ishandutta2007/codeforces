#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
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
	dsu_cycle(int n):dsu(n),vis(n){}
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
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		vector<tuple<int,int,int> >es;
		rep(i,0,m-1){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			--u,--v;
			es.eb(u,v,w);
		}
		int mask=0X7FFFFFFF;
		auto check=[&](){
			dsu o(n);
			rep(i,0,m-1)if((get<2>(es[i])|mask)==mask){
				o.unite(get<0>(es[i]),get<1>(es[i]));
			}
			rep(i,0,n-1)if(!o.check(0,i))return 0;
			return 1;
		};
		per(i,30,0){
			mask^=1<<i;
			if(!check())mask^=1<<i;
		}
		printf("%d\n",mask);
	}
	return 0;
}