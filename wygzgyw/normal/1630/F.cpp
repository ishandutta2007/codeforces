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
const int maxn=(4e5)+10;
int TT,n,a[maxn],bk[maxn];
	struct edge{
		int v,nxt;
		int w;
	} c[5000000];
	int front[maxn],edge_cnt;
	int cur[maxn],dep[maxn],S,T;
	int _q[maxn*2],_l,_r;
	int node_cnt;
	inline void addedge(int u,int v,int w) {
		c[++edge_cnt]=(edge){v,front[u],w},front[u]=edge_cnt;
		c[++edge_cnt]=(edge){u,front[v],0},front[v]=edge_cnt;
	}
	inline void init(){memset(front,255,sizeof(front)),edge_cnt=-1;}
	bool bfs() {
		memset(dep,255,(node_cnt+3)<<2);
		memcpy(cur,front,(node_cnt+3)<<2);
		dep[S]=0,_q[_l=_r=1]=S;
		while(_l!=_r+1) {
			int x=_q[_l++];
			for(int i=front[x];~i;i=c[i].nxt) {
				if(c[i].w&&!~dep[c[i].v]) {
					dep[c[i].v]=dep[x]+1;
					_q[++_r]=c[i].v;
				}
			}
		}
		return ~dep[T];
	}
	int dfs(int x,int flow) {
		if(x==T||!flow) return flow;
		int f=0,rf;
		for(int &i=cur[x];~i;i=c[i].nxt) {
			if(dep[c[i].v]==dep[x]+1&&(rf=dfs(c[i].v,min(flow,c[i].w)))) {
				flow-=rf,f+=rf;
				c[i].w-=rf,c[i^1].w+=rf;
				if(!flow) return f;
			}
		}
		return f;
	}
	int dinic() {
		int ans=0;
		while(bfs()) ans+=dfs(S,inf);
		return ans;
	}
	vector<int> D[maxn],g[maxn];
	void ADD(int x,int y) {
		g[x].push_back(y);
		g[x+n].push_back(y+n);
	}
int main() {
	for (int i=1;i<=50000;i++) for (int j=i;j<=50000;j+=i) D[j].push_back(i);
	read(TT);
	while (TT--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]),bk[a[i]]=i;
		for (int i=1;i<=n*2;i++) g[i].clear();
		node_cnt=n*4+5; init();
		for (int i=1;i<=n;i++) {
			for (int &j : D[a[i]]) if (bk[j]&&bk[j]!=i) ADD(bk[j],i);
			g[i].push_back(i+n);
		}
		S=n*4+1,T=n*4+2;
		for (int i=1;i<=n*2;i++) {
			addedge(S,i,1);
			addedge(i+n*2,T,1);
			for (int &j : g[i]) addedge(i,j+n*2,1);//,printf("%d %d\n",i,j);
		}
		int ans=dinic();
		printf("%d\n",ans-n);
		for (int i=1;i<=n;i++) bk[a[i]]=0;
	}
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