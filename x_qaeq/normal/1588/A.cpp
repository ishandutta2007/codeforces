//Coded by X_qaeq on 2021.11.14 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=1005;int n,a[N],b[N];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) if(a[i]!=b[i]&&a[i]+1!=b[i]) return puts("NO"),void();
	puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}