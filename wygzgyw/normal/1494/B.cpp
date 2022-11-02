#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T;
int n,a,b,c,d;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(a),read(b),read(c),read(d);
		int flag=0;
		for (int t=0;t<16;t++) {
			int A=a,B=b,C=c,D=d;
			if (t&1) A--,B--;
			if (t&2) B--,C--;
			if (t&4) C--,D--;
			if (t&8) D--,A--;
			if (0<=A&&A<=n-2&&0<=B&&B<=n-2&&0<=C&&C<=n-2&&0<=D&&D<=n-2) { flag=1; break; }
		}
		if (flag) puts("YES"); else puts("NO");
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