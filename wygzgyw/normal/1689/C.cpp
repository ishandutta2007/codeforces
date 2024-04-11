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
const int maxn=(3e5)+10;
int T,n,sz[maxn];
vector<int> g[maxn];
int dp[maxn];
void dfs(int u,int p) {
	int sum=0; sz[u]=1;
	for (int &v : g[u]) if (v!=p) {
		dfs(v,u);
		sum+=dp[v]; sz[u]+=sz[v];
	}
	dp[u]=0;
	for (int &v : g[u]) if (v!=p) dp[u]=max(dp[u],sz[v]-1+sum-dp[v]);
}
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) g[i].clear();
		int x,y;
		for (int i=1;i<n;i++) {
			read(x),read(y);
			g[x].push_back(y),g[y].push_back(x);
		}
		dfs(1,0);
		printf("%d\n",dp[1]);
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