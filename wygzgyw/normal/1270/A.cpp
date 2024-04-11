#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,k1,k2,x,flag,mx;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(k1); read(k2);
		mx=0;
		for (int i=1;i<=k1;i++)
			read(x),mx=max(mx,x);
		flag=0;
		for (int i=1;i<=k2;i++) {
			read(x);
			if (mx<x) flag=1;
		}
		if (flag) printf("NO\n");
		else printf("YES\n");
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