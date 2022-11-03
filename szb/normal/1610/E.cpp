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
ll a[N],n,ans,sumji,sum[N],b[N],cur[N],f[N][50],mama[N];
int main(){
	for(ll T=read();T--;){
		n=read();
		For(i,1,n)a[i]=read(),f[i][1]=i;f[0][1]=0;
		For(i,1,n)mama[i]=a[i]==a[i-1]?(mama[i-1]+1):0; 
		ans=1;
		a[n+1]=1e18; 
		For(j,2,39){
			ll pos=1; 
			For(i,1,n+1)f[i][j]=0;
			For(i,1,n){
				f[i][j]=max(f[i][j],f[i-1][j]);
				if (f[i][j-1]){
					ll pos=lower_bound(a+1,a+n+2,2*a[i]-a[f[i][j-1]])-a;
					pos=max(pos,i+1);
					f[pos][j]=max(f[pos][j],f[i][j-1]);
					ans=max(ans,j-1+mama[f[i][j-1]]);
				}
			}
		}
		write(n-ans);puts(""); 
	}
}