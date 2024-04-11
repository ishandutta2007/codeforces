#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T;
ll x,y,n;
int main() {
	read(T);
	while (T--) {
		read(x),read(y);
		if (y<x) n=x+y;
		else n=y-(y%x)/2;
		printf("%lld\n",n);
		assert(n%x==y%n);
	}
	return 0;
}