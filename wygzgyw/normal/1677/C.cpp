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
const int maxn=(3e5)+10;
int T,n,A[maxn],B[maxn],fa[maxn],sz[maxn];
int find(int x) {
	if (fa[x]==x) return x; return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	x=find(x),y=find(y);
	if (x!=y) fa[x]=y,sz[y]+=sz[x];
}
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(A[i]);
		for (int i=1;i<=n;i++) read(B[i]);
		for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
		for (int i=1;i<=n;i++) merge(A[i],B[i]);
		int C=0; ll ans=0;
		for (int i=1;i<=n;i++) if (find(i)==i) {
			C+=(sz[i]/2);
		}
		for (int i=1;i<=C;i++) ans-=i;
		for (int i=n;i>=n-C+1;i--) ans+=i;
		printf("%lld\n",ans*2);
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