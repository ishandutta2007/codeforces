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
vector<ll>g[N],ans;
ll no_son[N],no_son_son[N],fa[N],del[N],n,m,T;
void dfs(ll x){
	no_son[x]=1,no_son_son[x]=1;
	ll sum_son=0;
	rep(i,0,g[x].size()){
		if (fa[x]==g[x][i])continue;
		fa[g[x][i]]=x;
		dfs(g[x][i]);
		if(!del[g[x][i]]){
			++sum_son;
			no_son[x]=0;
			no_son_son[x]&=no_son[g[x][i]];
		}
	}
	if (!no_son[x]&&no_son_son[x]&&x!=1){
		ans.pb(sum_son);
		del[x]=1;
		rep(i,0,g[x].size())if (fa[g[x][i]]==x)del[g[x][i]]=1;
	}
}
int main(){
	T=read();
	for(;T--;){
		n=read();ans.clear();
		For(i,1,n)no_son[i]=no_son_son[i]=fa[i]=del[i]=0,g[i].clear();
		For(i,2,n){
			ll x=read(),y=read();
			g[x].pb(y);g[y].pb(x);
		}
		dfs(1);
		ll res=0,answ=0;
		For(i,1,n)if (!del[i])++res;
		if (res==1){
			rep(i,0,ans.size())answ+=ans[i]-1;
			answ++;
		}else{
			rep(i,0,ans.size())answ+=ans[i]-1;
			For(i,1,n)if (!del[i]&&i!=1){
				++answ;
			}
		}cout<<answ<<endl;
	}
}