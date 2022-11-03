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
const ll N=1600010,mod=998244353;
ll n,c[N],ans;
ll bing(ll a,ll b,ll c,ll d){
	return max(0ll,min(b,d)-max(a,c)+1);
}
int main(){
	n=read();
	For(i,1,n)c[i]=read();
	for(ll i=1;i<=n;i+=2){
		ll sum=0,L=1,R=c[i]; 
		for(ll j=i+1;j<=n;j+=2){
			ans+=bing(L,R,sum+1,sum+c[j]);
			sum+=c[j];
			L=max(L,sum);
			sum-=c[j+1];
		}
	}
	cout<<ans<<endl; 
}
/*

*/