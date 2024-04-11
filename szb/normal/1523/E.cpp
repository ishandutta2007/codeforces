/*
 
*/ 
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define fi first
#define se second
#define pa pair<ll,ll>
#define pb push_back
#define y1 y11111111111111
#define debug puts("@@@@@@@@@@@@@@@@@@@")
 
#define cpy(a,b) memcpy(a,b,sizeof(b))
inline ll read()
{
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
 
void write(ll x)
{
	if(x < 0) putchar('-'), x= -x;
	if(x > 9)write(x/10);
	putchar(x%10+'0');
}
const ll N=200010,mod=1e9+7;
ll fac[N],inv[N],n,k;
ll ppow(ll x,ll k){
	ll ans=1;
	for(;k;k>>=1,x=x*x%mod)if(k&1)ans=ans*x%mod;
	return ans; 
}
void init(ll n){
	fac[0]=1;For(i,1,n)fac[i]=fac[i-1]*i%mod;
	inv[0]=1;For(i,1,n)inv[i]=ppow(fac[i],mod-2); 
}
ll C(ll n,ll m){
	if (n<m)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll fangan(ll n,ll k,ll i){
	n-=(i-1)*(k-1);
	return C(n,i);
}
int main(){
	init(200010); 
	ll T=read();
	for(;T--;){
		n=read();	k=read();	ll ans=0;
		For(i,1,n){
			ans=(ans+fangan(n,k,i)*ppow(C(n,i),mod-2))%mod;
		}
		++ans;	ans%=mod;
		cout<<ans<<endl;
	}
}
/*
*/