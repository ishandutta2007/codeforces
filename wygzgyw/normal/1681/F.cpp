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
const int maxn=(5e5)+10;
int n; ll ans;
vector<pair<int,int> > g[maxn];
int fa[maxn],nxt[maxn];
int w[maxn],dep[maxn],lst[maxn];
int sz[maxn];
int all[maxn],buc[maxn];
void dfs(int u,int p) {
	dep[u]=dep[p]+1; sz[u]=1;
	for (auto [v,w] : g[u]) if (v!=p) {
		::w[v]=w; fa[v]=u;
		dfs(v,u); sz[u]+=sz[v];
	}
}
void dfs2(int u,int p) {
	int tmp=lst[w[u]]; nxt[u]=tmp;
	lst[w[u]]=u;
	for (auto [v,w] : g[u]) if (v!=p) {
		dfs2(v,u);
	}
	lst[w[u]]=tmp;
}
int main() {
	read(n);
	int x,y,z;
	for (int i=1;i<n;i++) {
		read(x),read(y),read(z);
		g[x].push_back(MP(y,z));
		g[y].push_back(MP(x,z));
	}
	dfs(1,0);
	dfs2(1,0);
	for (int i=2;i<=n;i++) {
		if (!nxt[i]) nxt[i]=1,buc[w[i]]+=sz[i];
		else all[nxt[i]]+=sz[i];
	}
	//for (int i=1;i<=n;i++) printf("%d ",nxt[i]); puts("");
	for (int i=2;i<=n;i++) {
		ll A=sz[i]-all[i];
		ll B=n-sz[i]-(all[nxt[i]]-sz[i])-(n-sz[nxt[i]]);
		if (nxt[i]==1) B=n-sz[i]-(buc[w[i]]-sz[i]);
		//printf("A=%lld,B=%lld\n",A,B);
		ans+=A*B;
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