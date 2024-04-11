#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+10;
int n,m;
ll ans[maxn];
bool mk[maxn];
char s[10];
struct Kruskal {
	int fa[maxn],id[maxn],dfn[maxn],sz[maxn],tot,t[maxn];
	int ch[maxn][2],bg[maxn],ed[maxn],idx;
	void init() {
		tot=n;
		for (int i=1;i<=n;i++) id[i]=i,sz[i]=1;
	}
	int find(int x) {
		if (id[x]==x) return x;
		return id[x]=find(id[x]);
	}
	void add(int x,int y,int i) {
		x=find(x); y=find(y);
		t[++tot]=i;
		id[tot]=id[x]=id[y]=tot;
		sz[tot]=sz[x]+sz[y];
		ch[tot][0]=x;
		ch[tot][1]=y;
		fa[x]=fa[y]=tot;
	}
	void dfs(int u) {
		if (!ch[u][0]) {
			bg[u]=ed[u]=dfn[u]=++idx;
			return;
		}
		bg[u]=idx+1;
		dfs(ch[u][0]);
		dfs(ch[u][1]);
		ed[u]=idx;
	}
	void build() {
		for (int i=1;i<=tot;i++)
			if (find(i)==i) dfs(i);
		for (int i=1;i<=n;i++) id[i]=i;
	}
	int find(int x,int i) {
		while (fa[id[x]]&&t[fa[id[x]]]<=i) id[x]=fa[id[x]];
		return id[x];
	}
} T1,T2;
int tr[maxn*4],lazy[maxn*4];
void pushdown(int root) {
	if (!lazy[root]) return;
	tr[root*2]=max(tr[root*2],lazy[root]);
	tr[root*2+1]=max(tr[root*2+1],lazy[root]);
	lazy[root*2]=max(lazy[root*2],lazy[root]);
	lazy[root*2+1]=max(lazy[root*2+1],lazy[root]);
	lazy[root]=0;
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) {
		tr[root]=max(tr[root],delta);
		lazy[root]=max(lazy[root],delta);
		return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2,delta);
	if (mid<R) add(L,R,mid+1,r,root*2+1,delta);
	tr[root]=max(tr[root*2],tr[root*2+1]);
}
int query(int x,int l,int r,int root) {
	if (l==r) return tr[root];
	pushdown(root);
	int mid=(l+r)/2;
	if (x<=mid) return query(x,l,mid,root*2);
	return query(x,mid+1,r,root*2+1);
}
ll S[maxn];
void add(int x,ll delta) {
	for (;x<=n;x+=x&(-x)) S[x]+=delta;
}
ll query(int x) {
	ll res=0;
	for (;x;x-=x&(-x)) res+=S[x];
	return res;
}
int tot;
struct node { int x,id; char op; } d[maxn];
struct Node { int x,id,delta; };
vector<Node> q[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	int x,y,tmp;
	T1.init(); T2.init();
	for (int i=1;i<=m;i++) {
		scanf("%s",s+1);
		read(x);
		if (s[1]=='U') {
			read(y);
			T1.add(x,y,i);
		} else if (s[1]=='M') {
			read(y);
			T2.add(x,y,i);
		} else d[++tot]=(node){x,i,s[1]};
	}
	T1.build(); T2.build();
	for (int i=1;i<=tot;i++)
		if (d[i].op=='Z') {
			x=T2.find(d[i].x,d[i].id);
			add(T2.bg[x],T2.ed[x],1,n,1,d[i].id);
		} else if (d[i].op=='Q') {
			mk[i]=1;
			x=d[i].x;
			q[d[i].id].push_back((Node){T1.dfn[x],i,1});
			tmp=query(T2.dfn[x],1,n,1);
			q[tmp].push_back((Node){T1.dfn[x],i,-1});
		}
	
	int pos=1;
	for (int i=1;i<=m;i++) {
		while (pos<=tot&&d[pos].id<=i) {
			if (d[pos].op=='A') {
				x=T1.find(d[pos].x,d[pos].id);
				add(T1.bg[x],T1.sz[x]);
				add(T1.ed[x]+1,-T1.sz[x]);
			}
			pos++;
		}
		for (int j=0;j<q[i].size();j++) {
			tmp=q[i][j].id;
			ans[tmp]+=(ll)q[i][j].delta*query(q[i][j].x);
		}
	}
	for (int i=1;i<=m;i++)
		if (mk[i]) printf("%lld\n",ans[i]);
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