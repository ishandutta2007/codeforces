#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
ll n,ans;
map<ll,ll> mp[55][55];
ll Func(ll L,ll R,ll v){
	if (L>R) swap(L,R);
	if (!L&&!R) return !v;
	if (mp[L][R].find(v)!=mp[L][R].end()) return mp[L][R][v];
	if (v<0||v>(1ll<<L)+(1ll<<R)-L-R-2) return 0;
	return mp[L][R][v]=Func(L,R-1,v)+(R==1?0:Func(L,R-1,v-(1ll<<(R-1))+1));
}
/*
0  2
1  4
3  8
11 16
26 32
x 2x 4x 8x 
*/
int main(){
	scanf("%lld",&n);
	for (int L=0;1ll<<(L+1)<=n+1;++L)
		for (int R=0;(1ll<<(L+1))+(3ll<<R)<=n+4;++R){
			ll s1=(1ll<<(L+1))+(1ll<<(R+1))-3,s2=(1ll<<R)-1;
			ll f=(n-s2)/s1,g=n-s1*f-s2;
			//cout<<L<<' '<<R<<' '<<f<<' '<<g<<' '<<ans<<endl;
			ans+=Func(L,R,g);
		}
	printf("%lld\n",ans);
}