#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
int n,m,k;
ll x[60],y[60];
int from[60][60];
ll dp[60][60];
bool e[60][60],e2[60][60];
namespace Dinic {
	const int maxm=(1e5)+10;
	const int maxn=110;
	int cur[maxn];
	int level[maxn],tot,ans,flow[maxm];
	int head[maxn],nxt[maxm];
	int to[maxm],s,t;
	queue<int> q;
	void Add_edge(int a,int b,int c) {
		tot++; nxt[tot]=head[a];
		head[a]=tot; to[tot]=b; flow[tot]=c;
	}
	void add_edge(int a,int b,int c) {
		Add_edge(a,b,c);
		Add_edge(b,a,0);
	}
	bool bfs() {
		q=queue<int>();
		for (int i=1;i<=t;i++) cur[i]=head[i],level[i]=-1;
		q.push(s);
		level[s]=0;
		while (!q.empty()) {
			int a=q.front(),b; q.pop();
			for (register int i=head[a];i;i=nxt[i]) {
				b=to[i];
				if (flow[i]>0&&level[b]==-1) {
					level[b]=level[a]+1;
					q.push(b);
				}
			}
		}
		return level[t]!=-1;
	}
	int dfs(int x,int rest) {
		if (x==t) return rest;
		int used=0;
		for (register int i=cur[x];i;i=nxt[i]) {
			cur[x]=i;
			int y=to[i];
			if (flow[i]>0&&level[y]==level[x]+1) {
				int tflow=dfs(y,min(flow[i],rest-used));
				used+=tflow;
				flow[i]-=tflow;
				flow[i^1]+=tflow;
				if (rest-used==0) break;
			}
		}
		if (!used) level[x]=-1;
		return used;
	}
	int solve() {
		s=n*2+1,t=s+1;
		for (int i=1;i<=t;i++) head[i]=0; tot=1;
		for (int i=1;i<=n;i++) {
			add_edge(s,i,1),add_edge(i+n,t,1);
			for (int j=1;j<=n;j++) if (e[i][j]) add_edge(i,j+n,1);
		}
		ans=0;
		while (bfs()) ans+=dfs(s,0x7f7f7f7f);
		return ans;
	}
};
int d[60],tot,r[60];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m),read(k); int xx,yy;
	for (int i=1;i<=m;i++) {
		read(xx),read(yy),e[xx][yy]=1;
	}
	for (int i=1;i<=k;i++) read(x[i]),read(y[i]);
	int cur=Dinic::solve();
	while (cur) {
		memcpy(e2,e,sizeof(e));
		int fd=-1;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) e[i][j]=0;
			if (Dinic::solve()!=cur) { fd=i; break; }
			memcpy(e,e2,sizeof(e));
		}
		if (fd==-1) {
			for (int i=1;i<=n;i++) {
				for (int j=1;j<=n;j++) e[j][i]=0;
				if (Dinic::solve()!=cur) { fd=i+n; break; }
				memcpy(e,e2,sizeof(e));
			}
		}
		assert(fd!=-1);
		d[++tot]=fd; cur--;
	}
	if (n-tot>k) {
		printf("%d\n",k);
		for (int i=1;i<=k;i++) printf("0 "); puts(""); return 0;
	}
	for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) dp[i][j]=-INF;
	dp[0][0]=0;
	for (int i=1;i<=k;i++) {
		for (int j=0;j<=tot;j++) {
			if (n-tot+j<=i) continue;
			for (int l=0;l<=j;l++) {
				ll tmp=dp[i-1][l]+max(0LL,x[i]-(j-l)*y[i]);
				if (tmp>dp[i][j]) dp[i][j]=tmp,from[i][j]=l;
			}
		}
	}
	ll ans=-1; int pos;
	for (int i=1;i<=tot;i++) if (ans<dp[k][i]) ans=dp[k][i],pos=i;
	for (int i=k;i>=1;i--) {
		r[i]=pos;
		pos=from[i][pos];
	}
	vector<int> P;
	for (int i=1;i<=k;i++) {
		for (int j=r[i-1]+1;j<=r[i];j++) P.push_back(d[j]);
		P.push_back(0);
	}
	printf("%d\n",(int)P.size());
	for (int x : P ) {
		if (x>n) x=-(x-n);
		printf("%d ",x);
	}
	puts("");
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/