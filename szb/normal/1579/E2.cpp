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
const ll N=200010,mod=1e9+7;
ll n,m,k,a[N],c[N],q[N],sum[N];
char s[N];
void add(ll x){
	for(;x<=n;x+=x&-x)c[x]++;
}
ll ask(ll x){
	ll ans=0;
	for(;x;x-=x&-x)ans+=c[x];
	return ans;
}
int main(){
	for(ll T=read();T--;){
		n=read();ll ans=0;
		For(i,1,n)a[i]=read(),q[i]=a[i],c[i]=sum[i]=0;
		sort(q+1,q+n+1);
		For(i,1,n)a[i]=lower_bound(q+1,q+n+1,a[i])-q;
		For(i,1,n){
			ll mn=ask(a[i]-1),mx=i-1-mn-sum[a[i]];
			
			ans+=min(mn,mx);
			
			sum[a[i]]++;
			add(a[i]);
			
		}
		cout<<ans<<endl;
	}
}