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
const int maxn=(3e5)+10;
int T,n;
int dep[maxn],f[maxn];
vector<int> g[maxn];
int mxdep[maxn];
void chkmax(int &x,int y) { if (x<y) x=y; }
void dfs(int u,int p) {
	dep[u]=dep[p]+1;
	mxdep[u]=dep[u];
	int m1=dep[u],m2=dep[u];
	for (int &v : g[u]) if (v!=p) {
		dfs(v,u);
		mxdep[u]=max(mxdep[u],mxdep[v]);
		if (mxdep[v]>m1) m2=m1,m1=mxdep[v];
		else m2=max(m2,mxdep[v]);
	}
	int i=min(m1,m2)-1;
	if (i>=0) chkmax(f[i],m1+m2-2*dep[u]);
}
int main() {
	read(T);
	while (T--) {
		read(n);
		int x,y;
		for (int i=1;i<=n;i++) g[i].clear(),f[i]=0;
		for (int i=1;i<n;i++) {
			read(x),read(y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dep[0]=-1; dfs(1,0);
		for (int i=n-2;i>=0;i--) chkmax(f[i],f[i+1]);
		int ans=0;
		for (int i=1;i<=n;i++) {
			while (ans<mxdep[1]&&(f[ans]+1)/2+i>ans) ans++;
			printf("%d ",ans);
		}
		puts("");		
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