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
const ll N=5100;
char s[N];
ll n,mod,c[N][N],fac[N],ffac[N];
void work(){
	ll ans=0;
	n=read();	mod=read(); 
	c[0][0]=1;
	For(i,1,n){
		c[i][0]=1;
		For(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;		
	}
	fac[n]=n;
	ffac[1]=1;
	For(i,2,n)ffac[i]=ffac[i-1]*i%mod;
	FOr(i,n-1,1)fac[i]=(fac[i+1]*i)%mod;
	ll most=1;
	for(;most*2<n;++most);
	ll unfair=0;
	For(i,1,most) unfair=(unfair+n*c[most-1][i-1]%mod*ffac[n-i])%mod;
	For(i,2,n)ans=(ans+fac[i])%mod;
	ll answ=(ans-unfair+mod)%mod;
	ans=0;
	unfair=0;
	For(i,1,most) unfair=(unfair+n*c[most-1][i-1]%mod*ffac[n-i]%mod*i)%mod;
	For(i,2,n)ans=(ans+fac[i]*(i-1))%mod;
	cout<<((ans-unfair+mod)%mod-answ+mod+n)%mod<<endl;
}
int main(){
//	ll T=read();
    	work();
}