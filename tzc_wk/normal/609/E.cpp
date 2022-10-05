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
const int LOG_N=17;
int n,m;ll sum=0,ans[MAXN+5];
struct edge{
	int u,v,w,id;
	bool operator <(const edge &rhs){
		return w<rhs.w;
	}
} e[MAXN+5];
struct ufset{
	int f[MAXN+5];
	int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
	void merge(int x,int y){x=find(x);y=find(y);if(x^y) f[x]=y;}
} f;
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],val[MAXN*2+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int fa[MAXN+5][LOG_N+2],mx[MAXN+5][LOG_N+2],dep[MAXN+5];
void dfs(int x,int f){
	fa[x][0]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==f) continue;
		mx[y][0]=z;dep[y]=dep[x]+1;dfs(y,x);
	}
}
int getmax(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);int res=0;
	for(int i=LOG_N;~i;i--) if(dep[u]-(1<<i)>=dep[v]) chkmax(res,mx[u][i]),u=fa[u][i];
	if(u==v) return res;
	for(int i=LOG_N;~i;i--) if(fa[u][i]^fa[v][i]){
		chkmax(res,mx[u][i]);chkmax(res,mx[v][i]);
		u=fa[u][i];v=fa[v][i];
	} return max(res,max(mx[u][0],mx[v][0]));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w),e[i].id=i;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		if(f.find(e[i].u)==f.find(e[i].v)) continue;
		adde(e[i].u,e[i].v,e[i].w);adde(e[i].v,e[i].u,e[i].w);
		sum+=e[i].w;f.merge(e[i].u,e[i].v);
	} dfs(1,0);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++){
		fa[j][i]=fa[fa[j][i-1]][i-1];
		mx[j][i]=max(mx[j][i-1],mx[fa[j][i-1]][i-1]);
	} for(int i=1;i<=m;i++) ans[e[i].id]=sum-getmax(e[i].u,e[i].v)+e[i].w;
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}