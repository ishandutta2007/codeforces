#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
const int MAXN=1e4;
const int LOG_N=16;
int n,m,bad=0,id[MAXN+5];pii e[MAXN+5]; 
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=1;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
struct ufset{
	int f[MAXN+5],col[MAXN+5];
	ufset(){memset(f,0,sizeof(f));}
	int find(int x){if(!f[x]) return x;int fx=f[x];find(f[x]);col[x]^=col[fx];return f[x]=find(f[x]);}
	int getcol(int x){find(x);return col[x];}
	void merge(int x,int y){
		int rv=getcol(x)^getcol(y)^1;
		x=find(x);y=find(y);if(x==y) return;
		if(rv) col[x]^=1;f[x]=y;
	}
	bool askequ(int x,int y){return (find(x)!=find(y))||(getcol(x)!=getcol(y));}
	bool askcon(int x,int y){return (find(x)==find(y));}
} f;
int fa[MAXN+5][LOG_N+2],vis[MAXN+5],dep[MAXN+5];
void dfs(int x,int f){
	fa[x][0]=f;vis[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);
	}
}
int getlca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=LOG_N;~i;i--) if(fa[x][i]^fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int mk1[MAXN+5],mk2[MAXN+5],is[MAXN+5];
void dfspush(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfspush(y,x);mk1[x]+=mk1[y];mk2[x]+=mk2[y];
		if(!mk2[y]&&mk1[y]==bad) is[e>>1]=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&e[i].fi,&e[i].se);
		if(!f.askcon(e[i].fi,e[i].se)) adde(e[i].fi,e[i].se),adde(e[i].se,e[i].fi),f.merge(e[i].fi,e[i].se),id[i]=ec>>1;
		else if(!f.askequ(e[i].fi,e[i].se)) bad++,id[i]=-1;
	}
	if(!bad){
		printf("%d\n",m);
		for(int i=1;i<=m;i++) printf("%d%c",i," \n"[i==m]);
		return 0;
	} vector<int> rts;
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0),rts.pb(i);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	for(int i=1;i<=m;i++) if(id[i]<=0){
		int lc=getlca(e[i].fi,e[i].se);
		if(id[i]==0) mk2[e[i].fi]++,mk2[e[i].se]++,mk2[lc]-=2;
		else mk1[e[i].fi]++,mk1[e[i].se]++,mk1[lc]-=2;
	} for(int x:rts) dfspush(x,0);
	vector<int> res;
	for(int i=1;i<=m;i++){
		if(!~id[i]&&bad==1) res.pb(i);
		if(id[i]&&is[id[i]]) res.pb(i);
	} printf("%d\n",res.size());
	for(int x:res) printf("%d ",x);printf("\n");
	return 0;
}//