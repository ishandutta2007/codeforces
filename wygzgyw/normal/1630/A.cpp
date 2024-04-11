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

int main() {
	read(T);
	while (T--) {
		read(n);
		read(k);
		if (n==4&&k==3) { puts("-1"); continue; }
		if (k==0) {
			for (int i=0;i<n-1-i;i++) printf("%d %d\n",i,n-i-1); continue;
		}
		if (k!=n-1) {
			printf("0 %d\n",n-1-k);
			printf("%d %d\n",k,n-1);
			for (int i=0;i<n-1-i;i++) if (i!=0&&i!=k&&i!=n-1-k) printf("%d %d\n",i,n-i-1); continue;
		}
		printf("0 1\n");
		int a=1,b=1;
		int lg=0; while ((1<<lg)<n) lg++;
		for (int i=1;i<lg;i++) if (i&1) a+=1<<i; else b+=1<<i;
		printf("%d %d\n",a,b);
		int c=n-1-a,d=n-1-b;
		printf("%d %d\n",c,d);
		printf("%d %d\n",n-2,n-1);
		for (int i=0;i<n-1-i;i++) if (i!=0&&i!=1&&i!=a&&i!=b&&i!=c&&i!=d&&i!=n-2&&i!=n-1) printf("%d %d\n",i,n-i-1);
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