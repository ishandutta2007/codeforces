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
const int N=100005,M=200005,K=20;
int T,n,m,Q,ans[M],val[N<<1],fa[N<<1][K],lca[N][K],dep[N<<1],lg[N];
struct dsu{
	int fa[N<<1];
	int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
}o;
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int dt=dep[u]-dep[v];
	per(i,K-1,0)if(dt>>i&1)u=fa[u][i];
	if(u==v)return u;
	per(i,K-1,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,2,N-1)lg[i]=lg[i>>1]+1;
	rd(T);
	while(T--){
		rd(n),rd(m),rd(Q);
		rep(i,1,n)o.fa[i]=i,val[i]=0;
		int cnt=n;
		rep(i,1,m){
			int u,v;
			rd(u),rd(v);
			int fu=o.find(u);
			int fv=o.find(v);
			if(fu!=fv){
				++cnt;
				o.fa[cnt]=cnt;
				o.fa[fu]=cnt;
				o.fa[fv]=cnt;
				fa[fu][0]=cnt;
				fa[fv][0]=cnt;
				val[cnt]=i;
			}
		}
		per(i,cnt,1){
			dep[i]=dep[fa[i][0]]+1;
		}
		rep(j,1,K-1){
			rep(i,1,cnt)fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		rep(i,1,n)lca[i][0]=i;
		rep(j,1,K-1){
			rep(i,1,n-(1<<j)+1){
				lca[i][j]=LCA(lca[i][j-1],lca[i+(1<<(j-1))][j-1]);
			}
		}
		rep(i,1,Q){
			int l,r;
			rd(l),rd(r);
			int x=lg[r-l+1];
			printf("%d ",val[LCA(lca[l][x],lca[r-(1<<x)+1][x])]);
		}
		puts("");
	}
	return 0;
}