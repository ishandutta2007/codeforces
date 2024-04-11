#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(3e5)+10;
int n,a[maxn],fa[maxn],pos[maxn];
vector<int> g[maxn];
int now;
ll ans;
int tot,idx,tot2,out[maxn];
int bg[maxn],ed[maxn];
void dfs(int u,int dep) {
	if (a[u]<now) ans+=dep;
	bg[u]=++tot;
	if (a[u]>=now) {
		idx++;
		if (idx+now-1!=a[u]) { puts("NO"); exit(0); }
	}
	for (int v : g[u]) dfs(v,dep+1);
	ed[u]=tot;
	out[u]=++tot2;
	if (a[u]<now&&out[u]!=a[u]) { puts("NO"); exit(0); }
}
bool cmp(int x,int y) { return a[x]<a[y]; }
int main() {
//	freopen("1.txt","r",stdin);
	read(n); int x,y,cur;
	for (int i=1;i<=n;i++) read(a[i]),pos[a[i]]=i;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(y);
		fa[y]=x;
	}
	for (int i=1;i<=n;i++) sort(g[i].begin(),g[i].end(),cmp);
	now=max(1,a[1]-1);
	cur=pos[now];
	for (x=cur;x!=1;x=fa[x]) {
		swap(pos[a[x]],pos[a[fa[x]]]);
		swap(a[x],a[fa[x]]);
		ans++;
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) if (out[i]==now) {
		if (bg[cur]<=bg[i]&&bg[i]<=ed[cur]);
		else { puts("NO"); return 0; }
	}
	puts("YES");
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",bg[i]); puts("");
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/