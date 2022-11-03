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
const ll N=5000010,mod=1e9+7;
ll t,n,x,y;
ll f[N];
vector<ll> ans;
void calc(ll n,ll m){
	For(i,0,n)if (x-i>=0&&x-i<=m)	f[n+x-i*2]=1;
}
int main(){
	for(ll T=read();T--;){
		x=read();;y=read();n=x+y;	ans.clear();
		For(i,0,n)f[i]=0;
		if (n&1)	calc(n/2+1,n/2),calc(n/2,n/2+1);
		else           calc(n/2,n/2);
		For(i,0,n)if (f[i])ans.pb(i);
		cout<<ans.size()<<endl;
		rep(i,0,ans.size())cout<<ans[i]<<' ';
		puts("");
	}
}