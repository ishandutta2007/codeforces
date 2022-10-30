#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T;ll n;
inline int sm(ll x) {int r=0;while(x) r+=x%10,x/=10;return r;}
inline char chk(ll n) {return __gcd(n,(ll)sm(n))>1ll;}
inline void solve()
{
	read(n);
	if(chk(n)) printf("%lld\n",n);
	else if(chk(n+1)) printf("%lld\n",n+1);
	else if(chk(n+2)) printf("%lld\n",n+2);
	else if(chk(n+3)) printf("%lld\n",n+3);
}
int main() {for(read(T);T--;) solve();return 0;}