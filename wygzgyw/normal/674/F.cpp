#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
typedef unsigned int uint;
ll n,p,q;
int x,g;
uint mi,ans,res,C[150],A,a[150];
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(p),read(q);
	C[0]=1;
	for (int i=1;i<=p;i++) {
		C[i]=1;
		a[i]=n-i+1;
		x=i;
		for (int j=1;j<=i;j++) {
			g=gcd(x,a[j]);
			x/=g,a[j]/=g;
			C[i]*=a[j];
		}
	}
	for (uint d=1;d<=q;d++) {
		res=0; mi=1;
		for (int i=0;i<=p&&i<n;i++) {
			res+=(mi*C[i]);
			mi*=d;
		}
		ans^=(res*d);
	}
	printf("%u\n",ans);
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