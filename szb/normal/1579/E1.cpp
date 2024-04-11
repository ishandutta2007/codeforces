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
const ll N=1001000,mod=1e9+7;
ll n,a[N],ans[N],pos[N],vis[N];
int main(){
	for(ll T=read();T--;){
		n=read();
		For(i,1,n)a[i]=read(),pos[a[i]]=i,vis[i]=0;
		ll cur=n+1,l=1,r=n;
		For(i,1,n){
			if (pos[i]<cur){
				vis[i]=1;
				ans[l++]=i;
				cur=pos[i];
			}
		}
		FOr(i,n,1)if(!vis[a[i]]){
			vis[a[i]]=1;
			ans[r--]=a[i];
		}
		For(i,1,n)write(ans[i]),putchar(' ');puts("");
	}
}