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
const int maxn=(1e5)+10;
int T,n;
int a[maxn],cnt[maxn][2],c[maxn][2];
bool solve() {
	int l=-1,r;
	for (int i=1;i<=n;i++) {
		if (l==-1) l=i;
		if (i==n||a[i]!=a[i+1]) {
			r=i;
			//printf("%d %d\n",l,r);
			if (abs(c[r][0]-c[l-1][0]-cnt[a[i]][0])!=0) return 0;
			if (abs(c[r][1]-c[l-1][1]-cnt[a[i]][1])!=0) return 0;
			l=-1;
		}
	}
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=1;i<maxn;i++) c[i][0]=c[i-1][0],c[i][1]=c[i-1][1],c[i][i&1]++;
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]),cnt[a[i]][i&1]++;
		sort(a+1,a+n+1);
		if (solve()) puts("YES"); else puts("NO");
		for (int i=1;i<=n;i++) cnt[a[i]][0]=cnt[a[i]][1]=0;
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