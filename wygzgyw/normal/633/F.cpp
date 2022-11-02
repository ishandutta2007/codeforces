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
const int maxn=(1e5)+10;
int n;
ll a[maxn],mxdep[maxn];
ll f[maxn],g[maxn],ans;
vector<int> G[maxn];
void dfs1(int u,int p) {
	mxdep[u]=a[u];
	for (int &v : G[u]) if (v!=p) {
		dfs1(v,u);
		mxdep[u]=max(mxdep[u],mxdep[v]+a[u]);
	}
}
void dfs2(int u,int p) {
	f[u]=a[u];
	ll m1=0,m2=0;
	for (int &v : G[u]) if (v!=p) {
		dfs2(v,u);
		f[u]=max(f[u],f[v]);
		if (mxdep[v]>m1) m2=m1,m1=mxdep[v];
		else m2=max(m2,mxdep[v]);
	}
	f[u]=max(f[u],a[u]+m1+m2);
}
void dfs3(int u,int p) {
	ll m1=0,m2=0;
	for (int &v : G[u]) if (v!=p) {
		if (mxdep[v]>m1) m2=m1,m1=mxdep[v];
		else m2=max(m2,mxdep[v]);
	}
	for (int &v : G[u]) if (v!=p) {
		ll tmp=(mxdep[v]==m1?m2:m1);
		g[v]=max(g[u]+a[v],tmp+a[u]+a[v]);
		dfs3(v,u);
	}
}
void dfs4(int u,int p) {
	ll m1=0,m2=0;
	for (int &v : G[u]) if (v!=p) {
		if (f[v]>m1) m2=m1,m1=f[v];
		else m2=max(m2,f[v]);
	}
	ans=max(ans,m1+m2);
	for (int &v : G[u]) if (v!=p) {
		ll tmp=(f[v]==m1?m2:m1);
		ans=max(ans,g[u]+mxdep[v]+tmp);
		dfs4(v,u);
	}
	m1=m2=0; ll m3=0;
	for (int &v : G[u]) if (v!=p) {
		if (mxdep[v]>m1) m3=m2,m2=m1,m1=mxdep[v];
		else if (mxdep[v]>m2) m3=m2,m2=mxdep[v];
		else m3=max(m3,mxdep[v]);
	}
	for (int &v : G[u]) if (v!=p) {
		ll tmp=(mxdep[v]==m1?m2+m3:mxdep[v]==m2?m1+m3:m1+m2);
		ans=max(ans,f[v]+a[u]+tmp);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	int x,y;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		G[x].push_back(y),G[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,0);
	g[1]=a[1];
	dfs3(1,0);
	dfs4(1,0);
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