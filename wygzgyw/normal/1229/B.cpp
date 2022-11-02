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
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=(1e5)+10;
int n;
int fa[maxn][20];
ll G[maxn][20];
int dep[maxn];
ll a[maxn];
vector<int> g[maxn];
int ans;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void dfs(int u,int p) {
	fa[u][0]=p,G[u][0]=a[p]; dep[u]=dep[p]+1;
	for (int &v : g[u]) if (v!=p) dfs(v,u);
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	int x,y;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,0);
	for (int j=1;j<=19;j++) for (int i=1;i<=n;i++)
		fa[i][j]=fa[fa[i][j-1]][j-1],
		G[i][j]=__gcd(G[i][j-1],G[fa[i][j-1]][j-1]);
	for (int i=1;i<=n;i++) {
		ll now=a[i];
		x=i;
		while (1) {
			y=x;
			for (int j=19;j>=0;j--) if (fa[x][j]&&now==__gcd(now,G[x][j])) x=fa[x][j];
			update(ans,(ll)(dep[y]-dep[x]+1)*(now%mod)%mod);
			if (x==1) break;
			x=fa[x][0];
			now=__gcd(now,a[x]);
		}
	}
	printf("%d\n",ans);
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