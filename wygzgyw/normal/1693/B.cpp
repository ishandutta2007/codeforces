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
int T,n;
ll l[maxn],r[maxn];
int ans;
vector<int> g[maxn];
ll dfs(int u) {
	if ((int)g[u].size()==0) { ans++; return r[u]; }
	ll sum=0;
	for (int &v : g[u]) sum+=dfs(v);
	if (sum>r[u]) sum=r[u];
	else if (sum<l[u]) ans++,sum=r[u];
	return sum;
}
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=2;i<=n;i++) {
			int x;read(x);g[x].push_back(i);
		}
		for (int i=1;i<=n;i++) read(l[i]),read(r[i]);
		ans=0;
		dfs(1);
		printf("%d\n",ans);
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