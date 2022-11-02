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
const int maxn=(1e5)+10;
const int INF=1e9;
int n,k,top[maxn],sz[maxn],fa[maxn],son[maxn],bt[maxn];
vector<int> g[maxn],light[maxn];
int col[maxn],dep[maxn],q;
int deg[maxn],rt[maxn],dfn[maxn],tot,bk[maxn];
namespace BST {
const int maxm=(1.6e7)+10;
int tot,ls[maxm],rs[maxm],tr[maxm];
void add(int x,int l,int r,int &root,int delta) {
	assert(x>=l&&x<=r);
	if (!root) root=++tot;
	if (l==r) { tr[root]+=delta; return; }
	int mid=(l+r)>>1;
	if (x<=mid) add(x,l,mid,ls[root],delta); else add(x,mid+1,r,rs[root],delta);
	tr[root]=tr[ls[root]]+tr[rs[root]];
}
int query(int L,int R,int l,int r,int root) {
	assert(L<=R);
	if (!root) return 0;
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)>>1,res=0;
	if (L<=mid) res=query(L,R,l,mid,ls[root]);
	if (mid<R) res+=query(L,R,mid+1,r,rs[root]);
	return res;
}
int rank(int &root,int x) {
	if (x==-INF) x=-n-1;
	return query(-n-1,x,-n-1,n+1,root);
}
void change(int &root,int x,int y) {
	if (x==-INF) x=-n-1;
	if (y==-INF) y=-n-1;
	if (x==INF) x=n+1;
	if (y==INF) y=n+1;
	add(x,-n-1,n+1,root,-1);
	add(y,-n-1,n+1,root,1);
}
};
void dfs1(int u,int p) {
	dep[u]=dep[p]+1,fa[u]=p,sz[u]=1;
	for (int v : g[u]) if (v!=p) {
		dfs1(v,u); sz[u]+=sz[v]; deg[u]++;
		if (sz[son[u]]<sz[v]) son[u]=v;
	}
}
int dfs2(int u,int p) {
	dfn[u]=++tot; bk[tot]=u;
	if (son[u]) top[son[u]]=top[u],bt[u]=dfs2(son[u],u);
	for (int v : g[u]) if (v!=p&&v!=son[u]) top[v]=v,dfs2(v,u);
	if (!deg[u]) return bt[u]=u;
	return bt[u];
}
struct node {
	int blue,red;
} init[3],tr[maxn*4];
node operator + (node t1,node t2) {
	return (node){min(max(t2.blue,t1.red),t1.blue),min(max(t2.red,t1.red),t1.blue)};
}
bool check(int x,int k,int delta) {
	int r=BST::rank(rt[x],k),b=deg[x]-r-1;
	//printf("%d %d %d\n",x,k,r);
	return k>=b-r+delta+1;
}
void pushup(int root) {
	tr[root]=(tr[root<<1]+tr[root<<1|1]);
}
void UPDATE(int x,int &k,int delta) {
	//printf("> %d %d\n",x,delta);
	while (check(x,k-1,delta)) k--;
	while (!check(x,k,delta)) k++;
}
void update(int x,node &A) {
	if (col[x]==-1) {
		UPDATE(x,A.blue,1);
		UPDATE(x,A.red,-1);
	} else A=init[col[x]];
}
node query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)>>1; node res=init[2];
	if (L<=mid) res=res+query(L,R,l,mid,root<<1);
	if (mid<R) res=res+query(L,R,mid+1,r,root<<1|1);
	return res;
}
int query(int x) {
	return query(dfn[x],dfn[bt[x]],1,n,1).blue;
}
void build(int x,int l,int r,int root) {
	if (l==r) {
		int u=bk[l];
		for (int v : light[u]) {
			//if (u==1) printf("ADD %d\n",query(v));
			BST::change(rt[u],0,query(v));
		}
		update(u,tr[root]);
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) build(x,l,mid,root<<1);
	else build(x,mid+1,r,root<<1|1);
	pushup(root);
}
void modify(int x,int l,int r,int root) {
	//if (root==1) printf("MODIFY %d\n",x);
	if (l==r) {
		update(bk[l],tr[root]);
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) modify(x,l,mid,root<<1); else modify(x,mid+1,r,root<<1|1);
	pushup(root);
}
void update(int x) {
	while (x) {
		int p=query(top[x]);
		modify(dfn[x],1,n,1);
		x=top[x];
		if (fa[x]) BST::change(rt[fa[x]],p,query(x));
		x=fa[x];
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	//printf("MLE %d\n",sizeof(BST::ls)*3/1024/1024);
	read(n),read(k);
	int op,x,y;
	init[1]={INF,INF};
	init[0]={-INF,-INF};
	init[2]={INF,-INF};
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(y),g[y].push_back(x);
	}
	for (int i=1;i<=n;i++) read(col[i]);
	dfs1(1,0);
	top[1]=1; dfs2(1,0);
	for (int i=2;i<=n;i++) if (top[i]==i) light[fa[i]].push_back(i);
	for (int i=1;i<=n;i++) if (deg[i]>1) BST::add(0,-n-1,n+1,rt[i],deg[i]-1);
	for (int i=n;i>=1;i--) build(i,1,n,1);
	
	//for (int i=1;i<=n;i++) printf("top[%d]=%d,bt[%d]=%d\n",i,top[i],i,bt[i]);
	read(q);
	while (q--) {
		read(op);
		if (op==1) read(x),printf("%d\n",k<query(x));
		else if (op==2) read(x),read(col[x]),update(x);
		else read(k);
		//printf("OK  %d %d\n",op,x);
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