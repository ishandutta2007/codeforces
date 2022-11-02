#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,ans,x;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int a,b;
	a=-1,b=-2;
	for (int i=1;i<=n;i++) {
		read(x);
		if (x==b) {
			if (x!=a) ans++,a=x;
		} else {
			ans++;
			if (a!=b&&x!=a) a=-2;
		}
		b=x;
	}
	printf("%d\n",ans);
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