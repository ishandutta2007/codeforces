#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(4e5)+10;
int T,n,a[maxn],flag;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		int g=0,s=0,b=0;
		for (int i=1;i<=n/2;i++)
			if (a[i]!=a[i+1]) { g=i; break; }
		if (!g) { printf("0 0 0\n"); continue; }
		for (int i=n/2;i>=1;i--)
			if (a[i]!=a[i+1]) { b=i; break; }
		for (int j=g+1;j<b;j++)
			if (j-g>g&&b-j>g&&a[j]!=a[j+1]) {
				s=j; break;
			}
		if (!s) { printf("0 0 0\n"); continue; }
		printf("%d %d %d\n",g,s-g,b-s);
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/