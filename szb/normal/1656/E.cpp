#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll int
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
const int N=200010;
vector<int>g[N];
int f[N],vis[N],n;
void dfs(ll x,ll ff){
	vis[x]=1;	f[x]=(ff==1)?(1+g[x].size()):(1-g[x].size()*2);
	rep(i,0,g[x].size()){
		if (!vis[g[x][i]])
			dfs(g[x][i],-ff);
	}
}
int main(){
	for(ll T=read();T--;){
		n=read();
		For(i,2,n){
			int x=read(),y=read();
			g[x].pb(y);g[y].pb(x);
		}
		int mx=1;
		For(i,1,n)mx=g[mx].size()>g[i].size()?mx:i;
		dfs(mx,1);
		For(i,1,n)cout<<f[i]<<' ';puts("");
		For(i,1,n)g[i].clear(),vis[i]=0;
	}
}