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
const ll N=200010,mod=998244353;
char s[N];
ll n,a[N],b[N],fac[N],inv[N];
ll ppow(ll x,ll k){
	ll ans=1;
	for(;k;k>>=1,x=x*x%mod)if(k&1)ans=ans*x%mod;
	return ans; 
}
void init(ll n){
	fac[0]=1;For(i,1,n)fac[i]=fac[i-1]*i%mod;
	inv[0]=1;For(i,1,n)inv[i]=ppow(fac[i],mod-2); 
}
ll C(ll a,ll b){
	return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
	init(100010);
	ll T=read();
	for(;T--;){
		n=read();
		scanf("%s",s+1);
		For(i,1,n)a[i]=s[i]-'0';
		ll ans=0,sum1=0,sum2=0;
		For(i,1,n)if (a[i]){
			ll j=i;
			for(;a[j+1]==a[i];++j);
			sum1+=j-i+1;
			sum2+=(j-i+1)&1;
			i=j;
		}
		n-=sum1;
		sum1-=sum2;	sum1/=2;
		cout<<C(sum1+n,sum1)<<endl;
	}
}