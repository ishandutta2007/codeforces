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
const int maxn=(2e5)+10;
int T,n,m;
ll a[maxn],sum[2];
vector<int> g[maxn];
int col[maxn],flag;
void dfs(int u) {
	for (int v : g[u]) {
		if (col[v]!=-1&&col[v]==col[u]) { flag=0; return; }
		if (col[v]==-1) col[v]=1-col[u],dfs(v);
		if (!flag) return;
	}
}

int main() {
	//freopen("1.txt","r",stdin);
	read(T); while (T--) {
		read(n),read(m);
		flag=1; int x,y; ll z; for (int i=1;i<=n;i++) g[i].clear(),col[i]=-1;
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) read(z),a[i]=z-a[i];
		for (int i=1;i<=m;i++) read(x),read(y),g[y].push_back(x),g[x].push_back(y);
		col[1]=0; dfs(1);
		if (flag) {
			sum[0]=sum[1]=0;
			for (int i=1;i<=n;i++) sum[col[i]]+=a[i];
			if (sum[0]==sum[1]) puts("YES"); else puts("NO");
		} else {
			z=0;
			for (int i=1;i<=n;i++) z+=a[i];
			if (abs(z)%2==0) puts("YES");
			else puts("NO");
		}
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