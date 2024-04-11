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
int T,n,a[maxn];
int lsh[maxn],N;
vector<int> g[maxn];
int main() {
	read(T); while (T--) {
		read(n);
		N=0;
		for (int i=1;i<=n;i++) read(a[i]),lsh[++N]=a[i];
		sort(lsh+1,lsh+N+1); N=unique(lsh+1,lsh+N+1)-lsh-1;
		for (int i=1;i<=N;i++) g[i].clear();
		for (int i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+N+1,a[i])-lsh,g[a[i]].push_back(i);
		int ans=-1;
		for (int i=1;i<=N;i++) {
			for (int j=1;j<g[i].size();j++) {
				int x=g[i][j-1],y=g[i][j];
				ans=max(ans,n-y+x);
			}
		}
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