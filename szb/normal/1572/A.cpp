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
const ll N=1001000,mod=1e9+7;
vector<ll>g[N];
ll ans[N],q[N],sum[N],n;
int main(){
	for(ll T=read();T--;){
		n=read();
		For(i,1,n)g[i].clear(),sum[i]=ans[i]=0;
		For(i,1,n){
			ll k=read();
			rep(j,0,k)g[read()].pb(i),++sum[i]; 
		}
		ll he=0,ta=0;
		For(i,1,n)if(sum[i]==0)q[++ta]=i,ans[i]=1;
		for(;he!=ta;){
			ll x=q[++he];
			rep(i,0,g[x].size()){
				--sum[g[x][i]];
				if (g[x][i]>x)	ans[g[x][i]]=max(ans[g[x][i]],ans[x]);
				else			ans[g[x][i]]=max(ans[g[x][i]],ans[x]+1);
				if(sum[g[x][i]]==0){
					q[++ta]=g[x][i]; 
				}
			}
		}
		ll answ=0;
		if(ta!=n){
			puts("-1");
		}else{
			For(i,1,n)answ=max(answ,ans[i]);
			write(answ);puts(""); 
		}
	}
}