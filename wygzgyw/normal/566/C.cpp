#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,N,tot,sz[maxn],mxsz[maxn];
double w[maxn],len[maxn*2],ans;
bool vis[maxn];
int head[maxn],nxt[maxn*2],to[maxn*2];
void add(int x,int y,int z) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y; len[tot]=z;
}
int root;
void dfs1(int u,int p) {
	sz[u]=1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p||vis[v]) continue;
		dfs1(v,u); sz[u]+=sz[v];
	}
}
void dfs2(int u,int p) {
	mxsz[u]=0;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p||vis[v]) continue;
		dfs2(v,u);
		mxsz[u]=max(mxsz[u],sz[v]);
	}
	mxsz[u]=max(mxsz[u],N-sz[u]);
	if (mxsz[u]<mxsz[root]||!root) root=u;
}

double sum,dao,d[maxn];
int S,pos;
void dfs(int u,int p,long double dep) {
	sum+=dep*sqrt(dep)*w[u];
	dao+=sqrt(dep)*1.5*w[u];
	d[S]+=sqrt(dep)*1.5*w[u];
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v!=p) dfs(v,u,dep+len[i]);
	}
}

void solve(int u) {
//	printf("%d\n",u);
	vis[u]=1;
	sum=dao=0;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		S=v; d[S]=0;
		dfs(v,u,len[i]);
	}
	if (sum<ans) ans=sum,pos=u;
//	printf("%.5lf %.5lf\n",sum,dao);
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (vis[v]) continue;
		if (dao-d[v]*2<0) {
			dfs1(v,u);
			N=sz[v]; root=0;
			dfs2(v,u);
			solve(root);
			return;
		}
	}
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(w[i]);
	int x,y,z;
	for (int i=1;i<n;i++) {
		read(x); read(y); read(z);
		add(x,y,z);
		add(y,x,z);
	}
	ans=1e20;
	dfs1(1,0);
	N=n;
	dfs2(1,0);
	solve(root);
	printf("%d %.7lf\n",pos,ans);
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