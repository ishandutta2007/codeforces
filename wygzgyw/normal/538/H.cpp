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
const int maxn=(1e5)+10;
int t,T,n,m,l[maxn],r[maxn],col[maxn];
void No() { puts("IMPOSSIBLE"); exit(0); }
bool vis[maxn]; vector<int> g[maxn];
void dfs(int u) {
	if (vis[u]) return;
	vis[u]=1;
	for (int &v : g[u]) {
		if (col[v]) {
			if (col[v]==col[u]) No();
		} else col[v]=3-col[u],dfs(v);
	}
}
int main() {
	read(t),read(T);
	read(n),read(m);
	int mxL=0,mnR=1e9;
	for (int i=1;i<=n;i++) read(l[i]),read(r[i]),mnR=min(mnR,r[i]),mxL=max(mxL,l[i]);
	int a=mnR,b=mxL;
	if (a+b<t) b=t-a;
	if (a+b>T) a=T-b;
	if (a<0||b<0) No();
	for (int i=1;i<=n;i++) {
		int t1=(l[i]<=a&&a<=r[i]),t2=(l[i]<=b&&b<=r[i]);
		if (!t1&&!t2) No();
		if (!t1) col[i]=2; if (!t2) col[i]=1;
	}
	int x,y;
	while (m--) read(x),read(y),g[x].push_back(y),g[y].push_back(x);
	for (int i=1;i<=n;i++) if (col[i]) dfs(i);
	for (int i=1;i<=n;i++) if (!col[i]) col[i]=1,dfs(i);
	puts("POSSIBLE");
	printf("%d %d\n",a,b);
	for (int i=1;i<=n;i++) printf("%d",col[i]); puts("");
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