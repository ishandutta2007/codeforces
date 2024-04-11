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
const int maxn=1010;
const ll INF=1e15;
int T,n,m;
ll a[maxn],b[maxn],now;
vector<int> g[maxn];
bool in[maxn],vis[maxn];
int from[maxn],all;
bool dfs(int x,int p,ll cur) {
	vis[x]=1;
	from[x]=p;
	for (int y : g[x]) if (y!=p) {
		if (in[x]&&in[y]) continue;
		if (!in[x]&&in[y]) {
			while (x) {
				if (!in[x]) all--,in[x]=1,now+=b[x];
				x=from[x];
			}
			return 1;
		}
		if (!in[x]&&vis[y]) {
			while (x) {
				if (!in[x]) all--,in[x]=1,now+=b[x];
				x=from[x];
			}
			return 1;
		}
		if (!vis[y]&&cur>a[y]) {
			if (dfs(y,x,cur+b[y])) return 1;
		}
	}
	from[x]=0; return 0;
}
bool solve(ll mid) {
	all=n-1;
	for (int i=1;i<=n;i++) in[i]=0;
	now=mid; in[1]=1;
	while (all) {
		for (int i=1;i<=n;i++) vis[i]=0;
		bool flag=0;
		for (int i=1;i<=n;i++) if (in[i]&&dfs(i,0,now)) { flag=1; break; }
		if (!flag) break;
	}
	return all==0;
}
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=2;i<=n;i++) read(a[i]);
		for (int i=2;i<=n;i++) read(b[i]);
		int x,y; for (int i=1;i<=m;i++) read(x),read(y),g[x].push_back(y),g[y].push_back(x);
		ll l=0,r=INF,mid,res=-1;
		while (l<=r) {
			mid=(l+r)>>1;
			if (solve(mid)) res=mid,r=mid-1; else l=mid+1;
		}
		printf("%lld\n",res);
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