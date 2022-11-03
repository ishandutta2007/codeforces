
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
const ll N=400010;
vector<ll>g[N];
ll l[N],r[N],f[N][2],vis[N],ans,n;
void dfs(ll x){
	vis[x]=1;
	f[x][0]=f[x][1]=0;
	rep(i,0,g[x].size()){
		ll to=g[x][i];
		if (!vis[to]){
			dfs(to);
			f[x][0]=f[x][0]+max(f[to][0]+abs(l[x]-l[to]),f[to][1]+abs(l[x]-r[to]));
			f[x][1]=f[x][1]+max(f[to][0]+abs(r[x]-l[to]),f[to][1]+abs(r[x]-r[to]));
		}
	}
	
}
int main(){
	ll T=read();
	for(;T--;){
		n=read();	ans=0;
		For(i,1,n)g[i].clear(),vis[i]=0;
		For(i,1,n)l[i]=read(),r[i]=read();
		For(i,2,n){
			ll x=read(),y=read();
			g[x].pb(y);g[y].pb(x);
		}
		dfs(1);
		cout<<max(f[1][0],f[1][1])<<endl;
	}
}