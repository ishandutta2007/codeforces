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
ll n;
inline ll ask(ll l,ll r)
{
	if(l>r||l<1||r<1||r>n||l>n) return 0;
	printf("? %lld %lld\n",l,r),fflush(stdout);ll w;read(w);return w;
}
inline void ans(ll a,ll b,ll c) {printf("! %lld %lld %lld\n",a,b,c),fflush(stdout);}
inline void solve()
{
	read(n);ll k=0;
	for(ll l=1,r=n,md=(l+r)>>1;l<=r;md=(l+r)>>1)
		if(ask(md,n)==0) k=md,r=md-1;else l=md+1;
	ll q1=ask(1,k),q2=ask(1,k-1),j=k-(q1-q2+1)+1;
	q1=ask(1,j-1),q2=ask(1,j-2);ll i=j-(q1-q2+1);
	ans(i,j,k);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}