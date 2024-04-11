#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T> void read(T &x){
	x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
}
const int MAXN=4e5;
int n,m,hd[MAXN+5],nxt[MAXN+5],to[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
map<int,int> mmp;int f[MAXN+5],siz[MAXN+5];
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
struct edge{
	int u,v,w;
	edge(int _u=0,int _v=0,int _w=0):u(_u),v(_v),w(_w){}
	bool operator <(const edge &rhs){return w<rhs.w;}
} e[MAXN+5];
vector<pii> g[MAXN+5];
bool have[1005][1005],vis[MAXN+5];
int is[MAXN+5][18],dep[MAXN+5],fa[MAXN+5][18];
void dfs(int x,int f){
//	printf("%d %d\n",x,f);
	fa[x][0]=f;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i].fi,z=g[x][i].se;if(y==f) continue;
		is[y][0]=(!z);dep[y]=dep[x]+1;dfs(y,x);
	}
}
bool isable(int x,int y){
	if(dep[x]<dep[y]) x^=y^=x^=y;bool ans=0;
	for(int i=17;~i;i--) if(dep[x]-(1<<i)>=dep[y]) ans|=is[x][i],x=fa[x][i];
	if(x==y) return ans;
	for(int i=17;~i;i--) if(fa[x][i]!=fa[y][i]){
		ans|=is[x][i];ans|=is[y][i];x=fa[x][i];y=fa[y][i];
	} ans|=is[x][0];ans|=is[y][0];return ans;
}
int main(){
	scanf("%d%d",&n,&m);int sum=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		adde(e[i].u,e[i].v);adde(e[i].v,e[i].u);sum^=e[i].w;
	} vector<int> vv;
	for(int i=1;i<=n;i++) siz[i]=1;
	for(int i=1;i<=n;i++){
		mmp.clear();
		for(int e=hd[i];e;e=nxt[e]) mmp[find(to[e])]++;
		for(int v:vv){
			int x=find(i),y=find(v);if(x==y) continue;
			if(siz[y]^mmp[y]) f[x]=y,siz[y]+=siz[x];
		} if(find(i)==i) vv.pb(i);
	} int ccn=0;
	for(int i=1;i<=n;i++) if(find(i)==i) ccn++;
	ll rst=1ll*n*(n-1)/2-m;//printf("%d\n",ccn);
	bool flg=(rst==(n-ccn));
	if(!flg){
		sort(e+1,e+m+1);ll ans=0;
		for(int i=1;i<=m;i++){
			int x=find(e[i].u),y=find(e[i].v);
			if(x^y){f[x]=y;ans+=e[i].w;}
		} printf("%lld\n",ans);
	} else {
		sort(e+1,e+m+1);ll ans=0;
		for(int i=1;i<=m;i++) have[e[i].u][e[i].v]=have[e[i].v][e[i].u]=1;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
			if(!have[i][j]) g[i].pb(mp(j,0)),g[j].pb(mp(i,0));
		for(int i=1;i<=m;i++){
			int x=find(e[i].u),y=find(e[i].v);
			if(x^y){
				vis[i]=1;f[x]=y;ans+=e[i].w;
				g[e[i].u].pb(mp(e[i].v,1));
				g[e[i].v].pb(mp(e[i].u,1));
			}
		} dfs(1,0);
		for(int i=1;i<=17;i++) for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
			is[j][i]=is[j][i-1]|is[fa[j][i-1]][i-1];
		} //printf("%lld\n",ans);
		for(int i=1;i<=m;i++) if(!vis[i]&&e[i].w<sum){
			if(isable(e[i].u,e[i].v)){
				printf("%lld\n",ans+e[i].w);
				return 0;
			}
		} printf("%lld\n",ans+sum);
	}
	return 0;
}