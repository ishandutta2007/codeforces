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
int n,m,cost[100];
int d[100][100],s1[100],s2[100],bit[1<<10];
int now[100],deg[1000];

	const int N=1000;
	struct edge{
		int v,nxt,w;
	} c[100000];
	int front[N],edge_cnt;
	int cur[N],dep[N],S,T;
	int _q[N],_l,_r;
	int node_cnt;
	inline void addedge(int u,int v,int w) {
		if (!w) return;
		//printf("add %d %d %d\n",u,v,w);
		c[++edge_cnt]=(edge){v,front[u],w},front[u]=edge_cnt; deg[u]+=w;
		c[++edge_cnt]=(edge){u,front[v],0},front[v]=edge_cnt; deg[v]+=w;
	}
	inline void init(int _i,int _s,int _t) { node_cnt=_i,S=_s,T=_t; memset(front,255,sizeof(front)),edge_cnt=1; }
	bool bfs() {
		memset(dep,255,(node_cnt+3)<<2);
		memcpy(cur,front,(node_cnt+3)<<2);
		dep[S]=0,_q[_l=_r=1]=S;
		while(_l!=_r+1) {
			int x=_q[_l++];
			for(int i=front[x];~i;i=c[i].nxt) {
				if(c[i].w>0&&!~dep[c[i].v]) {
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
	int solve() {
		int ans=0;
		while(bfs()) ans+=dfs(S,inf);
		return ans;
	}
	void clear() {
		for (int i=3;i<=edge_cnt;i+=2) c[i].w=0;
		for (int i=front[S];~i;i=c[i].nxt) c[i].w=1;
		for (int i=front[T];~i;i=c[i].nxt) c[i^1].w=1;
	}
struct node { int x,y,l,r; }; vector<node> res;
int main() {
	//freopen("1.txt","r",stdin);
	int T; read(n),read(m),read(T);
	for (int i=1;i<=m;i++) read(cost[i]);
	for (int i=1;i<=n;i++) {
		int num,x; read(num); for (int j=1;j<=num;j++) read(x),read(d[i][x]);
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) s1[i]+=d[i][j],s2[j]+=d[i][j];
	int ans=1e9,msk;
	for (int t=0;t<(1<<m);t++) {
		for (int i=1;i<=m;i++) if (t&(1<<(i-1))) bit[t]+=cost[i];
		if (bit[t]>T) continue;
		int res=0;
		for (int i=1;i<=n;i++) res=max(res,s1[i]);
		for (int i=1;i<=m;i++) if (t&(1<<(i-1))) res=max(res,(s2[i]+1)/2); else res=max(res,s2[i]);
		if (res<ans) ans=res,msk=t;
	}
	printf("%d\n",ans);
	for (int i=1;i<=m;i++) if (msk&(1<<(i-1))) putchar('1'); else putchar('0'); puts("");
	int s=n*2+m*4+1,t=s+1;
	init(t+1,s,t);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (msk&(1<<(j-1))) {
		int x=now[j]; now[j]+=d[i][j]; int y=now[j];
		if (y<=s2[j]/2) addedge(i,n+j,d[i][j]);
		else if (x>=s2[j]/2) addedge(i,n+m+j,d[i][j]);
		else addedge(i,n+j,s2[j]/2-x),addedge(i,n+m+j,y-s2[j]/2);
	} else addedge(i,n+j,d[i][j]);
	for (int i=1;i<=n;i++) addedge(i,n+m*2+i,ans-deg[i]);
	for (int i=n+1;i<=n+m*2;i++) addedge(i+n+m*2,i,ans-deg[i]);
	for (int i=n+m*2+1;i<=n*2+m*2;i++) for (int j=n*2+m*2+1;j<=n*2+m*4;j++)
		addedge(j,i,ans-max(deg[i],deg[j]));
	for (int i=1;i<=n;i++) addedge(s,i,1),addedge(n+m*2+i,t,1);
	for (int i=1;i<=m*2;i++) addedge(n+i,t,1),addedge(s,n*2+m*2+i,1);
	int tim=0;
//	printf("s=%d,t=%d\n",s,t);
	while (1) {
		int mn=1e9;
		clear();
		solve();
		vector<int> E;
		for (int i=3;i<=edge_cnt;i+=2) if (c[i].w&&c[i^1].v!=::T&&c[i].v!=S) {
			E.push_back(i); mn=min(mn,c[i^1].w);
		}
		//printf("mn=%d\n",mn);
		if (E.empty()) break;
		for (int &i : E) {
			c[i^1].w-=mn;
			int x=c[i].v,y=c[i^1].v;
		//	printf("(%d,%d) %d\n",x,y,i-2);
			if (x<=n&&y<=n+m) res.push_back((node){x,y-n,tim,mn+1});
			else if (x<=n&&y<=n+m*2) res.push_back((node){x,y-n-m,tim,mn+1});
		}
		tim+=mn+1;
	}
	printf("%d\n",(int)res.size());
	for (node &A : res) printf("%d %d %d %d\n",A.x,A.y,A.l,A.r);
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