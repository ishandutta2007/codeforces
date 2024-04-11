//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,m;
inline void solve()
{
	read(n);if(n==1) return putchar('z'),putchar('\n'),void();
	if(n&1)
	{
		for(int i=1;i<n/2;i++) putchar('a');
		putchar('x'),putchar('t');
		for(int i=1;i<=n/2;i++) putchar('a');
		putchar('\n');
	}
	else
	{
		for(int i=1;i<n/2;i++) putchar('a');
		putchar('z');
		for(int i=1;i<=n/2;i++) putchar('a');
		putchar('\n');
	}
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}