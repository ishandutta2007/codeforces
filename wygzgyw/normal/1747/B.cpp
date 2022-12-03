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
int T,n;
int A[110],C[110];
int main() {
	read(T);
	while (T--) {
		read(n);
		printf("%d\n",(n+1)/2);
		for (int i=1;i<=n;i++) A[i]=i*3-2,C[i]=i*3;
		for (int i=1;i<=n-i+1;i++) printf("%d %d\n",A[i],C[n-i+1]);
	}
	return 0;
}