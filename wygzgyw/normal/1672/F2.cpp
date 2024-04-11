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
const int maxn=(6e5)+10;
int T,n,tot;
vector<int> g[maxn];
int in[maxn],a[maxn],b[maxn],cnt[maxn];
void add(int x,int y) { g[x].push_back(y),in[y]++; }
int hd,tl,q[maxn];
int main() {
	read(T);
	while (T--) {
		read(n); tot=n*2;
		for (int i=1;i<=tot;i++) in[i]=0,g[i].clear();
		for (int i=1;i<=n;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) read(a[i]),cnt[a[i]]++;
		for (int i=1;i<=n;i++) read(b[i]);
		int mx=0;
		for (int i=1;i<=n;i++) if (cnt[i]>cnt[mx]) mx=i;
		for (int i=1;i<=n;i++) if (a[i]!=mx&&b[i]!=mx) {
			add(i,a[i]+n),add(b[i]+n,i);
		}
		hd=1,tl=0;
		for (int i=1;i<=tot;i++) if (!in[i]) q[++tl]=i;
		while (hd<=tl) {
			int x=q[hd]; hd++;
			for (int &y : g[x]) {
				in[y]--;
				if (!in[y]) q[++tl]=y;
			}
		}
		if (tl==tot) puts("AC");
		else puts("WA");
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