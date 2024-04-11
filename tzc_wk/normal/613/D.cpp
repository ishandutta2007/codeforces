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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int LOG_N=18;
int n,qu,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dfn[MAXN+5],seq[MAXN*2+5],tim=0,dep[MAXN+5],_log[MAXN*2+5];
pii st[MAXN*2+5][LOG_N+2];int fa[MAXN+5];
void dfs(int x,int f){
	seq[++tim]=x;dfn[x]=tim;fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);seq[++tim]=x;
	}
}
pii querymn(int l,int r){
	int k=_log[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int getlca(int x,int y){
	if(dfn[x]>dfn[y]) x^=y^=x^=y;
	return querymn(dfn[x],dfn[y]).se;
}
bool vis[MAXN+5];
int pt[MAXN+5],pcnt;vector<int> g[MAXN+5];
bool cmp(int x,int y){return dfn[x]<dfn[y];}
int stk[MAXN+5],tp=0;
void insert(int x){
//	eprintf("insert %d\n",x);
	if(!tp) return stk[++tp]=x,void();
	int lc=getlca(x,stk[tp]);//eprintf("%d\n",lc);
	while(tp>=2&&dep[lc]<dep[stk[tp-1]]) g[stk[tp-1]].pb(stk[tp]),tp--;
	if(tp&&dep[lc]<dep[stk[tp]]) g[lc].pb(stk[tp--]);
	if(!tp||stk[tp]!=lc) stk[++tp]=lc;stk[++tp]=x;
}
void fin(){
	while(tp>=2) g[stk[tp-1]].pb(stk[tp]),tp--;
	tp=0;
}
int dp[MAXN+5],f[MAXN+5];
void dfs(int x){
//	eprintf("%d\n",x);
	dp[x]=f[x]=0;int cnt=0;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];dfs(y);
		if(f[y]) cnt++;dp[x]+=dp[y];
	}
	if(vis[x]) dp[x]+=cnt,f[x]=1;
	else if(cnt>=2) dp[x]++,f[x]=0;
	else if(cnt==1) f[x]=1;
}
void clear(int x){
	dp[x]=f[x]=0;
	for(int i=0;i<g[x].size();i++) clear(g[x][i]);
	while(!g[x].empty()) g[x].ppb();
}
void solve(){
	scanf("%d",&pcnt);
	for(int i=1;i<=pcnt;i++) scanf("%d",&pt[i]),vis[pt[i]]=1;
//	debug(19260817);
	for(int i=1;i<=pcnt;i++) if(vis[fa[pt[i]]]){
		puts("-1");
		for(int j=1;j<=pcnt;j++) vis[pt[j]]=0;
		return;
	} sort(pt+1,pt+pcnt+1,cmp);
	if(!vis[1]) insert(1);for(int i=1;i<=pcnt;i++) insert(pt[i]);
	fin();dfs(1);printf("%d\n",dp[1]);clear(1);
	for(int i=1;i<=pcnt;i++) vis[pt[i]]=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(1,0);for(int i=1;i<=n<<1;i++) st[i][0]=mp(dep[seq[i]],seq[i]);
//	for(int i=1;i<=n<<1;i++) eprintf("%d%c",seq[i],(i==n<<1)?'\n':' ');
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n<<1;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
	for(int i=2;i<=MAXN*2;i++) _log[i]=_log[i-1]+((1<<(_log[i-1]+1))==i);
	scanf("%d",&qu);while(qu--) solve();
	return 0;
}