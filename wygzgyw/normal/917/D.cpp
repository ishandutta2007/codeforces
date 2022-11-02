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
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=110;
int n;
vector<int> g[maxn];
int dp[maxn][maxn][maxn];
int mi[maxn],ans[maxn];
int sz[maxn],tmp[maxn][maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void dfs(int u,int p) {
	sz[u]=1; dp[u][0][1]=1;
	for (int &v : g[u]) if (v!=p) {
		dfs(v,u);
		for (int i=0;i<=sz[u]+sz[v];i++) for (int j=0;j<=sz[u]+sz[v];j++) tmp[i][j]=0;
		for (int i=0;i<=sz[u];i++) for (int j=0;j<sz[v];j++)
		for (int k=0;k<=sz[u];k++) for (int l=1;l<=sz[v];l++) {
			update(tmp[i+j+1][k+l],(ll)dp[u][i][k]*dp[v][j][l]%mod);
			update(tmp[i+j][k],(ll)dp[u][i][k]*dp[v][j][l]%mod*l%mod);
		}
		for (int i=0;i<=sz[u]+sz[v];i++) for (int j=0;j<=sz[u]+sz[v];j++) dp[u][i][j]=tmp[i][j];
		sz[u]+=sz[v];
	}
	//for (int i=0;i<=sz[u];i++) for (int j=0;j<=sz[u];j++) if (dp[u][i][j]) printf("%d %d %d %d\n",u,i,j,dp[u][i][j]);
}
int ksm(int x,int y) {
	if (y<0) return ksm(ksm(x,-y),mod-2);
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int C[maxn][maxn];
int main() {
	read(n); int x,y;
	for (int i=1;i<n;i++) read(x),read(y),g[x].push_back(y),g[y].push_back(x);
	mi[0]=1; for (int i=1;i<=n;i++) mi[i]=(ll)mi[i-1]*n%mod;
	for (int i=0;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	dfs(1,0);
	for (int i=0;i<n;i++) {
		for (int j=1;j<=n;j++) update(ans[i],(ll)j*dp[1][i][j]%mod);
		ans[i]=(ll)ksm(n,n-i-2)*ans[i]%mod;
	}
	for (int i=0;i<n;i++) {
		int res=0;
		for (int j=i;j<n;j++) {
			int tmp=(ll)C[j][i]*ans[j]%mod;
			if ((j-i)&1^1) update(res,tmp); else update(res,mod-tmp);
		}
		printf("%d ",res);
	} puts("");
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