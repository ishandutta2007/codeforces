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
ll a[N],n,ans,sumji,sum[N],b[N];
ll ppow(ll x,ll k){
	ll ans=1;
	for(;k;k>>=1,x=x*x%mod)if(k&1)ans=ans*x%mod;
	return ans; 
}
int main(){
	n=read();
	For(i,1,n){
		a[i]=read();
		if (a[i]&1)--i,--n,++sumji;
		else{
			For(j,1,40)if ((a[i]%(1ll<<j)==0)&&(a[i]%(1ll<<j+1)!=0))sum[j]++;
		}
	}
	ans+=(ppow(2,sumji)-1)*ppow(2,n)%mod;
	FOr(i,40,1)b[i]=(b[i+1]+sum[i]);
	For(i,1,40)if (sum[i])ans+=(ppow(2,sum[i]-1)-1)*ppow(2,b[i+1])%mod;
	ans%=mod;
	ans+=mod;
	ans%=mod;
	cout<<ans<<endl;
}
/*
1
0
2
1
3
3
4
7

5
103904 1032840 4142834 12391240 1000000000 
101952  516420 2071417  6190620  500000000
 
(2l+x-1)*x/2
2l*x (x-1)*x
x 3x 5x 7x 9x 11x 13x
y 3y 5y 7y 9y 11y 13y

2 2 2 %4==2 
2 2 4 %4==0 
%4==2 
*/