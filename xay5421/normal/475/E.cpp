#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.h"
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
const int N=2005;
int n,m,dfn[N],low[N],ind,st[N],top,bel[N],cnt,sz[N],base,ans;
vector<int>e[N],ee[N];
void tarjan(int u,int fa){
	dfn[u]=low[u]=++ind,st[++top]=u;
	for(auto&x:e[u])if(x!=fa){
		if(!dfn[x]){
			tarjan(x,u);
			low[u]=min(low[u],low[x]);
		}else{
			low[u]=min(low[u],dfn[x]);
		}
	}
	if(low[u]==dfn[u]){
		++cnt;
		do{
			++sz[cnt];
			bel[st[top]]=cnt;
		}while(st[top--]!=u);
		base+=sz[cnt]*sz[cnt];
	}
}
int sum,ss[N];
void dfs(int u,int fa,int dep){
	ss[u]=sz[u];
	for(auto&x:ee[u])if(x!=fa){
		dfs(x,u,dep+1);
		ss[u]+=ss[x];
	}
	sum+=sz[u]*(ss[u]-sz[u]);
}
int main() {
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v),e[v].push_back(u);
	}
	tarjan(1,0);
	rep(u,1,n)for(auto&x:e[u])if(bel[u]!=bel[x])ee[bel[u]].push_back(bel[x]);
	rep(root,1,cnt){
		sum=0;
		dfs(root,0,0);
		bitset<2005>bag;
		bag.set(0);
		for(auto&x:ee[root])bag|=bag<<ss[x];
		int mx=0;
		rep(j,1,n-sz[root]-1)if(bag[j]){
			mx=max(mx,j*(n-sz[root]-j));
		}
		ans=max(ans,mx+sum+base);
	}
	printf("%d\n",ans);
	return 0;
}