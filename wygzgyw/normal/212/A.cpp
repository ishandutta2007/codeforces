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
const int inf=1e9;
const int N=410;
int n,m,t,M;
pair<int,int> E[10000];
namespace MCMF {
	struct edge{
		int v,nxt;
		int w;
		int cost;
	} c[1000000];
	int front[N],edge_cnt;
	inline void addedge(int u,int v,int w,int cost) {
		c[++edge_cnt]=(edge){v,front[u],w,cost};
		front[u]=edge_cnt;
		
		c[++edge_cnt]=(edge){u,front[v],0,-cost};
		front[v]=edge_cnt;
	}
	int dep[N];
	int cur[N],S,T,node_cnt;
	bool inq[N];
	int _q[N*N],_l,_r;
	inline void init(int _i) { node_cnt=_i; memset(front,255,sizeof(front)),edge_cnt=1; }
	bool bfs() {
		memset(dep,63,(node_cnt+2)*sizeof(int));
		memcpy(cur,front,(node_cnt+2)<<2);
		memset(inq,0,node_cnt+2);
		_q[_l=_r=1]=S,dep[S]=0;
		while(_l!=_r+1) {
			int x=_q[_l++];
			inq[x]=0;
			for(int i=front[x];~i;i=c[i].nxt) {
				if(c[i].w&&dep[c[i].v]>dep[x]+c[i].cost) {
					dep[c[i].v]=dep[x]+c[i].cost;
					if(!inq[c[i].v]) inq[c[i].v]=1,_q[++_r]=c[i].v;
				}
			}
		}
		return dep[T]<inf;
	}
	int dfs(int x,int flow) {
		if(x==T||!flow) return flow;
		inq[x]=1;
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
	void dinic() {
		int ans=0;
		int res=0;
		while(bfs()) {
			int tmp=dfs(S,inf);
			// inf changes when type1 != int
			ans+=tmp;
			res+=dep[T]*tmp;
		}
	}
}
int k,d1[10000],d2[10000],ans[10000];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m),read(M),read(k);
	for (int i=1;i<=M;i++) read(E[i].first),read(E[i].second),d1[E[i].first]++,d2[E[i].second]++;
	int cnt=0; for (int i=1;i<=n;i++) if (d1[i]%k!=0) cnt++; for (int i=1;i<=m;i++) if (d2[i]%k!=0) cnt++;
	printf("%d\n",cnt);
	for (int I=k;I>=1;I--) {
		MCMF::init(n+m+3);
		MCMF::S=n+m+1,MCMF::T=n+m+2;
		for (int i=1;i<=M;i++) if (!ans[i]) {
			MCMF::addedge(E[i].first,E[i].second+n,1,0);
		}
		for (int i=1;i<=n;i++) {
			MCMF::addedge(MCMF::S,i,d1[i]/I,0);
			if (d1[i]%I!=0) MCMF::addedge(MCMF::S,i,1,1);
		}
		for (int i=1;i<=m;i++) {
			MCMF::addedge(i+n,MCMF::T,d2[i]/I,0);
			if (d2[i]%I!=0) MCMF::addedge(i+n,MCMF::T,1,1);
		}
		MCMF::dinic();
		for (int i=1,id=0;i<=M;i++) if (!ans[i]) {
			id+=2;
			if (!MCMF::c[id].w) {
				ans[i]=I;
				d1[E[i].first]--,d2[E[i].second]--;
			}
		}
	}
	for (int i=1;i<=M;i++) printf("%d ",ans[i]); puts("");
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