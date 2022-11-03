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
#define pa pair<ll,ll>
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
const ll N=200010,mod=1e9+7;
char s[N];
ll ans,n,bin[N],bin1[N],cur[N],suc[N];
int main(){
	scanf("%s",s+1);	n=strlen(s+1);
	bin[0]=1;	bin1[0]=1;
	For(i,1,n)
		bin[i]=bin[i-1]*10%mod,
		bin1[i]=(bin[i]+bin1[i-1])%mod;
	For(i,1,n)
		cur[i]=(cur[i-1]*10+s[i]-'0')%mod;
	FOr(i,n,1)
		suc[i]=(suc[i+1]+bin[n-i]*(s[i]-'0'))%mod;
	For(i,1,n-1){
		ans=(ans+cur[i]*bin1[n-i-1])%mod;
	}
	For(i,1,n){
		ans=(ans+suc[i]*(i-1))%mod;
	}
	cout<<ans<<endl;
}