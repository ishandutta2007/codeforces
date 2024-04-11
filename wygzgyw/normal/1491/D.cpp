#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int q,x,y;
int now;
int main() {
	//freopen("1.txt","r",stdin);
	read(q); while (q--) {
		read(x),read(y);
		if (x==y) { puts("YES"); continue; }
		if (x>y) { puts("NO"); continue; }
		now=0; int flag=1;
		for (int i=0;i<=30;i++) {
			if (x>>i&1) now++;
			if (y>>i&1) now--;
			if (now<0) { flag=0; break; }
		}
		if (flag) puts("YES");
		else puts("NO");
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