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
int T,n;
bitset<110> d[110][110];
char s[110];
int dis[110][110];
int fa[20010],sz[20010];
vector<int> g[20010];
int N(int x,int y) {
	if (x>y) swap(x,y);
	return x*(n+1)+y;
}
pair<int,int> M(int x) {
	return MP(x/(n+1),x%(n+1));
}
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
void link(int x,int y) {
	x=find(x),y=find(y);
	if (x==y) return;
	sz[x]+=sz[y],fa[y]=x;
}
vector<pair<int,int> > V;
namespace Y {
int fa[110];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
int S;
vector<int> g[110];
void dfs(int u,int p) {
	dis[S][u]=dis[S][p]+1;
	for (int &v : g[u]) if (v!=p) dfs(v,u);
}
bitset<110> H[110],now[110];
bool check() {
	for (int i=1;i<=n;i++) fa[i]=i,g[i].clear();
	for (auto [x,y] : V) {
		if (1<=x&&x<=n&&1<=y&&y<=n&&x!=y); else return 0;
		g[x].push_back(y),g[y].push_back(x);
		int a=find(x),b=find(y);
		if (a==b) return 0;
		fa[a]=b;
	}
	for (S=1;S<=n;S++) dis[S][0]=-1,dfs(S,0);
	for (int k=1;k<=n;k++) {
		for (int i=0;i<=n;i++) now[i].reset(),H[i].reset();
		for (int i=1;i<=n;i++) H[dis[i][k]].set(i);
		for (int i=1;i<=n;i++) {
			now[i]=H[dis[i][k]];
			now[i].reset(i);
			if (now[i]!=d[k][i]) return 0;
		}
	}
	puts("Yes");
	for (auto [x,y] : V) printf("%d %d\n",x,y);
	return 1;
}
};
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); int tot=N(n,n);
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) d[i][j].reset();
		for (int i=1;i<=tot;i++) fa[i]=i,sz[i]=1,g[i].clear();
		int F=1;
		for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) {
			scanf("%s",s+1);
			for (int k=1;k<=n;k++) if (s[k]=='1') {
				if (i==k||k==j) F=0;
				link(N(i,k),N(j,k));
				d[k][i].set(j);
				d[k][j].set(i);
			}
		}
		if (!F) { puts("No"); continue; }
		for (int i=1;i<=tot;i++) g[find(i)].push_back(i);
		bool flag=0;
		for (int i=1;i<=tot;i++) if (find(i)==i&&sz[i]==n-1) {
			V.clear();
			for (int &x : g[i]) V.push_back(M(x));
			if (Y::check()) { flag=1; break; }
		}
		if (!flag) puts("No");
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