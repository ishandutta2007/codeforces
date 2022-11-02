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
int n,p[maxn];
int R[maxn]; ll ans;
int tr[maxn];
void clear() { for (int i=1;i<=n;i++) tr[i]=n+1; }
void add(int x,int y) {
	for (;x<=n;x+=x&(-x)) tr[x]=min(tr[x],y);
}
int query(int x) {
	int res=n+1; for (;x;x-=x&(-x)) res=min(res,tr[x]); return res;
}
int st[maxn],tot;
vector<int> g[maxn],h[maxn];
void solve() {
	clear();
	for (int i=1;i<=n;i++) g[i].clear(),h[i].clear();
	tot=0;
	for (int i=n;i>=1;i--) {
		while (tot&&p[st[tot]]<p[i]) tot--;
		if (tot) g[st[tot]].push_back(i); st[++tot]=i;
	}
	tot=0;
	for (int i=1;i<=n;i++) {
		while (tot&&p[st[tot]]>p[i]) tot--;
		if (tot) h[st[tot]].push_back(i); st[++tot]=i;
	}
	for (int i=n;i>=1;i--) {
		for (int &x : g[i]) R[x]=min(R[x],query(p[x]));
		for (int &x : h[i]) add(p[x],x);
	}
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(p[i]),R[i]=n+1;
	solve();
	for (int i=1;i<=n;i++) p[i]=n-p[i]+1;
	solve();
	R[n+1]=n+1;
	for (int i=n;i>=1;i--) R[i]=min(R[i+1],R[i]),ans+=R[i]-i;
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