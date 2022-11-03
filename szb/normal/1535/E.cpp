/*
 
*/ 
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define fi first
#define se second
#define pa pair<ll,ll>
#define pb push_back
#define y1 y11111111111111
#define debug puts("@@@@@@@@@@@@@@@@@@@")
 
#define cpy(a,b) memcpy(a,b,sizeof(b))
inline ll read()
{
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
 
void write(ll x)
{
	if(x < 0) putchar('-'), x= -x;
	if(x > 9)write(x/10);
	putchar(x%10+'0');
}
const ll N=300010,mod=1e9+7;
ll vis[N],fa[N][22],a[N],c[N],dep[N],n;
ll find(ll x,ll len){
	For(i,0,20)if (len>>i&1)x=fa[x][i];
	return x;
}
ll ask(ll x,ll w){
	ll y=x;
	FOr(i,20,0)if (!vis[fa[x][i]])x=fa[x][i];
	ll sum=0,ans=0;
	for(;;){
		ll now=min(a[x],w);
		w-=now;a[x]-=now;
		sum+=now;
		ans+=now*c[x];
		if (y==x||w==0)break;
		vis[x]=1;
		x=find(y,dep[y]-dep[x]-1);
	}
	write(sum);putchar(' ');write(ans);puts(""); 
}
int main(){
	ll q=read();	a[0]=read();	c[0]=read();
	For(i,1,q){
		ll opt=read();
		if (opt==1){
			fa[i][0]=read();	a[i]=read();	c[i]=read(); dep[i]=dep[fa[i][0]]+1;
			For(j,1,20)fa[i][j]=fa[fa[i][j-1]][j-1];
		}else{
			ll vi=read(),wi=read();
			ask(vi,wi);
			fflush(stdout);
		}
	}
}