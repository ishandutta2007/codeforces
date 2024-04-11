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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e4;
const int MAXM=2e4;
const int MAXV=3e4;
const int MAXE=9e4;
const int INF=0x3f3f3f3f;
int n,m,k=0,cnt[MAXM+5];
int hd[MAXN+5],to[MAXM*2+5],nxt[MAXM*2+5],col[MAXM*2+5],ec=1;
void adde(int u,int v,int w){to[++ec]=v;col[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
struct edge{int u,v,w;} ed[MAXM+5];
int dfn[MAXN+5],tim=0,fa[MAXN+5],bel[MAXM+5];
int bot[MAXN+5],siz[MAXN+5];
tuple<int,int,int> et[MAXN+5];
void dfs(int x,int f,int pre){
	dfn[x]=++tim;fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=col[e];
		if(!dfn[y]) dfs(y,x,e),bot[y]=e>>1;
		else if(e^pre^1){
			if(dfn[y]<dfn[x]) et[++k]=mt(x,y,e>>1);
		}
	}
}
int S=3e4+1,T=3e4+2;
namespace maxflow{
	int hd[MAXV+5],to[MAXE+5],cap[MAXE+5],nxt[MAXE+5],ec=1;
	void adde(int u,int v,int f){
		to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
		to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
	} int dep[MAXV+5],now[MAXV+5];
	bool getdep(){
		memset(dep,-1,sizeof(dep));dep[S]=0;
		queue<int> q;q.push(S);now[S]=hd[S];
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int e=hd[x];e;e=nxt[e]){
				int y=to[e],z=cap[e];
				if(z&&!~dep[y]){
					dep[y]=dep[x]+1;
					now[y]=hd[y];q.push(y);
				}
			}
		} return ~dep[T];
	}
	int getflow(int x,int f){
		if(x==T) return f;int ret=0;
		for(int &e=now[x];e;e=nxt[e]){
			int y=to[e],z=cap[e];
			if(z&&dep[y]==dep[x]+1){
				int w=getflow(y,min(f-ret,z));
				ret+=w;cap[e]-=w;cap[e^1]+=w;
				if(f==ret) return ret;
			}
		} return ret;
	}
	int dinic(){
		int ret=0;
		while(getdep()) ret+=getflow(S,INF);
		return ret;
	}
}
int main(){
	scanf("%d%d",&n,&m);set<int> st;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);cnt[ed[i].w]++;
		adde(ed[i].u,ed[i].v,ed[i].w);adde(ed[i].v,ed[i].u,ed[i].w);
	} dfs(1,0,0);
	for(int i=1;i<=k;i++){
		int x=get<0>(et[i]),y=get<1>(et[i]),id=get<2>(et[i]);
		bel[id]=i;siz[i]=1;while(x^y) bel[bot[x]]=i,x=fa[x],siz[i]++;
	}
	for(int i=1;i<=m;i++){
		if(bel[i]) maxflow::adde(bel[i],ed[i].w+k,1);
		else maxflow::adde(S,ed[i].w+k,1);
	}
	for(int i=1;i<=k;i++) maxflow::adde(S,i,siz[i]-1);
	for(int i=1;i<=m;i++) if(cnt[i]) maxflow::adde(i+k,T,1);
	printf("%d\n",maxflow::dinic());
	return 0;
}
/*
5 8
1 2 1
1 2 2
2 3 3
2 3 4
3 4 5
3 4 6
4 5 6
4 5 7

7 9
2 1 1
2 3 1
2 4 2
2 5 2
2 6 3
2 7 3
1 3 1
4 5 2
6 7 3
*/