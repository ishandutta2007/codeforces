#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(3e5)+10;
int n,m,tot,head[maxn],nxt[maxn*2],to[maxn*2];
void add(int x,int y) { tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y; }
int dep[maxn],fa[maxn][20];
int d1[maxn],d2[maxn],w1[maxn],w2[maxn];
ll ans;
void dfs(int u,int p) {
	dep[u]=dep[p]+1; fa[u][0]=p;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs(v,u);
	}
}
int lca(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--) if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=19;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int c0[maxn];
map<int,int> c1[maxn];
map<pair<int,int>,int> c2[maxn];
ll C2(int x) { return (ll)x*(x-1)/2; }
void DFS(int u,int p) {
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v==p) continue;
		DFS(v,u);
		d1[u]+=d1[v],d2[u]+=d2[v];
	}
}
int newnode() {
	tot++; return tot;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y,z,a,b;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		add(x,y),add(y,x);
	}
	tot=n;
	dfs(1,0);
	for (int i=1;i<=19;i++)
	for (int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	read(m);
	for (int i=1;i<=m;i++) {
		read(x),read(y),z=lca(x,y);
		w1[z]++;
		d1[z]-=2,d1[x]++,d1[y]++;
		a=x; for (int j=19;j>=0;j--) if (fa[a][j]&&dep[fa[a][j]]>dep[z]) a=fa[a][j];
		b=y; for (int j=19;j>=0;j--) if (fa[b][j]&&dep[fa[b][j]]>dep[z]) b=fa[b][j];
		if (a!=z) w2[a]++; if (b!=z) w2[b]++;
		d2[x]++,d2[y]++,d2[a]--,d2[b]--;
		if (a==z) a=newnode();
		if (b==z) b=newnode();
		c0[z]++;
		c1[z][a]++,c1[z][b]++;
		if (a>b) swap(a,b);
		c2[z][make_pair(a,b)]++;
	}
	DFS(1,0);
	for (int i=1;i<=n;i++) {
		ans+=C2(c0[i]);
		for (auto A : c1[i]) ans-=C2(A.second);
		for (auto A : c2[i]) ans+=C2(A.second);
		ans+=(ll)w1[i]*d1[i]-(ll)w2[i]*d2[i];
	}
	printf("%lld\n",ans);
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