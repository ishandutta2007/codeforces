#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,m,q;
int head[maxn],nxt[maxn*2],to[maxn*2],tot;
void add(int x,int y) {
	tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y;
}
vector<int> G[maxn],g[maxn][20];
int fa[maxn][20],dep[maxn];
void merge(vector<int> a,vector<int> b,vector<int> &c) {
	c.clear(); int i=0,j=0,n=(int)a.size(),m=(int)b.size();
	while (i<n||j<m) {
		if ((int)c.size()>=10) break;
		if (i<n&&j<m&&a[i]==b[j]) i++;
		if (i==n) c.emplace_back(b[j]),j++;
		else if (j==m) c.emplace_back(a[i]),i++;
		else if (a[i]>b[j]) c.emplace_back(b[j]),j++;
		else c.emplace_back(a[i]),i++;
	}
}
void dfs(int u,int p) {
	dep[u]=dep[p]+1,fa[u][0]=p;
	g[u][0]=G[p];
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs(v,u);
	}
}
vector<int> res;
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m),read(q);
	int x,y,z;
	for (int i=1;i<n;i++) {
		read(x),read(y),add(x,y),add(y,x);
	}
	for (int i=1;i<=m;i++) {
		read(x);
		if ((int)G[x].size()<=9) G[x].push_back(i);
	}
	dfs(1,0);
	for (int i=1;i<=19;i++)
	for (int j=1;j<=n;j++) {
		fa[j][i]=fa[fa[j][i-1]][i-1];
		merge(g[j][i-1],g[fa[j][i-1]][i-1],g[j][i]);
	}
	while (q--) {
		read(x),read(y),read(z);
		if (dep[x]<dep[y]) swap(x,y); res.clear();
		if (x==y) res=G[x];
		else {
			merge(G[x],G[y],res);
			for (int i=19;i>=0;i--) if (dep[fa[x][i]]>=dep[y]) merge(res,g[x][i],res),x=fa[x][i];
			for (int i=19;i>=0;i--) if (fa[x][i]!=fa[y][i]) {
				merge(res,g[x][i],res);
				merge(res,g[y][i],res);
				x=fa[x][i],y=fa[y][i];
			}
			if (x!=y) merge(res,g[x][0],res),merge(res,g[y][0],res);
		}
		n=(int)res.size();
		printf("%d ",min(n,z));
		for (int i=0;i<n&&i<z;i++) printf("%d ",res[i]);
		puts("");
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