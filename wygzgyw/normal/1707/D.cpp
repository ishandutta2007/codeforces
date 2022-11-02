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
const int maxn=2010;
int n,mod,C[maxn][maxn];
vector<int> g[maxn];
int dp[maxn][maxn],ans[maxn],s[maxn][maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int pre[maxn][maxn],suf[maxn][maxn],sum[maxn];
void dfs(int u,int p) {
	sort(g[u].begin(),g[u].end());
	if (p) g[u].erase(lower_bound(g[u].begin(),g[u].end(),p));
	int sz=(int)g[u].size();
	if (sz==0) { for (int i=1;i<=n;i++) dp[u][i]=1; }
	else {
		for (int &v : g[u]) dfs(v,u);
		for (int j=1;j<=n;j++) {
			for (int i=0;i<sz;i++) pre[i][j]=(ll)(i==0?1:pre[i-1][j])*s[g[u][i]][j]%mod;
			for (int i=sz-1;i>=0;i--) suf[i][j]=(ll)(i==sz-1?1:suf[i+1][j])*s[g[u][i]][j]%mod;
		}
		for (int j=0;j<sz;j++) sum[j]=0;
		for (int i=1;i<=n;i++) {
			dp[u][i]=1; for (int &v : g[u]) dp[u][i]=(ll)dp[u][i]*s[v][i]%mod;
			if (u==1||i==1) continue;
			for (int j=0;j<sz;j++) {
				int v=g[u][j];
				update(sum[j],(ll)(j==0?1:pre[j-1][i-1])%mod*(j==sz-1?1:suf[j+1][i-1])%mod);
				update(dp[u][i],(ll)dp[v][i]*sum[j]%mod);
				//if (u==2) printf("?%d\n",dp[v][i]);
			}
		}
	}
	for (int i=1;i<=n;i++) s[u][i]=(s[u][i-1]+dp[u][i])%mod;
//	printf("u=%d\n",u);
//	for (int i=1;i<n;i++) printf("%d ",dp[u][i]); puts("");
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(mod);
	for (int i=0;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	int x,y;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) ans[i]=dp[1][i];
	for (int i=1;i<=n;i++) for (int j=1;j<i;j++) update(ans[i],mod-(ll)C[i][j]*ans[j]%mod);
	for (int i=1;i<n;i++) printf("%d ",ans[i]); puts("");
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