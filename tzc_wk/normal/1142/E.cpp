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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,m,hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dfn[MAXN+5],low[MAXN+5],stk[MAXN+5],tp=0,vis[MAXN+5],tim=0;
int cmp=0,bel[MAXN+5],deg[MAXN+5];
vector<int> g[MAXN+5],pts[MAXN+5];
void tarjan(int x){
	dfn[x]=low[x]=++tim;stk[++tp]=x;vis[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(!dfn[y]) tarjan(y),chkmin(low[x],low[y]);
		else if(vis[y]) chkmin(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]){
		cmp++;int o;
		do {o=stk[tp--];bel[o]=cmp;vis[o]=0;} while(o^x);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),adde(u,v);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) for(int e=hd[i];e;e=nxt[e]){
		int j=to[e];
		if(bel[i]^bel[j]){
			deg[bel[j]]++;g[bel[i]].pb(bel[j]);
		}
	} queue<int> q;
	for(int i=1;i<=n;i++) pts[bel[i]].pb(i);
	for(int i=1;i<=cmp;i++) if(!deg[i]) q.push(pts[i].back());
	while(q.size()>1){
		int x=q.front();q.pop();
		int y=q.front();q.pop();
		printf("? %d %d\n",x,y);fflush(stdout);
		int d;scanf("%d",&d);if(!d) x^=y^=x^=y;
		q.push(x);pts[bel[y]].pop_back();
		if(!pts[bel[y]].size()){
			for(int v:g[bel[y]]){
				if(!--deg[v]) q.push(pts[v].back());
			}
		} else q.push(pts[bel[y]].back());
	} printf("! %d\n",q.front());fflush(stdout);
	return 0;
}