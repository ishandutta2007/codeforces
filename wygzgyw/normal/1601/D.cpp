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
const int maxn=(5e5)+10;
int n,d,ans;
struct node {
	int s,a;
} D[maxn];
bool cmp(node A,node B) {
	if (max(A.s,A.a)!=max(B.s,B.a)) return max(A.s,A.a)<max(B.s,B.a);
	if (A.s==B.s) return A.a<B.a;
	return A.s<B.s;
}
int main() {
	read(n),read(d);
	for (int i=1;i<=n;i++) read(D[i].s),read(D[i].a);
	sort(D+1,D+n+1,cmp);
	for (int i=1;i<=n;i++) if (d<=D[i].s) ans++,d=max(d,D[i].a);
	printf("%d\n",ans);
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