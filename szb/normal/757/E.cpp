#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
#define FOr(i,x,y)	for(ll i=(x);i>=(y);--i)
#define rep(i,x,y)	for(ll i=(x);i<(y);++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define fi	first
#define se	second
#define	pb	push_back
#define mk	make_pair
#define pa	pair<ll,ll>
#define y1	y11111111111111
#define debug	puts("@@@@@@@@@@@@@@@@@@@@@@@")
ll read(){
	ll x=0,f=1;	char ch=getchar();
  	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
   	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';
   	return x*f;
}
void write(ll x){
   	if (x<0)	putchar('-'),write(-x);
   	else{
   		if (x>=10)	write(x/10);
   		putchar(x%10+'0');
   	}
}
const	ll N=1000200,mod=1e9+7;
ll ff[N],f[N][22],fac[N],inv[N],r,n;
ll ppow(ll x,ll k){
	ll ans=1;
	while(k){
		if (k&1)ans=ans*x%mod;
		x=x*x%mod;k>>=1;
	}return ans;
}
void init(ll n){
	For(i,2,n)if (!ff[i])for(ll j=i;j<=n;j+=i)++ff[j];
	For(i,1,n){
		f[i][1]=ppow(2,ff[i]);
		f[i][21]%=mod;
		For(k,2,21){
			f[i][k-1]%=mod;
			if (!f[i][k-1])break;
			for(ll j=i<<1;j<=n;j+=i)
			f[j][k]=f[j][k]+f[i][k-1];
		}
	}
	fac[0]=1;For(i,1,n)fac[i]=fac[i-1]*i%mod;
	inv[0]=1;For(i,1,n)inv[i]=inv[i-1]*ppow(i,mod-2)%mod;
}
ll C(ll n,ll m){
	if (m>n)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	init(1000100);
	for(ll q=read();q--;){
		r=read();	n=read();
		ll ans=0;
		For(i,1,21)	ans=(ans+f[n][i]*C(r,i-1))%mod;
		write(ans);puts("");
	}
}