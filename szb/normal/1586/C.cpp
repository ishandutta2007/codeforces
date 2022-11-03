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
ll n,m,a[N],mark[N],sum[N],tr[N],now[N],ans[N];
char s[N],t[N];
int main(){
	n=read();m=read();
	scanf("%s",s+1);
	For(i,2,n){
		scanf("%s",t+1); 
		For(j,2,m)if (t[j-1]=='X'&&s[j]=='X'){
			ans[j]=1;
		}
		For(j,1,m)s[j]=t[j];
	}
	For(j,1,m)ans[j]+=ans[j-1];
	for(ll T=read();T--;){
		ll x=read(),y=read();
		puts(ans[x]==ans[y]?"YES":"NO");
	}
}