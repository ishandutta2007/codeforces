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
int p[15],ans[15];
int main() {
	read(T);
	while (T--) {
		read(n);
		if (n%2==0) { for (int i=1;i<=n;i+=2) printf("%d %d ",i+1,i); }
		else if (n==1) printf("1 ");
		else {
			printf("1 3 2 ");
			for (int i=4;i<=n;i+=2) printf("%d %d ",i+1,i);
		}
		puts("");
	}
	return 0;
	for (n=1;n<=10;n++) {
		for (int i=1;i<=n;i++) p[i]=i;
		int mx=0;
		do {
			int tmp=0;
			for (int i=1;i<=n;i++) tmp+=p[i]*i/__gcd(i,p[i]);
			if (tmp>mx) mx=tmp,memcpy(ans,p,sizeof(p));
		} while (next_permutation(p+1,p+n+1));
		for (int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
	}
	return 0;
}