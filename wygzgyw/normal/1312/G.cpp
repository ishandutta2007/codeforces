#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
const int INF=(1e9);
int n,bg[maxn],ed[maxn],dp[maxn],d[maxn];
int tot,m,id[maxn],s[maxn],tmp;
bool mk[maxn];
char ch[maxn],S[10];
vector<int> g[maxn];
bool cmp(int a,int b) { return ch[a]<ch[b]; }
void dfs(int u) {
	bg[u]=++tot; d[tot]=u;
	for (int i=0;i<g[u].size();i++) dfs(g[u][i]);
	ed[u]=tot;
}
struct SegTree {
	int tr[maxn*4],lazy[maxn*4];
	void init() {
		for (int i=1;i<=(n+1)*4;i++) tr[i]=lazy[i]=INF;
	}
	void pushdown(int root) {
		if (lazy[root]==INF) return;
		tr[root*2]=min(tr[root*2],lazy[root]);
		tr[root*2+1]=min(tr[root*2+1],lazy[root]);
		lazy[root*2]=min(lazy[root*2],lazy[root]);
		lazy[root*2+1]=min(lazy[root*2+1],lazy[root]);
		lazy[root]=INF;
	}
	void add(int L,int R,int l,int r,int root,int delta) {
		if (L>R) return;
		if (L<=l&&r<=R) {
			lazy[root]=min(lazy[root],delta);
			tr[root]=min(tr[root],delta);
			return;
		}
		pushdown(root);
		int mid=(l+r)/2;
		if (L<=mid) add(L,R,l,mid,root*2,delta);
		if (mid<R) add(L,R,mid+1,r,root*2+1,delta);
		tr[root]=min(tr[root*2],tr[root*2+1]);
	}
	int query(int x,int l,int r,int root) {
		if (l==r) return tr[root];
		pushdown(root);
		int mid=(l+r)/2;
		if (x<=mid) return query(x,l,mid,root*2);
		return query(x,mid+1,r,root*2+1);
	}
} T;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int x,u,v;
	for (int i=1;i<=n;i++) {
		read(x); g[x].push_back(i);
		scanf("%s",S+1);
		ch[i]=S[1];
	}
	for (int i=0;i<=n;i++) sort(g[i].begin(),g[i].end(),cmp);
	dfs(0);
	read(m);
	for (int i=1;i<=m;i++) {
		read(id[i]);
		s[bg[id[i]]]++;
		mk[id[i]]=1;
	}
	for (int i=1;i<=n+1;i++) s[i]+=s[i-1];
	for (int i=1;i<=n;i++) dp[i]=INF;
	T.init();
	for (int i=1;i<=n+1;i++) {
		u=d[i];
		if (mk[u]) {
			tmp=T.query(bg[u],1,n+1,1);
			dp[u]=min(dp[u],tmp+s[bg[u]]);
		}
		T.add(bg[u]+1,ed[u],1,n+1,1,dp[u]-s[bg[u]-1]);
		for (int j=0,v;j<g[u].size();j++) {
			v=g[u][j];
			dp[v]=min(dp[v],dp[u]+1);
		}
	}
	for (int i=1;i<=m;i++)
		printf("%d ",dp[id[i]]);
	printf("\n");
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