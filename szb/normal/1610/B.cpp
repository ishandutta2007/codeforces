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
const ll N=4001000,mod=1e9+7;
ll n,m,a[N];
bool check(ll x){
	ll l=1,r=n;
	for(;;){
		for(;l<=r&&a[l]==x;)++l;
		for(;l<=r&&a[r]==x;)--r;
		if (l>r)return 1;
		if (a[l]!=a[r])return 0; 
		++l;--r;
	}
}
int main(){
	for(ll T=read();T--;){
		n=read();
		For(i,1,n)a[i]=read();
		ll x=0,y=0,p=0,q=0;
		For(i,1,n)if(a[i]!=a[n-i+1]){
			x=a[i],y=a[n-i+1];
			FOr(j,i-1,1)if (a[j]!=a[i]){p=a[j];break;}
			For(j,n-i+2,n)if(a[j]!=a[n-i+1]){q=a[j];break;}
			break;
		}
		
		if(!x&&!y)puts("YES");
		else if (check(x)||check(y)||check(p)||check(q))puts("YES");
		else puts("NO"); 
	}
}