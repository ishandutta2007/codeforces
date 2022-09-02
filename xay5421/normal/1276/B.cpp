#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i) 
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005;
int T,n,m,x,y,ind,cnt,dfn[N],siz[N],low[N],st[N];vector<int>g[N];
int lnk[N],pp;
struct ed{int nxt,v;}G[N<<1];
void ae(int u,int v){G[++pp]=(ed){lnk[u],v},lnk[u]=pp;}
void tarjan(int u){
	dfn[u]=low[u]=++ind,st[++st[0]]=u;
	for(int i=lnk[u];i;i=G[i].nxt){
		int v=G[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				++cnt;
				for(int x=0;x!=v;--st[0]){
					x=st[st[0]];
					g[cnt].push_back(x);
					g[x].push_back(cnt);
				}
				g[cnt].push_back(u);
				g[u].push_back(cnt);
			}
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
void dfs(int k1,int k2){
	siz[k1]=(k1<=n);
	for(int j:g[k1])if(j!=k2){
		dfs(j,k1);
		siz[k1]+=siz[j];
	}
}
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(m),rd(x),rd(y);cnt=n;
		rep(i,1,m){
			int u,v;rd(u),rd(v);
			ae(u,v),ae(v,u);
		}
		tarjan(1);
		dfs(x,0);int sz1=siz[y]-1;
		dfs(y,0);int sz2=siz[x]-1;
		pt(1ll*sz1*sz2,'\n');
		for(int i=1;i<=cnt;++i)lnk[i]=0,dfn[i]=low[i]=0,g[i].clear();
		pp=0,cnt=0,ind=0;
	}
}