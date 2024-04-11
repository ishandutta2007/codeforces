#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(4e5)+10;
int n,k,m,id[maxn],fa[maxn][20],dep[maxn];
bool vis[maxn];
int nxt[maxn*2],to[maxn*2],head[maxn],tot,dis[maxn];
queue<int> q;
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
int find(int x) {
	if (x==id[x]) return x;
	return id[x]=find(id[x]);
}
void merge(int x,int y) {
	x=find(x);
	y=find(y);
	id[x]=y;
}
void dfs(int u,int p) {
	fa[u][0]=p;
	dep[u]=dep[p]+1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs(v,u);
	}
}
int lca(int x,int y) {
	if (dep[x]>dep[y]) swap(x,y);
	for (int i=19;i>=0;i--)
		if (dep[fa[y][i]]>=dep[x]) y=fa[y][i];
	if (x==y) return x;
	for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int walk(int x,int d) {
	for (int i=19;i>=0;i--)
		if (d&(1<<i)) x=fa[x][i];
	return x;
}
int solve(int x,int y,int z) {
	if (dep[x]-dep[z]>=k) return walk(x,k);
	return walk(y,dep[y]-dep[z]-(k-(dep[x]-dep[z])));
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	read(k);
	read(m);
	int x,y,z,a,b;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		add(x,n+i),add(n+i,x);
		add(y,n+i),add(n+i,y);
	}
	while (m--) {
		read(x); q.push(x); vis[x]=1;
	}
	n*=2;
	for (int i=1;i<=n;i++) id[i]=i;
	while (!q.empty()) {
		int u=q.front(); q.pop();
		if (dis[u]>=k) continue;
		for (int i=head[u],v;i;i=nxt[i]) {
			v=to[i];
			merge(u,v);
			if (!vis[v]) {
				q.push(v);
				vis[v]=1;
				dis[v]=dis[u]+1;
			}
		}
	}
	dfs(1,0);
	for (int j=1;j<=19;j++)
	for (int i=1;i<=n;i++)
		fa[i][j]=fa[fa[i][j-1]][j-1];
	read(m);
	while (m--) {
		read(x); read(y);
		z=lca(x,y);
		if (dep[x]+dep[y]-2*dep[z]<=2*k) { printf("YES\n"); continue; }
		a=solve(x,y,z);
		b=solve(y,x,z);
		//printf("%d %d\n",a,b);
		if (find(a)==find(b)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/