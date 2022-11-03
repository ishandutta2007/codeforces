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
const ll N=5000010;
ll n,mod,f[N],h[N],res,sum,pp;
int main(){
	n=read();mod=read();
	For(i,1,n){
		res=(res+h[i])%mod;
		if (i==1)f[1]=1;
		else    f[i]=(sum*2+res)%mod;
		sum+=f[i];sum%=mod;
		For(j,1,n/i)h[i*j]=(h[i*j]+f[i])%mod;
		For(j,1,n/(i+1))h[(i+1)*j]=(h[(i+1)*j]-f[i])%mod;		
	}
	cout<<(f[n]+mod)%mod;
}