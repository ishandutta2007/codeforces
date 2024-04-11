// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=20010;
const int inf=1e9;
int n,k;
namespace MCMF {
	struct edge{
		int v,nxt;
		int w;
		int cost;
	} c[5000000];
	int front[maxn],edge_cnt;
	inline void addedge(int u,int v,int w,int cost) {
		c[++edge_cnt]=(edge){v,front[u],w,cost};
		front[u]=edge_cnt;
		
		c[++edge_cnt]=(edge){u,front[v],0,-cost};
		front[v]=edge_cnt;
	}
	int dep[maxn];
	int cur[maxn],S,T,node_cnt;
	bool inq[maxn];
	int _q[40000000],_l,_r;
	inline void init(){memset(front,255,sizeof(front)),edge_cnt=-1;}
	bool bfs() {
		for (int i=1;i<=node_cnt;i++) dep[i]=-inf;
		memcpy(cur,front,(node_cnt+2)<<2);
		memset(inq,0,node_cnt+2);
		_q[_l=_r=1]=S,dep[S]=0;
		while(_l!=_r+1) {
			int x=_q[_l++];
			inq[x]=false;
			for(int i=front[x];~i;i=c[i].nxt) {
				if(c[i].w&&dep[c[i].v]<dep[x]+c[i].cost) {
					dep[c[i].v]=dep[x]+c[i].cost;
					if(!inq[c[i].v]) inq[c[i].v]=true,_q[++_r]=c[i].v;
				}
			}
		}
		return dep[T]>-inf;
	}
	int dfs(int x,int flow) {
		if(x==T||!flow) return flow;
		inq[x]=true;
		int f=0,rf;
		for(int &i=cur[x];~i;i=c[i].nxt) {
			if(!inq[c[i].v]&&dep[c[i].v]==dep[x]+c[i].cost&&(rf=dfs(c[i].v,min(flow,c[i].w)))) {
				flow-=rf,f+=rf;
				c[i].w-=rf,c[i^1].w+=rf;
				if(!flow) return f;
			}
		}
		return f;
	}
	pair<int,int> dinic() {
		int ans=0;
		int res=0;
		while(bfs()) {
			int tmp=dfs(S,inf);
			// inf changes when type1 != int
			ans+=tmp;
			res+=dep[T]*tmp;
		}
		return MP(ans,res);
	}
}
int a[1<<20];
struct node {
	int x,y,z;
	friend bool operator < (node A,node B) { return A.z>B.z; }
} f[(1<<20)*20+10];
int tot,id[1<<20],cnt;
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
	for (int i=0;i<(1<<n);i++) read(a[i]);
	for (int i=0;i<(1<<n);i++) if (__builtin_popcount(i)&1^1) {
		for (int j=0;j<n;j++) f[++tot]=(node){i,i^(1<<j),a[i]+a[i^(1<<j)]};
	}
	int m=min(tot,(2*n-1)*(k-1)+1);
	nth_element(f+1,f+m,f+tot+1);
	for (int i=1;i<=m;i++) {
		int x=f[i].x,y=f[i].y;
		if (!id[x]) id[x]=++cnt;
		if (!id[y]) id[y]=++cnt;
	}
	MCMF::S=cnt+1,MCMF::T=MCMF::node_cnt=cnt+3;
	MCMF::init();
	for (int i=0;i<(1<<n);i++) if (id[i]) {
		if (__builtin_popcount(i)&1^1) MCMF::addedge(cnt+1,id[i],1,0);
		else MCMF::addedge(id[i],cnt+2,1,0);
	}
	MCMF::addedge(cnt+2,cnt+3,k,0);
	for (int i=1;i<=m;i++) {
		int x=f[i].x,y=f[i].y;
		x=id[x],y=id[y];
		MCMF::addedge(x,y,1,f[i].z);
		//printf("%d %d %d\n",x,y,f[i].z);
	}
	printf("%d\n",MCMF::dinic().second);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/