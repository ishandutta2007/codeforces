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
	read(n),read(m);if(n>m) return puts("0"),void();else m++;
	int rs=0;for(int i=30;~i;i--)
	{
		int a=(n>>i)&1,b=(m>>i)&1;
		if(a>b) return printf("%d\n",rs),void();
		if(a<b) rs|=1<<i;
	}
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}