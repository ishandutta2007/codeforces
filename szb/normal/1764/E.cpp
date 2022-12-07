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
#define fi first 
#define se second
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
pair<ll,ll> a[100005];
void work(){

		ll n,k;
		cin>>n>>k;
		for (ll i=1;i<=n;++i)
			cin>>a[i].first>>a[i].second;
		if (n==1){
			if (k<=a[1].first)
				puts("YES");
			else
				puts("NO");
				return;
		}
		sort(a+2,a+1+n);
	ll mx=-2e9,tmx=-2e9;
	for (ll i=2;i<=n;++i){
		mx=max(max(mx,tmx),max(min(a[i].first,mx)+a[i].second,a[i].first));
		tmx=max(tmx,a[i].first+a[i].second);
	}
    ll pos=max(a[1].first,min(a[1].first,mx)+a[1].second);
	if (k<=pos)
		puts("YES");
	else
	puts("NO");
}
int main(){
	ll t;
//	ll T=read();
	ll T=read();
    for(;T--;){
    	work();
	}
	return 0;
}