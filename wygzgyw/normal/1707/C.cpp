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
int n,m;
int f[maxn];
int find(int x) { if (f[x]==x) return x; return f[x]=find(f[x]); }
vector<pair<int,int> > E;
vector<int> g[maxn];
int bg[maxn],ed[maxn],tot;
int fa[maxn][20],dep[maxn];
void dfs(int u,int p) {
	bg[u]=++tot; fa[u][0]=p,dep[u]=dep[p]+1;
	for (int &v : g[u]) if (v!=p) dfs(v,u);
	ed[u]=tot;
}
int ans[maxn];
void add(int l,int r,int d) { ans[l]+=d,ans[r+1]-=d; }

int main() {
	read(n),read(m);
	for (int i=1;i<=n;i++) f[i]=i;
	int x,y;
	for (int i=1;i<=m;i++) {
		read(x),read(y);
		if (find(x)!=find(y)) f[find(x)]=find(y),g[x].push_back(y),g[y].push_back(x);
		else E.push_back(MP(x,y));
	}
	dfs(1,0);
	for (int i=1;i<=19;i++) for (int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	for (pair<int,int> &A : E) {
		x=A.first,y=A.second;
		if (bg[x]<=bg[y]&&bg[y]<=ed[x]) swap(x,y);
		if (bg[y]<=bg[x]&&bg[x]<=ed[y]) {
			add(bg[x],ed[x],1);
			int z=x; for (int i=19;i>=0;i--) if (dep[fa[z][i]]>dep[y]) z=fa[z][i];
			add(1,n,1),add(bg[z],ed[z],-1);
		} else add(bg[x],ed[x],1),add(bg[y],ed[y],1);
	}
	for (int i=1;i<=n;i++) ans[i]+=ans[i-1];
	for (int i=1;i<=n;i++) if (ans[bg[i]]==(int)E.size()) printf("1"); else printf("0"); puts("");
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