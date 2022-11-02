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
typedef unsigned long long ull;
typedef long long ll;
const int maxn=(5e5)+10;
const int INF=1e9;
int T,n,m;
bool vis[maxn];
vector<int> g[maxn];
int fa[maxn],dep[maxn],cnt[maxn],f[maxn];
ull H[maxn],mi[maxn],H2[maxn];
map<pair<int,int>,int> M;
int FA[maxn][20];
int sz[maxn],top[maxn],son[maxn];
struct node {
	int a,b,c,d; ll res;
} ans;
void dfs(int u) {
	vis[u]=1; sz[u]=1; son[u]=0;
	for (int &v : g[u]) if (v!=fa[u]) {
		if (vis[v]) {
			if (dep[u]<dep[v]) {
				f[v]++,f[u]--;
				int id=M[MP(u,v)];
				H[v]+=mi[id],H[u]-=mi[id];
				H2[v]+=id,H2[u]-=id;
			}
		} else {
			//printf("%d %d\n",v,u);
			fa[v]=u,dep[v]=dep[u]+1; dfs(v);
			sz[u]+=sz[v];
			if (sz[v]>sz[son[u]]) son[u]=v;
		}
	}
}
int dfn[maxn],TOT,bk[maxn];
void dfs2(int u) {
	dfn[u]=++TOT,bk[TOT]=u;
	//printf("u=%d\n",u);
	if (son[u]) {
		top[son[u]]=top[u];
		dfs2(son[u]);
	}
	for (int &v : g[u]) if (fa[v]==u) {
		if (v!=son[u]) top[v]=v,dfs2(v);
		H[u]+=H[v],f[u]+=f[v],H2[u]+=H2[v];
	}
}
void dfs3(int u) {
	for (int &v : g[u]) if (fa[v]==u) {
		dfs3(v); cnt[u]+=cnt[v];
	}
}
int lca(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--) if (FA[x][i]&&dep[FA[x][i]]>=dep[y]) x=FA[x][i];
	if (x==y) return x;
	for (int i=19;i>=0;i--) if (FA[x][i]!=FA[y][i]) x=FA[x][i],y=FA[y][i];
	return fa[x];
}
pair<int,int> E[maxn];
map<ull,vector<int> > V;
int lst[maxn],CL[maxn];
bool cmp(int x,int y) { return dep[x]<dep[y]; }
ll tr[maxn*4],lazy[maxn*4],pos[maxn*4];
void pushup(int root) {
	if (tr[root<<1]<tr[root<<1|1]) tr[root]=tr[root<<1|1],pos[root]=pos[root<<1|1];
	else tr[root]=tr[root<<1],pos[root]=pos[root<<1];
}
void build(int l,int r,int root) {
	lazy[root]=0;
	if (l==r) { tr[root]=0,pos[root]=l; return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1),pushup(root);
}
void puttag(int root,ll delta) {
	lazy[root]+=delta,tr[root]+=delta;
}
void pushdown(int root) {
	if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0;
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L>R) return;
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
pair<ll,int> query(int L,int R,int l,int r,int root) {
	if (L>R) return MP(-INF,0);
	if (L<=l&&r<=R) {
		return MP(tr[root],pos[root]);
	}
	int mid=(l+r)>>1;
	pushdown(root); pair<ll,int> res=MP(-INF,0);
	if (L<=mid) res=query(L,R,l,mid,root<<1);
	if (mid<R) res=max(res,query(L,R,mid+1,r,root<<1|1));
	return res;
}
struct Node { int x,y,z; };
vector<Node> G[maxn],G2[maxn];
pair<ll,int> query(int x,int y) {
	pair<ll,int> res=MP(-INF,0);
	//printf("?? %d %d\n",x,y);
	while (top[x]!=top[y]) {
		res=max(res,query(dfn[top[x]],dfn[x],1,n,1));
		x=fa[top[x]];
	}
	res=max(res,query(dfn[y],dfn[x],1,n,1));
	return res;
}
void add(int x,int y,int delta) {
	//printf("add %d %d %d\n",x,y,delta);
	while (top[x]!=top[y]) {
		add(dfn[top[x]],dfn[x],1,n,1,delta);
		x=fa[top[x]];
	}
	//printf("%d %d\n",dfn[x],dfn[y]);
	add(dfn[y],dfn[x],1,n,1,delta);
}
void add(int x,int y) {
	//printf("%d %d\n",x,y);
	while (top[x]!=top[y]) {
		G[top[x]].push_back((Node){x,y,-2});
		G2[x].push_back((Node){x,y,2});
		//printf("[%d,%d]\n",top[x],x);
		x=fa[top[x]];
	}
		//printf("[%d,%d]\n",y,x);
	G[y].push_back((Node){x,y,-2});
	G2[x].push_back((Node){x,y,2});
}
int ALL;
void DFS(int u) {
	if (!ALL) return;
	if (u>1) {
		for (Node &A : G[u]) add(A.x,A.y,A.z);
		if (lst[u]!=u&&H[u]) {
			//printf("u=%d %d\n",u,lst[u]);
			pair<ll,int> res=query(fa[u],lst[u]);
			res.second=bk[res.second];
			res.first+=cnt[u];
			//if (u==5) printf("%d %d\n",cnt[5],cnt[10]);
			//printf(">> res=%lld,u=%d %d\n",res.first,u,lst[u]);
			if (res.first>ans.res) ans=(node){u,fa[u],res.second,fa[res.second],res.first};
			//exit(0);
			ALL--;
			if (!ALL) return;
		}
		if (H[u]) add(u,u,cnt[u]);
		//printf("add %d %d\n",dep[u],cnt[u]);
		//printf("u=%d,CL=%d\n",u,CL[u]);
		if (CL[u]&&H[u]) add(u,CL[u],-INF);
		for (Node &A : G2[u]) add(A.x,A.y,A.z);
		//if (u==2) exit(0);
	}
	if (son[u]) DFS(son[u]);
	//	for (Node &A : G2[u]) add(A.x,A.y,A.z);
	for (int &v : g[u]) if (v!=son[u]&&fa[v]==u) DFS(v);
}
int FD(int x,int y) {
	for (int i=19;i>=0;i--) if (dep[FA[x][i]]>dep[y]) x=FA[x][i]; return x;
}
int main() {
	//freopen("1.txt","r",stdin);
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=mi[i-1]*99988883;
	read(T);
	while (T--) {
		read(n),read(m); M.clear(); V.clear();
		for (int i=1;i<=n;i++) G[i].clear(),G2[i].clear(),g[i].clear();
		ans.res=0; ALL=0;
		for (int i=1;i<=m;i++) {
			int x,y; read(x),read(y);
			g[x].push_back(y),g[y].push_back(x);
			M[MP(x,y)]=M[MP(y,x)]=i;
			E[i]=MP(x,y);
			if (i==1) ans.a=x,ans.b=y;
			else if (i==2) ans.c=x,ans.d=y;
		}
		for (int i=1;i<=n;i++) fa[i]=vis[i]=cnt[i]=H[i]=f[i]=H2[i]=lst[i]=CL[i]=0;
		dfs(1);
		for (int i=1;i<=n;i++) FA[i][0]=fa[i];
		for (int i=1;i<=19;i++) for (int j=1;j<=n;j++) FA[j][i]=FA[FA[j][i-1]][i-1];
		int K; read(K);
		TOT=0;
		top[1]=1,dfs2(1);
		while (K--) {
			int x,y; read(x),read(y);
			int z=lca(x,y);
			int a=FD(y,z),b=FD(x,z);
			if (z!=y) add(y,a);
			if (z!=x) add(x,b);
		//	printf("x=%d,y=%d,z=%d\n",x,y,z);
			cnt[x]++,cnt[y]++,cnt[z]-=2;
		}
		dfs3(1);
		/*for (int i=1;i<=n;i++) printf("%d ",cnt[i]); puts("");
		for (int i=1;i<=n;i++) printf("%d,%d ",i,fa[i]); puts("");
		for (int i=1;i<=n;i++) printf("%llu ",H[i]); puts("");
		for (int i=1;i<=n;i++) printf("%u ",top[i]); puts("");
		for (int i=1;i<=n;i++) printf("%d ",dfn[i]); puts("");*/
		int m1=0,m2=0,i1=0,i2=0;
		for (int i=2;i<=n;i++) {
			if (f[i]==0) {
				if (cnt[i]>m1) m2=m1,i2=i1,m1=cnt[i],i1=i; else if (cnt[i]>m2) m2=cnt[i],i2=i;
			}
			if (f[i]==1) {
				int id=H2[i];
				if (cnt[i]>ans.res) ans=(node){i,fa[i],E[id].first,E[id].second,cnt[i]};
			}
		}
		if (!i2) {
			if (i1==2) i2=3; else i2=2;
		}
		if (m1+m2>ans.res) ans=(node){i1,fa[i1],i2,fa[i2],m1+m2};
		for (int i=2;i<=n;i++) V[H[i]].push_back(i);
		for (auto it : V) {
			sort(it.second.begin(),it.second.end(),cmp);
			CL[it.second.back()]=it.second[0];
			for (int &x : it.second) lst[x]=it.second[0];
		//	for (int &x : it.second) printf("%d ",x); puts("");
		}
		build(1,n,1);
		ALL=0;
		for (int i=2;i<=n;i++) if (lst[i]!=i&&H[i]) ALL++;
		DFS(1);
		printf("%lld\n",ans.res);
	    printf("%d %d\n%d %d\n",ans.a,ans.b,ans.c,ans.d);
		//exit(0);
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