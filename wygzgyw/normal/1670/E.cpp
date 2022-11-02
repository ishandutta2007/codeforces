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
int T,rt,deg[maxn];
int n,m;
vector<pair<int,int> > g[maxn];
int a[maxn],b[maxn],cnt;
void dfs(int u,int p,int dep) {
	for (auto [v,w] : g[u]) if (v!=p) {
		cnt++;
		a[w]=cnt;
		b[v]=cnt+n;
		if (dep&1) swap(a[w],b[v]);
		dfs(v,u,dep+1);
	}
}
int main() {
	read(T);
	while (T--) {
		read(m);
		n=1<<m;
		for (int i=1;i<=n;i++) deg[i]=0,g[i].clear();
		for (int i=1;i<n;i++) {
			int x,y; read(x),read(y);
			g[x].push_back(MP(y,i));
			g[y].push_back(MP(x,i));
			deg[x]++,deg[y]++;
		}
		for (int i=1;i<=n;i++) if (deg[i]==1) { rt=i; break; }
		cnt=1;
		a[g[rt][0].second]=1+n;
		b[rt]=1;
		b[g[rt][0].first]=n;
		dfs(g[rt][0].first,rt,0);
		printf("%d\n",rt);
		for (int i=1;i<=n;i++) printf("%d ",b[i]); puts("");
		for (int i=1;i<n;i++) printf("%d ",a[i]); puts("");
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