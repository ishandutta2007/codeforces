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
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=100005,maxC=100005,maxL=((maxC-1)>>6)+110;
struct my_bitset{
	ULL a[maxL];
	void set(int i){a[i>>6]|=1ULL<<(i&63);}
};
using T=my_bitset;
void _or(const T&x,const T&y,T &z){
	rep(i,0,maxL-1){
		z.a[i]=x.a[i]|y.a[i];
	}
}
int n,Q,m,C,a[N],ans[N];
const int X=96;
struct my_ULL{
	ULL a[X];
	inline void operator|=(const my_ULL&rhs){rep(i,0,X-1)a[i]|=rhs.a[i];}
	inline int count()const{int ret=0;rep(i,0,X-1)ret+=__builtin_popcountll(a[i]);return ret;}
};
using TT=my_ULL;
namespace siever{
	const int N=20005;
	bool ban[N];
	int p[N],min_d[N];
	bool vis[N];
	int to[N];
	int id[N],idx;
	T mask[12170];
	void run(){
		ban[0]=ban[1];
		rep(i,2,N-1){
			if(!ban[i]){
				p[++*p]=i;
				to[i]=i;
				min_d[i]=*p;
			}
			for(int j=1;j<=*p&&i*p[j]<N;++j){
				ban[i*p[j]]=1;
				min_d[i*p[j]]=j;
				if(i%p[j]==0){
					to[i*p[j]]=to[i];
					break;
				}
				to[i*p[j]]=to[i]*p[j];
			}
		}
		rep(i,1,N-1){
			vis[to[i]]=1;
		}
		rep(i,1,N-1)if(vis[i])id[i]=++idx;
		rep(i,1,N-1)if(vis[i]){
			if(!ban[i]){
				for(int j=i;j<=C;j+=i){
					mask[id[i]].set(j);
				}
			}else{
				_or(mask[id[i/p[min_d[i]]]],mask[id[p[min_d[i]]]],mask[id[i]]);
			}
		}
	}
}
using siever::mask;
struct q_node{
	int l,r,id;
}qs[N];
namespace offline{
	
	int len;
	struct event{
		int type;
		int x,y;
	}all[1500000];
	struct dsu{
		int fa[N];
		dsu(){iota(fa,fa+N,0);}
		int find(int u){
			if(u!=fa[u]){
				int fa_u=fa[u];
				fa[u]=find(fa[u]);
				if(fa[fa_u]!=fa_u)all[++len]=(event){1,u,fa_u};
			}
			return fa[u];
		}
	}o;
	void init(){
		int j=1;
		rep(i,1,n){
			o.fa[i]=i+1;
			all[++len]=(event){0,i};
			while(j<=Q&&qs[j].r==i){
				o.find(qs[j].l);
				all[++len]=(event){2,qs[j].id,qs[j].l};
				++j;
			}
		}
		// memcpy(o.dis[i].a,mask[a[i]].a+x,sizeof(ULL)*X);
	}
}
using offline::all;
using offline::len;
TT dis[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m),rd(C),rd(Q);
	siever::run();
	rep(i,1,n)rd(a[i]),a[i]=siever::id[siever::to[a[i]]];
	rep(i,1,Q){
		rd(qs[i].l),rd(qs[i].r);
		qs[i].id=i;
	}
	sort(qs+1,qs+Q+1,[&](const q_node&lhs,const q_node&rhs){return lhs.r<rhs.r;});
	offline::init();
	int mx=C/64;
	for(int x=0;x<=mx;x+=X){
		memset(dis+1,0,sizeof(dis[0])*n);
		rep(_,1,len){
			switch(all[_].type){
				case 0:
					memcpy(dis[all[_].x].a,mask[a[all[_].x]].a+x,sizeof(ULL)*X);
					break;
				case 1:
					dis[all[_].x]|=dis[all[_].y];
					break;
				case 2:
					ans[all[_].x]+=dis[all[_].y].count();
					break;
			}
		}
	}
	rep(i,1,Q)pt(C-ans[i],'\n');
	return 0;
}