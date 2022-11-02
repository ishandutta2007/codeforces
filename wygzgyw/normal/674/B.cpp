#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m;
int a,b,c,d;
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	if (n==4||m<=n) { puts("-1"); return 0; }
	read(a),read(b),read(c),read(d);
	printf("%d %d ",a,c);
	for (int i=1;i<=n;i++) if (i!=a&&i!=b&&i!=c&&i!=d) printf("%d ",i);
	printf("%d %d\n",d,b);
	printf("%d %d ",c,a);
	for (int i=1;i<=n;i++) if (i!=a&&i!=b&&i!=c&&i!=d) printf("%d ",i);
	printf("%d %d\n",b,d);
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