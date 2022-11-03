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
	ll x;
	scanf("%lld",&x);
	return x;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
const ll N=1000010,mod=1e9+7;
ll n,m,k,a[N],c[N],q[N],sum[N],vis[N],d;
int main(){
	for(ll T=read();T--;){
		n=read();	d=read();
		For(i,1,n)a[i]=read(),vis[i]=0;
		ll ans=0; 
		For(i,1,n)if(!vis[i]){
			bool fl=1;ll clk=0;
			for(ll j=i;vis[j]!=1;j=(j+d-1)%n+1){
				fl&=a[j],vis[j]=1;
				if(a[j])++clk;
				else clk=0;
				ans=max(ans,clk);
			}
			for(ll j=i;vis[j]!=2;j=(j+d-1)%n+1){
				fl&=a[j],vis[j]=2;
				if(a[j])++clk;
				else clk=0;
				ans=max(ans,clk);
			}
			if(fl)	ans=1e18;
			else	ans=max(ans,clk);
		}
		if(ans==1e18)puts("-1");
		else	cout<<ans<<endl;
	}
}