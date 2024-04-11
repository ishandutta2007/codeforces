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
int n,a[100005],K;
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	if(n<=200)
	{
		ll rs=-1e18;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) rs=max(rs,1ll*i*j-K*(a[i]|a[j]));
		printf("%lld\n",rs);return;
	}
	ll rs=-1e18;
	for(int i=n-200;i<=n;i++) for(int j=i+1;j<=n;j++) rs=max(rs,1ll*i*j-K*(a[i]|a[j]));
	printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}