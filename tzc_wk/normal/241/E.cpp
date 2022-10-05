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
const int MAXN=1000;
const int MAXM=5000;
int n,m,u[MAXM+5],v[MAXM+5];vector<int> g[MAXN+5],rev[MAXN+5];bool vis1[MAXN+5],vis2[MAXN+5];
int hd[MAXN+5],to[MAXM*2+5],val[MAXM*2+5],nxt[MAXM*2+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
void dfs(int x){if(vis1[x]) return;vis1[x]=1;for(int y:g[x]) dfs(y);}
void dfs_rev(int x){if(vis2[x]) return;vis2[x]=1;for(int y:rev[x]) dfs_rev(y);}
int dis[MAXN+5],cnt[MAXN+5];bool inq[MAXN+5];
void SPFA(int s){
	memset(dis,63,sizeof(dis));dis[s]=0;
	queue<int> q;q.push(s);inq[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();inq[x]=0;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=val[e];
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				if(!inq[y]){
					if(++cnt[y]>n) puts("No"),exit(0);
					q.push(y);inq[y]=1;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		g[u[i]].pb(v[i]);rev[v[i]].pb(u[i]);
	} dfs(1);dfs_rev(n);
	for(int i=1;i<=m;i++){
		if(!vis1[u[i]]||!vis1[v[i]]||!vis2[u[i]]||!vis2[v[i]]) continue;
		adde(u[i],v[i],2);adde(v[i],u[i],-1);
	} SPFA(1);puts("Yes");
	for(int i=1;i<=m;i++){
		if(!vis1[u[i]]||!vis1[v[i]]||!vis2[u[i]]||!vis2[v[i]]) puts("1");
		else printf("%d\n",dis[v[i]]-dis[u[i]]);
	}
	return 0;
}