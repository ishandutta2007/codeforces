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
int T,n,col[maxn],m,N;
int U[maxn],W[maxn],w[maxn],fa[maxn];
vector<int> g[maxn],G[maxn];
int d[maxn],dy[maxn];
void dfs(int u,int p) {
	fa[u]=p;
	if (u!=1) {
		if (w[u]==-1) U[u]=u,W[u]=0,d[++N]=u,dy[u]=N;
		else W[u]=(W[p]^w[u]),U[u]=U[p];
	} else d[++N]=u,dy[u]=N,U[u]=u,W[u]=0;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i]; if (v==p) continue;
		w[v]=G[u][i];
		dfs(v,u);
	}
}
vector<pair<int,int> > h[maxn];
void add(int x,int y,int z) {
	h[x].push_back(MP(y,z));
	h[y].push_back(MP(x,z));
	//printf("add %d %d %d\n",x,y,z);
}
int flag;
void dfs(int u) {
	for (pair<int,int> &A : h[u]) {
		int v=A.first,w=A.second;
		if (col[v]!=-1&&col[v]!=(w^col[u])) { flag=0; return; }
		if (col[v]==-1) col[v]=(w^col[u]),dfs(v);
	}
}
void DFS(int u) {
	if (u!=1) {
		if (w[u]==-1) W[u]=col[u];
		else W[u]=(W[fa[u]]^w[u]);
	}
	for (int &v : g[u]) if (v!=fa[u]) DFS(v);
}
int main() {
	read(T);
	while (T--) {
		read(n); read(m);
		for (int i=1;i<=n;i++) g[i].clear(),G[i].clear(),h[i].clear(),col[i]=-1,dy[i]=d[i]=0;
		N=0; flag=1;
		int x,y,z;
		for (int i=1;i<n;i++) {
			read(x),read(y),read(z);
			g[x].push_back(y),g[y].push_back(x);
			G[x].push_back(z),G[y].push_back(z);
		}
		dfs(1,0);
		//for (int i=1;i<=n;i++) printf("%d %d %d\n",i,U[i],W[i]);
		while (m--) {
			read(x),read(y),read(z);
			int tmp=(W[x]^W[y]);
			tmp=__builtin_popcount(tmp); tmp&=1; tmp^=z;
			//printf("x=%d,y=%d\n",x,y);
			x=U[x],y=U[y];
			add(x,y,tmp);
		}
		for (int i=1;i<=N;i++) if (-1==col[d[i]]) col[d[i]]=0,dfs(d[i]);
		if (!flag) { puts("NO"); continue; }
		puts("YES");
		DFS(1);
		for (int i=2;i<=n;i++) printf("%d %d %d\n",i,fa[i],W[i]^W[fa[i]]);
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