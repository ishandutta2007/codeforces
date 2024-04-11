#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+10;
int n,N,head[maxn],nxt[maxn],to[maxn],tot;
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
bool vis[maxn];
void dfs(int u) {
	vis[u]=1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (!vis[v]) dfs(v);
	}
}
ll m;
struct node { int l,r; } d[maxn];
bool cmp(node a,node b) { return a.l<b.l; }
int S[maxn];
void add(int x) {
	for (;x<=N;x+=x&(-x)) S[x]++;
}
int query(int x) {
	int res=0;
	for (;x;x-=x&(-x)) res+=S[x];
	return res;
}
vector<int> g[maxn*4];
ll tr[maxn*4];
void add(int x,int l,int r,int root,int z) {
	g[root].push_back(z);
	if (l==r) {
		tr[root]++;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) add(x,l,mid,root*2,z);
	else add(x,mid+1,r,root*2+1,z);
	tr[root]=tr[root*2]+tr[root*2+1];
}
void query(int L,int R,int l,int r,int root,int z) {
	if (!tr[root]) return;
	if (L<=l&&r<=R) {
		for (int i=0;i<g[root].size();i++)
			add(z,g[root][i]),add(g[root][i],z);
		return;
	}
	int mid=(l+r)/2;
	if (L<=mid) query(L,R,l,mid,root*2,z);
	if (mid<R) query(L,R,mid+1,r,root*2+1,z);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); N=2*n;
	for (int i=1;i<=n;i++) read(d[i].l),read(d[i].r);
	sort(d+1,d+n+1,cmp);
	for (int i=1;i<=n;i++) {
		m+=query(d[i].r)-query(d[i].l-1);
		add(d[i].r);
	}
	if (m!=n-1) { printf("NO\n"); return 0; }
	for (int i=1;i<=n;i++) {
		query(d[i].l,d[i].r,1,N,1,i);
		add(d[i].r,1,N,1,i);
	}
	dfs(1);
	for (int i=1;i<=n;i++)
		if (!vis[i]) { printf("NO\n"); return 0; }
	printf("YES\n");
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