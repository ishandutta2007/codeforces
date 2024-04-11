#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=5010;

int n,head[maxn],nxt[maxn*2],to[maxn*2],dp[maxn][maxn];
int m,tot,sz[maxn],f[maxn],ans;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void add(int x,int y) {
	tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y;
}
void dfs(int u,int p) {
	dp[u][0]=1;
	sz[u]=1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v==p) continue;
		dfs(v,u);
		for (int j=0;j<=sz[u]+sz[v];j++) f[j]=0;
		for (int j=0;j<=sz[v]&&j<=m;j++) if (dp[v][j]) {
			for (int k=0;k<=sz[u]&&k<=m;k++) if (dp[u][k]) {
				if (j+k+1<=m) update(f[max(j+1,k)],(ll)dp[v][j]*dp[u][k]%mod);
				update(f[k],(ll)dp[v][j]*dp[u][k]%mod);
			}
		}
		for (int j=0;j<=sz[u]+sz[v];j++) dp[u][j]=f[j];
		sz[u]+=sz[v];
	}	
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m); int x,y;
	for (int i=1;i<n;i++) read(x),read(y),add(x,y),add(y,x);
	dfs(1,0);
	for (int i=0;i<=n;i++) update(ans,dp[1][i]);
	printf("%d\n",ans);
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