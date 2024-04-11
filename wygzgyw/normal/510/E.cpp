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
const int N=20010;
int n,a[N];
	struct edge{
		int v,nxt;
		int w;
	} c[5000000];
	int front[N],edge_cnt;
	int cur[N],dep[N],S,T;
	int _q[N],_l,_r;
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
		// inf changes when type != int
		return ans;
	}
bool vis[N]; int prime[N],tot;
vector<int> g[N];
vector<int> D;
vector<vector<int> > ans;
void dfs(int u) {
	D.push_back(u); vis[u]=1;
	for (int &v : g[u]) if (!vis[v]) dfs(v);
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=2;i<N;i++) {
		if (!vis[i]) prime[++tot]=i;
		for (int j=1;j<=tot;j++) {
			if (i*prime[j]>=N) break;
			vis[i*prime[j]]=1; if (i%prime[j]==0) break;
		}
	}
	S=n+1,T=n+2,node_cnt=T+1,init();
	int cnt=0,c2=0;
	for (int i=1;i<=n;i++) {
		if (a[i]&1) {
			for (int j=1;j<=n;j++) if (!vis[a[i]+a[j]]) addedge(i,j,1);
			addedge(S,i,2); cnt+=2;
		} else addedge(i,T,2),c2+=2;
	}
	if (cnt!=c2||dinic()!=cnt) { puts("Impossible"); return 0; }
	for (int i=1;i<=n;i++) if (a[i]&1) {
		for (int j=front[i];~j;j=c[j].nxt) if (c[j].v<=n&&!c[j].w) {
			g[i].push_back(c[j].v),g[c[j].v].push_back(i);
		}
	}
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) if (!vis[i]) D.clear(),dfs(i),ans.push_back(D);
	printf("%d\n",(int)ans.size());
	for (vector<int> &D : ans) {
		printf("%d ",(int)D.size()); for (int &x : D) printf("%d ",x); puts("");
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