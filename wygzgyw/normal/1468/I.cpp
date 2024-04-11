#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n;
ll dx1,dy1,dx2,dy2,x,y;
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(dx1),read(dy1),read(dx2),read(dy2);
	if (dx1*dy2==dx2*dy1) { puts("NO"); return 0; }
	y=abs(gcd(dy1,dy2));
	dy1/=y,dy2/=y;
	x=abs(dx2*dy1-dy2*dx1);
	if (x*y==n) {
		puts("YES");
		for (int i=0;i<x;i++)
		for (int j=0;j<y;j++) printf("%d %d\n",i,j);
	} else puts("NO");
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