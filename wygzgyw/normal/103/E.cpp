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
const int maxn=310;
int n,cost[maxn];
vector<int> V[maxn];
bool vis[maxn];
int matL[maxn],matR[maxn];
int dfs(int x) {
	for (int &y : V[x]) if (!vis[y]) {
		vis[y]=1;
		if (!matR[y]||dfs(matR[y])) {
			matL[x]=y,matR[y]=x; return 1;
		}
	}
	return 0;
}
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
		// inf changes when type != int
		return ans;
	}
int ans;
int main() {
	read(n);
	for (int i=1;i<=n;i++) {
		int x,y;
		read(x); while (x--) read(y),V[i].push_back(y);
	}
	int cnt=0;
	for (int i=1;i<=n;i++) {
		memset(vis,0,sizeof(vis));
		cnt+=dfs(i);
	}
	assert(cnt==n);
	S=n+1,T=S+1,node_cnt=T+1,init();
	for (int i=1;i<=n;i++) read(cost[i]),cost[i]*=-1;
	for (int i=1;i<=n;i++) for (int &j : V[i]) addedge(i,matR[j],inf);
	for (int i=1;i<=n;i++) {
		if (cost[i]>0) addedge(S,i,cost[i]),ans+=cost[i];
		else addedge(i,T,-cost[i]);
	}
	ans-=dinic();
	printf("%d\n",-ans);
	
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