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
	vector<int>what;
	dsu(){}
	dsu(int n_):n(n_),fa(n_),sz(n_,1),what(n_,0){
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
const int N=200005;
int T,n,a[N],p[N],q[N];
vector<int>vec[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	rep(tc,1,T){
		rd(n);
		fill(p+1,p+n+1,0);
		fill(q+1,q+n+1,0);
		rep(i,1,n)vec[i].clear();
		rep(i,1,n)rd(a[i]),vec[a[i]].pb(i);
		int tt=0;
		rep(i,1,n)tt+=SZ(vec[i])&1;
		if(tt>1){
			puts("NO");
			continue;
		}
		dsu o(n+1);
		int l,r;
		if(n&1){
			l=(n+1)>>1;
			r=(n+1)>>1;
		}else{
			l=n>>1;
			r=(n>>1)+1;
		}
		auto link=[&](int u,int v){
			p[u]=v,q[v]=u;
			o.unite(u,v);
		};
		if(n&1){
			vector<int>&v=vec[a[(n+1)>>1]];
			if(SZ(v)==1){
				puts("NO");
				continue;
			}
			rep(i,1,n)if(SZ(vec[i])&1){
				if(vec[i].back()==l)swap(vec[i].back(),vec[i][SZ(vec[i])-2]);
				link(vec[i].back(),l),vec[i].pop_back();
				--l,++r;
				while(!vec[i].empty()){
					link(vec[i].back(),l--),vec[i].pop_back();
					link(vec[i].back(),r++),vec[i].pop_back();
				}
			}
		}
		rep(i,1,n){
			while(!vec[i].empty()){
				link(vec[i].back(),l--),vec[i].pop_back();
				link(vec[i].back(),r++),vec[i].pop_back();
			}
		}
		rep(i,1,n)vec[a[i]].pb(i);
		rep(i,1,n){
			int u=i,v=n+1-i;
			if(o.find(u)!=o.find(v)){
				int qu=q[u];
				int pu=p[u];
				int qv=q[v];
				int pv=p[v];
				p[qv]=u,q[u]=qv;
				p[qu]=v,q[v]=qu;
				o.unite(u,v);
			}
		}
		rep(i,1,n){
			if((n&1)&&i==((n+1)>>1))continue;
			o.what[o.find(i)]=i;
		}
		int last=-1;
		rep(i,1,n)if(o.find(i)==i){
			if(last==-1){
				last=i;
			}else{
				
				int u=o.what[last],u_=n+1-u;
				int v=o.what[i],v_=n+1-v;
				int qu=q[u],pu=p[u];
				int qv=q[v],pv=p[v];
				int qu_=q[u_],pu_=p[u_];
				int qv_=q[v_],pv_=p[v_];
				link(qu_,v);
				link(qv_,u_);
				link(qu,v_);
				link(qv,u);
				
				o.unite(last,i);
				last=o.find(i);
			}
		}
		// rep(i,1,n)assert(p[q[i]]==i);
		puts("YES");
		rep(i,1,n)printf("%d%c",q[i],i==n?'\n':' ');
		D("! ");
		rep(i,1,n)D("%d%c",a[q[i]],i==n?'\n':' ');
	}
	return 0;
}