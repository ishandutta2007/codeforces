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
int n,q,m;
int fa[maxn],dep[maxn];
vector<int> g[maxn];
int find(int x) { if (fa[x]==x) return x; return fa[x]=find(fa[x]); }
void dfs(int u,int p) {
	fa[u]=p; dep[u]=dep[p]+1;
	for (int v : g[u]) if (v!=p) dfs(v,u);
}
int deg[maxn],d[maxn],tot; pair<int,int> E[maxn];
int main() {
	read(n),read(m);
	for (int i=1;i<=n;i++) fa[i]=i;
	int x,y;
	while (m--) {
		read(x),read(y);
		if (find(x)!=find(y)) fa[find(x)]=find(y),g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,0); read(q);
	for (int i=1;i<=q;i++) {
		read(x),read(y);
		E[i]=MP(x,y); deg[x]++,deg[y]++;
	}
	int cnt=0;
	for (int i=1;i<=n;i++) cnt+=(deg[i]%2==1);
	if (cnt) { printf("NO\n%d\n",cnt/2); return 0; }
	puts("YES");
	for (int i=1;i<=q;i++) {
		x=E[i].first,y=E[i].second;
		while (x!=y) {
			if (dep[x]>dep[y]) x=fa[x]; else y=fa[y];
		}
		int z=x;
		x=E[i].first,y=E[i].second;
		printf("%d\n",1+dep[x]+dep[y]-dep[z]*2);
		while (x!=z) printf("%d ",x),x=fa[x]; printf("%d ",z);
		tot=0;
		while (y!=z) d[++tot]=y,y=fa[y];
		for (int i=tot;i>=1;i--) printf("%d ",d[i]); puts("");
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