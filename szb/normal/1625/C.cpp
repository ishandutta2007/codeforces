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
const ll N=400100,mod=1e9+7;
ll n,k,l,a[N],d[N],p[N],v[N],f[2][550][550];
int main(){ 
	n=read();	l=read();	k=read();
	For(i,1,n)d[i]=read(),p[i]=d[i]-d[i-1];
	For(i,1,n)v[i]=read();
	f[1][0][1]=0; 
	For(i,2,n){
		memset(f[i&1],60,sizeof f[i&1]); 
		ll most=min(i-1,k),pvz,now=i&1,nnow=now^1;
		For(j,0,most)For(cur,1,i-1){
			pvz=f[nnow][j][cur]+v[cur]*p[i];
			f[now][j][i]=min(pvz,f[now][j][i]);
			f[now][j+1][cur]=min(pvz,f[now][j+1][cur]);
		}
	}
	ll ans=1e18;
	For(j,0,k)For(cur,1,n){
		ans=min(ans,f[n&1][j][cur]+(l-d[n])*v[cur]);
	}
	cout<<ans<<endl;
}