#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1LL<<50;
const int maxn=(3e5)+10;
int n,m,tot,nxt[maxn*2],to[maxn*2],head[maxn],dfn[maxn],sz[maxn];
ll tr[maxn*4],dp[maxn],lazy[maxn*4];
int tL[maxn],tR[maxn],vL[maxn],vR[maxn];
vector<int> in[maxn],out[maxn];
struct node { int x,y; ll z; } d[maxn];
bool cmp(node A,node B) { return dfn[A.x]<dfn[B.x]; }
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
void DFS(int u,int p) {
	dfn[u]=++tot;
	sz[u]=1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v!=p) DFS(v,u),sz[u]+=sz[v];
	}
}
void F(ll &x,ll y) { x+=y; if (x>INF) x=INF; }
void pushdown(int root) {
	if (!lazy[root]) return;
	F(tr[root*2],lazy[root]);
	F(tr[root*2+1],lazy[root]);
	F(lazy[root*2],lazy[root]);
	F(lazy[root*2+1],lazy[root]);
	lazy[root]=0;
}
void add(int L,int R,int l,int r,int root,ll delta,bool flag=0) {
	if (L>R) return;
	//printf("%d %d %lld %d\n",L,R,delta,flag);
	if (L<=l&&r<=R) {
		if (flag) F(tr[root],delta),F(lazy[root],delta);
		else tr[root]=delta;
		return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2,delta,flag);
	if (mid<R) add(L,R,mid+1,r,root*2+1,delta,flag);
	tr[root]=min(tr[root*2],tr[root*2+1]);
}
ll query(int L,int R,int l,int r,int root) {
	if (L>R) return INF;
	if (L<=l&&r<=R) return tr[root];
	pushdown(root);
	int mid=(l+r)/2;
	ll res=INF;
	if (L<=mid) res=min(res,query(L,R,l,mid,root*2));
	if (mid<R) res=min(res,query(L,R,mid+1,r,root*2+1));
	return res;
}
void dfs(int u,int p) {
	ll sum=0;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v!=p) {
			dfs(v,u);
			F(sum,dp[v]);
		}
	}
	if (sum>=INF) { printf("-1\n"); exit(0); }
	if (u==1) { printf("%lld\n",sum); exit(0); }
	for (int i=0,id;i<in[u].size();i++) {
		id=in[u][i];
	//	printf("Add %d\n",id);
		add(id,id,1,m,1,sum+d[id].z);
	}
	for (int i=0,id;i<out[u].size();i++) {
		id=out[u][i];
	//	printf("Del %d\n",id);
		add(id,id,1,m,1,INF);
	}
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v!=p) add(vL[v],vR[v],1,m,1,sum-dp[v],1);
	}
	dp[u]=query(vL[u],vR[u],1,m,1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	int x,y;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		add(x,y); add(y,x);
	}
	tot=0;
	DFS(1,0);
	//for (int i=1;i<=n;i++) printf("%d ",dfn[i]); printf("\n");
	for (int i=1;i<=m;i++) read(d[i].x),read(d[i].y),read(d[i].z);
	sort(d+1,d+m+1,cmp);
	//for (int i=1;i<=m;i++) printf("%d %d %lld\n",d[i].x,d[i].y,d[i].z);
	for (int i=1;i<=n;i++) tL[i]=m+1;
	for (int i=1;i<=m;i++) {
		x=dfn[d[i].x];
		tL[x]=min(tL[x],i);
		tR[x]=max(tR[x],i);
		in[d[i].x].push_back(i);
		out[d[i].y].push_back(i);
	}
	for (int i=1;i<=n;i++) tR[i]=max(tR[i],tR[i-1]);
	for (int i=n-1;i>=1;i--) tL[i]=min(tL[i],tL[i+1]);
	for (int i=1;i<=n;i++) {
		vL[i]=tL[dfn[i]];
		vR[i]=tR[dfn[i]+sz[i]-1];
		//printf("%d %d\n",vL[i],vR[i]);
	}
	for (int i=1;i<=n*4;i++) tr[i]=INF;
	dfs(1,0);
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