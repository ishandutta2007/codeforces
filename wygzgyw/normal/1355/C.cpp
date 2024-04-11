#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
ll A,B,C,D;
ll l,r;
ll ans;
ll S(ll x,ll y) {
	return (x+y)*(y-x+1)/2;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(A); read(B); read(C); read(D);
	for (int y=B;y<=C;y++) {
		l=max(A,C-y+1);
		r=min(B,D-y+1);
		if (l<=r) {
			ans+=S(l,r)+(y-C)*(r-l+1);
		}
		l=max(A,D-y+2);
		r=B;
		if (l<=r) {
			ans+=(r-l+1)*(D-C+1);
		}
	}
	printf("%lld\n",ans);
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