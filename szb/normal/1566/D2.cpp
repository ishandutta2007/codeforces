#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define fi first
#define se second
#define cpy(a,b) memcpy(a,b,sizeof (b))
#define pa pair<ll,ll>
#define y1 yyyyyyyyyyyyyyyyy
#define pb push_back
#define mk make_pair
#define debug puts("@@@@@@@@@@@@@@@@@@@@@@@")
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
const ll N=1001000,mod=1e9+7;
pa a[N];
ll n,m,T;
bool operator <(pa a,pa b){
	return a.fi==b.fi?a.se<b.se:a.fi<b.fi;
}
int main(){
	T=read();
	for(;T--;){
		n=read();	m=read();
		ll cnt=0;
		For(i,1,n*m){
			a[i].fi=read();
			a[i].se=i;
		}
		sort(a+1,a+n*m+1);
		ll ans=0;
		for(ll k=1;k<=n*m;k+=m)rep(i,0,m)rep(j,i+1,m)ans+=(a[i+k].se<a[j+k].se)&&(a[i+k].fi!=a[j+k].fi);
		cout<<ans<<endl;
	}
}