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
vector<ll>g[N];
ll fa[N],dep[N],x[N],y[N],sum[N],n,m;
void dfs(ll x){
	rep(i,0,g[x].size()){
		ll to=g[x][i];
		if(!fa[to]){
			fa[to]=x;
			dep[to]=dep[x]+1;
			dfs(to);
		}
	}
}
ll lca(ll x,ll y){
	for(;x!=y;){
		if(dep[x]<dep[y])swap(x,y);
		x=fa[x]; 
	}
	return x;
}
vector<ll>res,rr;
void did(ll x,ll y){
	ll t=lca(x,y);
	res.clear();	rr.clear();
	for(res.pb(x);x!=t;)x=fa[x],res.pb(x);
	for(rr.pb(y);y!=t;)y=fa[y],rr.pb(y);
//	cout<<x<<' '<<y<<' '<<res[0]<<' '<<rr[0]<<endl;
	cout<<res.size()+rr.size()-1<<endl;
	rep(i,0,res.size())printf("%lld ",res[i]);
	for(int i=(int)(rr.size()-2);i>=0;--i)printf("%lld ",rr[i]);
	puts(""); 
}
int main(){
	n=read();	m=read();
	For(i,1,m){
		ll x=read(),y=read();
		g[x].pb(y);g[y].pb(x); 
	}
	fa[1]=10000000;dfs(1);
	m=read();
	For(i,1,m)x[i]=read(),y[i]=read(),sum[x[i]]^=1,sum[y[i]]^=1;
	ll tot=0;
	For(i,1,n)tot+=sum[i];
//	For(i,1,n)printf("%lld ",dep[i]); 
	if(tot){
		puts("NO");
		cout<<tot/2;
	}else{
		puts("YES"); 
		For(i,1,m){
			did(x[i],y[i]);
		}
	}
}