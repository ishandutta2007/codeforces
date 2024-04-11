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
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
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
const int MAXN=2e4;
const int MAXV=2e5;//remember to calculate
const int MAXE=3e6*2;
const int INF=0x3f3f3f3f;
int n,m;
namespace maxflow{
	int S=99999,T=1e5;
	int hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],cap[MAXE+5],ec=1;
	void adde(int u,int v,int f){
		to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
		to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
	}
	int dep[MAXV+5],now[MAXV+5];
	bool getdep(){
		memset(dep,-1,sizeof(dep));dep[S]=0;
		queue<int> q;q.push(S);now[S]=hd[S];
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int e=hd[x];e;e=nxt[e]){
				int y=to[e],z=cap[e];
				if(z&&!~dep[y]){
					dep[y]=dep[x]+1;
					q.push(y);now[y]=hd[y];
				}
			}
		} return ~dep[T];
	}
	int getflow(int x,int f){
		if(x==T) return f;int ret=0;
		for(int &e=now[x];e;e=nxt[e]){
			int y=to[e],z=cap[e];
			if(dep[y]==dep[x]+1&&z){
				int w=getflow(y,min(f-ret,z));
				ret+=w;cap[e]-=w;cap[e^1]+=w;
				if(ret==f) return ret;
			}
		} return ret;
	}
	int dinic(){
		int ret=0;
		while(getdep()) ret+=getflow(S,INF);
		return ret;
	}
	bool vis[MAXV+5];
	void dfs(int x){
		if(vis[x]) return;vis[x]=1;
		for(int e=hd[x];e;e=nxt[e]) if(cap[e]) dfs(to[e]);
	}
}
namespace segtree{
	int leaf[MAXN+5];
	void build(int k,int l,int r){
		if(l==r){leaf[l]=k;maxflow::adde(k+m,maxflow::T,1);return;}
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
		maxflow::adde(k+m,(k<<1)+m,INF);maxflow::adde(k+m,(k<<1|1)+m,INF);
	}
	void connect(int k,int l,int r,int ql,int qr,int id){
		if(ql<=l&&r<=qr){maxflow::adde(id,k+m,INF);return;}
		int mid=l+r>>1;
		if(qr<=mid) connect(k<<1,l,mid,ql,qr,id);
		else if(ql>mid) connect(k<<1|1,mid+1,r,ql,qr,id);
		else connect(k<<1,l,mid,ql,mid,id),connect(k<<1|1,mid+1,r,mid+1,qr,id);
	}
}
namespace tree{
	int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
	int fa[MAXN+5],siz[MAXN+5],dep[MAXN+5],wson[MAXN+5];
	int top[MAXN+5],dfn[MAXN+5],tim=0,id[MAXN+5],rev[MAXN+5];
	void dfs1(int x=1,int f=0){
		fa[x]=f;siz[x]=1;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			dep[y]=dep[x]+1;dfs1(y,x);
			id[y]=e;siz[x]+=siz[y];
			if(siz[y]>siz[wson[x]]) wson[x]=y;
		}
	}
	void dfs2(int x=1,int tp=1){
		top[x]=tp;dfn[x]=++tim;rev[tim]=x;if(wson[x]) dfs2(wson[x],tp);
		for(int e=hd[x];e;e=nxt[e]) if(to[e]!=fa[x]&&to[e]!=wson[x]) dfs2(to[e],to[e]);
	}
	void jumpath(int u,int v,int id){
		while(top[u]^top[v]){
			if(dep[top[u]]<dep[top[v]]) u^=v^=u^=v;
			segtree::connect(1,1,n,dfn[top[u]],dfn[u],id);
			u=fa[top[u]];
		} if(dep[u]<dep[v]) u^=v^=u^=v;
		if(u^v) segtree::connect(1,1,n,dfn[v]+1,dfn[u],id);
	}
}
int main(){
	scanf("%d%d",&n,&m);segtree::build(1,1,n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),tree::adde(u,v),tree::adde(v,u);
	tree::dfs1();tree::dfs2();
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		maxflow::adde(maxflow::S,i,1);
		tree::jumpath(u,v,i);
	} printf("%d\n",maxflow::dinic());
	maxflow::dfs(maxflow::S);int c1=0,c2=0;
//	for(int i=1;i<=n;i++) printf("%d\n",segtree::leaf[i]); 
	for(int i=1;i<=m;i++) if(!maxflow::vis[i]) c1++;printf("%d ",c1);
	for(int i=1;i<=m;i++) if(!maxflow::vis[i]) printf("%d ",i);printf("\n");
	for(int i=2;i<=n;i++) if(maxflow::vis[segtree::leaf[i]+m]) c2++;printf("%d ",c2);
	for(int i=2;i<=n;i++) if(maxflow::vis[segtree::leaf[i]+m])
		printf("%d ",tree::id[tree::rev[i]]+1>>1);
	return 0;
}