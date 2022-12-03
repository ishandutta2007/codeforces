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
const int maxn=2010;
int n;
ll f[maxn][maxn];
struct node {
	ll x; int y,z;
} d[maxn*maxn];
bool cmp(node A,node B) { return A.x>B.x; }
int tot,sz[maxn];
int fa[maxn];
vector<int> g[maxn];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
void dfs(int u,int p) {
	sz[u]=1;
	for (int &v : g[u]) if (v!=p) {
		dfs(v,u);
		sz[u]+=sz[v];
		printf("%d %d %lld\n",u,v,(f[u][u]-f[u][v])/sz[v]);
	}
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) for (int j=1;j<=i;j++) {
		read(f[i][j]),f[j][i]=f[i][j];
		if (i!=j) d[++tot]=(node){f[i][j],i,j};
	}
	sort(d+1,d+tot+1,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=tot;i++) {
		int x=d[i].y,y=d[i].z;
		if (find(x)!=find(y)) {
			fa[find(x)]=find(y);
			g[x].push_back(y),g[y].push_back(x);
		}
	}
	dfs(1,0);
	return 0;
}