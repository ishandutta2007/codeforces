#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
const int maxn=(3e5)+10;
int n,m,q,tot,head[maxn],nxt[maxn*2],to[maxn*2];
void add(int x,int y) {
	tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y;
	//if (x<=y) printf("add %d %d\n",x,y);
}
int idx,st[maxn],cnt,dfn[maxn],dep[maxn],low[maxn],bk[maxn],fa[maxn];
vector<int> g[maxn];
multiset<int> s[maxn];
int top[maxn],w[maxn],tr[maxn*4],son[maxn],sz[maxn],CNT;
void tarjan(int u,int p) {
	dfn[u]=low[u]=++idx;
	st[++CNT]=u;
	for (int v : g[u]) if (v!=p) {
		if (!dfn[v]) {
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if (low[v]>=dfn[u]) {
	//			printf("%d %d\n",v,u);
				add(++cnt,u),add(u,cnt);
				while (st[CNT+1]!=v) add(st[CNT],cnt),add(cnt,st[CNT]),CNT--;
			}
		} else low[u]=min(low[u],dfn[v]);
	}
}
void dfs1(int u,int p) {
	sz[u]=1; fa[u]=p; dep[u]=dep[p]+1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v==p) continue;
		dfs1(v,u); sz[u]+=sz[v];
		if (!son[u]||sz[v]>sz[son[u]]) son[u]=v;
	}
	if (u>n) {
		for (int i=head[u],v;i;i=nxt[i]) {
			v=to[i];
			if (v!=p) s[u].insert(w[v]);
		}
	}
}
void dfs2(int u,int p) {
	dfn[u]=++tot; bk[tot]=u;
	if (son[u]) top[son[u]]=top[u],dfs2(son[u],u);
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v==p||v==son[u]) continue;
		top[v]=v,dfs2(v,u);
	}
}
void pushup(int root) {
	tr[root]=min(tr[root<<1],tr[root<<1|1]);
}
void build(int l,int r,int root) {
	if (l==r) {
		if (bk[l]<=n) tr[root]=w[bk[l]];
		else tr[root]=(*s[bk[l]].begin());
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
void modify(int x,int l,int r,int root,int delta) {
	if (l==r) { tr[root]=delta; return; }
	int mid=(l+r)>>1;
	if (x<=mid) modify(x,l,mid,root<<1,delta);
	else modify(x,mid+1,r,root<<1|1,delta);
	pushup(root);
}
int query(int L,int R,int l,int r,int root) {
	assert(L<=R);
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)>>1,res=INF;
	if (L<=mid) res=query(L,R,l,mid,root<<1);
	if (mid<R) res=min(res,query(L,R,mid+1,r,root<<1|1));
	return res;
}
void modify(int x,int delta) {
	int y=fa[x];
	modify(dfn[x],1,cnt,1,delta);
	if (y>n) {
		int tmp=(*s[y].begin());
		s[y].erase(s[y].find(w[x]));
		s[y].insert(delta);
		if (tmp!=(*s[y].begin())) modify(dfn[y],1,cnt,1,(*s[y].begin()));
	}
	w[x]=delta;
}
int query(int x,int y) {
	int res=INF;
	while (top[x]!=top[y]) {
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		res=min(res,query(dfn[top[x]],dfn[x],1,cnt,1));
		x=fa[top[x]];
	}
	//printf("%d %d\n",x,y);
	if (dep[x]>dep[y]) swap(x,y);
	res=min(res,query(dfn[x],dfn[y],1,cnt,1));
	if (x>n) res=min(res,w[fa[x]]);
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m),read(q);
	for (int i=1;i<=n;i++) read(w[i]);
	//puts("OK");
	int x,y;
	for (int i=1;i<=m;i++) {
		read(x),read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cnt=n;
	//printf("OK %d %d\n",cnt,q);
	tarjan(1,0);
	tot=0;
	dfs1(1,0);
	top[1]=1,dfs2(1,0),fa[1]=1;
	//for (int i=1;i<=cnt;i++) printf("fa[%d]=%d, %d\n",i,fa[i],dep[i]);
	build(1,cnt,1);
	char op[3];
	//puts("OK");
	while (q--) {
		scanf("%s",op+1);
		read(x),read(y);
		if (op[1]=='A') printf("%d\n",query(x,y));
		else modify(x,y);
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