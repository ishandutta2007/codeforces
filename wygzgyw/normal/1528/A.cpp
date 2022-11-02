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
typedef long long ll;
const int maxn=(1e5)+10;
int T,n;
vector<int> g[maxn];
ll l[maxn],r[maxn],dp[maxn][2];
void dfs(int u,int p) {
	dp[u][0]=dp[u][1]=0;
	for (int v : g[u]) if (v!=p) {
		dfs(v,u);
		dp[u][0]+=max(dp[v][0]+abs(l[u]-l[v]),dp[v][1]+abs(l[u]-r[v]));
		dp[u][1]+=max(dp[v][0]+abs(r[u]-l[v]),dp[v][1]+abs(r[u]-r[v]));
	}
}
int main() {
//	freopen("1.txt","r",stdin);
	read(T); while (T--) {
		read(n); for (int i=1;i<=n;i++) g[i].clear(); int x,y;
		for (int i=1;i<=n;i++) read(l[i]),read(r[i]);
		for (int i=1;i<n;i++) {
			read(x),read(y); g[x].push_back(y); g[y].push_back(x);
		}
		dfs(1,0);
		
		printf("%lld\n",max(dp[1][0],dp[1][1]));
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