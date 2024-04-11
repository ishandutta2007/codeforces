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
	ll x;
	scanf("%lld",&x);
	return x;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
const ll N=410,mod=1e9+7;
ll n,m,a[N][N],sum[N][N];
char s[N];
inline ll count(ll x1,ll y1,ll x2,ll y2,ll opt){
	return opt==1?(sum[x2][y2]+sum[x1-1][y1-1]-sum[x1-1][y2]-sum[x2][y1-1]):
				  ((x2-x1+1)*(y2-y1+1)-(sum[x2][y2]+sum[x1-1][y1-1]-sum[x1-1][y2]-sum[x2][y1-1]));
}
int main(){
	for(ll T=read();T--;){
		n=read();	m=read();	ll ans=n*m;
		For(i,1,n){
			scanf("%s",s+1);
			For(j,1,m)a[i][j]=s[j]-'0',	sum[i][j]=a[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
		}
		For(i,1,n-4)For(j,1,m-3)For(x,i+4,n)For(y,j+3,m){
			ll at_least_need=count(i+1,j,x-1,j,0)
							+count(i,j+1,i,y-1,0)
							+count(i+1,j+1,x-1,y-1,1);
//			cout<<i<<' '<<j<<' '<<x<<' '<<y<<' '<<at_least_need<<endl;
			if (at_least_need>=ans)break;
			at_least_need+=	count(i+1,y,x-1,y,0)
						   +count(x,j+1,x,y-1,0);
			ans=min(ans,at_least_need);
		}
		cout<<ans<<endl;
	}
}