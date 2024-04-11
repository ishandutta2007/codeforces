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
const ll N=(1<<14)|233,mod=1e9+7;
ll n,a[N],all[15][N],f[N];
ll ppow(ll x,ll k){
	ll ans=1;
	for(;k;k>>=1,x=x*x%mod)if (k&1)ans=ans*x%mod;
	return ans; 
}
ll qwq(ll x,ll y){
	return x*ppow(x+y,mod-2)%mod;
}
ll allwin(ll S,ll T){
	ll u=1;;
	For(i,1,n)if (S>>(i-1)&1)
		u=u*all[i][T]%mod;
	return u; 
}
ll count(ll S){
	ll ans=0;
	For(i,1,n)ans+=S>>(i-1)&1;
	return ans;
}
int main(){
	n=read();
	For(i,1,n)a[i]=read();
	For(i,1,n)rep(S,0,(1<<n))if(!(S>>(i-1)&1)){
		all[i][S]=1;
		For(j,1,n)if (S>>(j-1)&1)
			all[i][S]=all[i][S]*qwq(a[i],a[j])%mod;
	}
	rep(S,1,(1<<n)){
		f[S]=1;
		for(ll T=(S-1)&S;T;T=(T-1)&S){
			f[S]=(f[S]-f[T]*allwin(T,S-T))%mod; 
		}
		f[S]=(f[S]+mod)%mod;
	}
	ll ans=f[(1<<n)-1]*n%mod;
//	cout<<allwin(3,4)<<endl;
	rep(i,1,(1<<n)-1)ans=(ans+f[i]*allwin(i,((1<<n)-1)-i)%mod*count(i))%mod;//,cout<<i<<' '<<f[i]<<' '<<count(i)<<endl;
	ans=(ans+mod)%mod;
	write(ans);
}