#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=3010;
int n,tot,head[maxn],nxt[maxn*2],to[maxn*2];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
int S,fa[maxn][maxn],sz[maxn][maxn];
void dfs(int u,int p) {
	sz[S][u]=1;
	fa[S][u]=p;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs(v,u);
		sz[S][u]+=sz[S][v];
	}
}
ll dp[maxn][maxn],ans;
ll DP(int u,int v) {
	if (u==v) return dp[u][v]=0;
	if (dp[u][v]!=-1) return dp[u][v];
	int p1=fa[v][u],p2=fa[u][v];
	dp[u][v]=sz[v][u]*sz[u][v]+max(DP(p1,v),DP(p2,u));
	return dp[u][v];
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n);
	int x,y;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		add(x,y);
		add(y,x);
	}
	for (int i=1;i<=n;i++) {
		S=i; dfs(i,0);
	}
	memset(dp,-1,sizeof(dp));
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
		ans=max(ans,DP(i,j));
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/