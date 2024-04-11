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
int T,a,b,ans;
int query(int a,int b) {
	int res=(a|b),x=0;
	for (int i=25;i>=0;i--) {
		if (b>>i&1) {
			x|=1<<i;
		} else {
			x|=1<<i;
			res=min(res,a|x);
			x^=1<<i;
		}
	}
	return res;
}
int main() {
	read(T);
	while (T--) {
		read(a),read(b);
		ans=b-a; int now=0;
		while (a<=b) {
			ans=min(ans,now+query(a,b)-b+1);
			a++; now++;
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