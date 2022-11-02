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
const ll INF=1e18;
const int maxn=4010;
int n,m;
ll a[maxn],dp[maxn][maxn];
vector<int> g[maxn];
int build(int l,int r) {
	if (l>r) return 0;
	if (l==r) return l;
	int mid=l;
	for (int i=l+1;i<=r;i++) if (a[i]<a[mid]) mid=i;
	g[mid].push_back(build(l,mid-1));
	g[mid].push_back(build(mid+1,r));
	return mid;
}
int sz[maxn];
ll tmp[maxn];
void chkmax(ll &x,ll y) { if (x<y) x=y; }
void dfs(int u) {
	sz[u]=1;
	for (int &v : g[u]) if (v) {
		dfs(v);
		ll w=abs(a[u]-a[v]);
		//printf("u=%d,v=%d,w=%lld\n",u,v,w);
		for (int i=0;i<=sz[u]+sz[v]&&i<=m;i++) tmp[i]=-INF;
		for (int i=0;i<=sz[v];i++) for (int j=0;j<=sz[u]&&i+j<=m;j++) {
			chkmax(tmp[i+j],dp[u][j]+dp[v][i]+w*i*(m-i));
		}
		sz[u]+=sz[v];
		for (int i=0;i<=sz[u]&&i<=m;i++) dp[u][i]=tmp[i];
	}
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	int rt=build(1,n);
	dfs(rt);
	printf("%lld\n",dp[rt][m]);
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