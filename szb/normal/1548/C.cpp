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
#define clr(a,b) memset(a,b,sizeof (a))
#define fi first 
#define se second
#define pa pair<long double,ll>
#define y1 yyyyyyyyyyyyyyyyy
#define pb push_back
#define mk make_pair
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
const ll N=5000010,mod=1e9+7;
ll n,q,fac[N],inv[N],a[N],ans[N];
ll ppow(ll x,ll k){
	ll ans=1;for(;k;k>>=1,x=x*x%mod)if (k&1)ans=ans*x%mod;
	return ans;
}
int main(){
	n=read();	q=read();
	fac[0]=1;For(i,1,n*4+100)fac[i]=fac[i-1]*i%mod;
	inv[n*4+100]=ppow(fac[n*4+100],mod-2);
	FOr(i,n*4+99,0)inv[i]=inv[i+1]*(i+1)%mod;
	For(i,1,3*n+3)		a[i]=fac[3*n+3]*inv[i]%mod*inv[3*n+3-i]%mod;
	--a[1];--a[1];--a[1];	--a[2];--a[2];--a[2];	--a[3];
	For(i,1,3*n+3)	a[i]=(a[i]+mod)%mod;
	FOr(i,3*n,0)	ans[i]=a[i+3],a[i+1]=(a[i+1]-3*ans[i])%mod,a[i+2]=(a[i+2]-3*ans[i])%mod;
	For(i,1,q){
		write((ans[read()]+mod)%mod);
		puts("");
	}
}