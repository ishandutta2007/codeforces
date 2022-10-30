//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;
int n,m,K,a[1000005];char ch[1000005];
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<n;i++) if(K) while(a[i]&&K) a[i]--,K--,a[n]++;
	for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}