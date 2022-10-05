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
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int MAXM=3e5;
const int LOG_N=17;
int n,m,s,_hd[MAXN+5],_to[MAXM*2+5],_nxt[MAXM*2+5],_val[MAXM*2+5],_ec=0;
void _adde(int u,int v,int w){_to[++_ec]=v;_val[_ec]=w;_nxt[_ec]=_hd[u];_hd[u]=_ec;}
ll dis[MAXN+5];
void dijkstra(){
	memset(dis,63,sizeof(dis));dis[s]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	q.push(mp(0,s));
	while(!q.empty()){
		pair<ll,int> p=q.top();q.pop();int x=p.se;
		for(int e=_hd[x];e;e=_nxt[e]){
			int y=_to[e],z=_val[e];
			if(dis[y]>dis[x]+z) dis[y]=dis[x]+z,q.push(mp(dis[y],y));
		}
	}
}
struct graph{
	int hd[MAXN+5],to[MAXM*2+5],nxt[MAXM*2+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
} g,rv_g,dt;
int deg[MAXN+5],fa[MAXN+5][LOG_N+2],dep[MAXN+5];
int getlca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=LOG_N;~i;i--) if(fa[x][i]^fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void calc(int x){
	int lc=0;
	for(int e=rv_g.hd[x];e;e=rv_g.nxt[e]){
		int y=rv_g.to[e];if(!lc) lc=y;else lc=getlca(y,lc);
	} fa[x][0]=lc;dep[x]=dep[lc]+1;
	if(lc) dt.adde(lc,x);
	for(int i=1;i<=LOG_N;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
}
int siz[MAXN+5];
void dfs(int x){
	siz[x]=1;
	for(int e=dt.hd[x];e;e=dt.nxt[e]){
		int y=dt.to[e];dfs(y);siz[x]+=siz[y];
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		_adde(u,v,w);_adde(v,u,w);
	} dijkstra();
	for(int x=1;x<=n;x++) for(int e=_hd[x];e;e=_nxt[e]){
		int y=_to[e],z=_val[e];
		if(dis[y]==dis[x]+z) g.adde(x,y),rv_g.adde(y,x),deg[y]++;
	} queue<int> q;
	for(int i=1;i<=n;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();calc(x);
		for(int e=g.hd[x];e;e=g.nxt[e]){
			int y=g.to[e];
			if(!--deg[y]) q.push(y);
		}
	} dfs(s);int res=0;
	for(int i=1;i<=n;i++) if(i^s) chkmax(res,siz[i]);
	printf("%d\n",res);
	return 0;
}