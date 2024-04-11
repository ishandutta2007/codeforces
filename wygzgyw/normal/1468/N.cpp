#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,c[4],a[6];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		for (int i=1;i<=3;i++) read(c[i]);
		for (int i=1;i<=5;i++) read(a[i]);
		c[1]-=a[1],c[2]-=a[2],c[3]-=a[3];
		if (c[1]<0||c[2]<0||c[3]<0||c[1]+c[2]+c[3]<a[4]+a[5]) { puts("NO"); continue; }
		a[4]-=c[1];
		a[5]-=c[2];
		if (max(0,a[4])+max(0,a[5])<=c[3]) puts("YES");
		else puts("NO");
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