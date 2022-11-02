#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
const int maxn=(2e5)+10;
int T,n,dep[maxn],head[maxn],nxt[maxn*2],to[maxn*2],fa[maxn];
int tot,mx[maxn],mn[maxn],id[maxn];
ll dp[maxn],g[maxn][2],a[maxn],ans;
bool cmp(int x,int y) { return dep[x]<dep[y]; }
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
void dfs(int u,int p) {
	fa[u]=p;
	dep[u]=dep[p]+1; int d=dep[u];
	if (a[u]>a[mx[d]]||!mx[d]) mx[d]=u;
	if (a[u]<a[mn[d]]||!mn[d]) mn[d]=u;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs(v,u);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	int x,y,d;
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) head[i]=mx[i]=mn[i]=dp[i]=0,g[i][0]=g[i][1]=-INF; tot=0;
		for (int i=2;i<=n;i++) read(x),add(x,i),add(i,x);
		for (int i=2;i<=n;i++) read(a[i]);
		dfs(1,0);
		for (int i=1;i<=n;i++) id[i]=i;
		sort(id+2,id+n+1,cmp);
		for (int i=2;i<=n;i++) {
			x=id[i],d=dep[x];
			dp[x]=dp[fa[x]]+max(a[mx[d]]-a[x],a[x]-a[mn[d]]);
			if (d!=2) dp[x]=max(dp[x],max(g[d-1][0]-a[x],g[d-1][1]+a[x]));
			for (int j=head[x];j;j=nxt[j]) {
				y=to[j]; if (y==fa[x]) continue;
				g[d][0]=max(g[d][0],dp[x]+a[y]);
				g[d][1]=max(g[d][1],dp[x]-a[y]);
			}
		}
		ans=0;
		for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
		printf("%lld\n",ans);
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