#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,d,a[110];
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(d);
		for (int i=1;i<=n;i++) read(a[i]);
		int pos=2;
		while (1) {
			while (pos<=n&&!a[pos]) pos++;
			if (pos>n) break;
			if (d>=pos-1) {
				d-=pos-1;
				a[1]++;
				a[pos]--;
			} else break;
		}
		printf("%d\n",a[1]);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/