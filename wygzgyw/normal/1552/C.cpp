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
int T,n,k;
int mat[210],d[210],tot;

int main() {
	read(T);
	while (T--) {
		read(n),read(k); int x,y;
		for (int i=1;i<=n*2;i++) mat[i]=0; tot=0;
		for (int i=1;i<=k;i++) read(x),read(y),mat[x]=y,mat[y]=x;
		for (int i=1;i<=n*2;i++) if (!mat[i]) d[++tot]=i;
		for (int i=1;i<=tot/2;i++) mat[d[i]]=d[i+tot/2],mat[d[i+tot/2]]=d[i];
		int ans=0;
		for (int i=1;i<=n*2;i++) if (mat[i]>i) {
			for (int j=i+1;j<mat[i];j++) if (mat[j]>mat[i]||mat[j]<i) ans++;		
		}
		printf("%d\n",ans/2);
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