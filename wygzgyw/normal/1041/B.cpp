#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
ll a,b,x,y;
ll gcd(ll A,ll B) {
	if (!A||!B) return A+B;
	return gcd(B,A%B);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(a); read(b); read(x); read(y);
	ll z=gcd(x,y); x/=z; y/=z;
	printf("%lld\n",min(a/x,b/y));
	return 0;
}