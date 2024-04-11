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
priority_queue<pa>q; 
vector<pa>ans;
ll n,a[N];
int main(){
	for(ll T=read();T--;){
		n=read();ans.clear();
		For(i,1,n){
			a[i]=read();
			if (a[i])q.push(mk(a[i],i));
		}
		for(;!q.empty();){
			ll x1=q.top().fi,y1=q.top().se;
			q.pop();
			if (q.empty())break;
			ll x2=q.top().fi,y2=q.top().se;
			q.pop();
			x1--;
			x2--;
			if (x1)q.push(mk(x1,y1));
			if (x2)q.push(mk(x2,y2));
			ans.pb(mk(y1,y2));
		}
		cout<<ans.size()<<endl;
		rep(i,0,ans.size())write(min(ans[i].fi,ans[i].se)),putchar(' '),write(max(ans[i].fi,ans[i].se)),puts("");
	}
}