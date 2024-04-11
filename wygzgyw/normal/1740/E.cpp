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
const int maxn=(2e5)+10;
int n,p[maxn];
vector<int> g[maxn];
int dp[maxn],mxdep[maxn];
void dfs1(int u) {
	for (int &v : g[u]) dfs1(v),mxdep[u]=max(mxdep[u],mxdep[v]);
	mxdep[u]++;
}
void dfs(int u) {
	int sum=0;
	for (int &v : g[u]) dfs(v),sum+=dp[v];
	dp[u]=max(mxdep[u],sum);
}
int main() {
	read(n);
	for (int i=2;i<=n;i++) {
		read(p[i]); g[p[i]].push_back(i);
	}
	dfs1(1);
	dfs(1);
	printf("%d\n",dp[1]);
	return 0;
}