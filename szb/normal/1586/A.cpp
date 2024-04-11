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
ll n,m,fa[N],sz[N],a[N],mark[N];
char s[N];
void init(ll n){
	For(i,2,n)if(!mark[i])For(j,2,n/i)mark[i*j]=1;
}
void did(){
		n=read();
		For(i,1,n)a[i]=read();
		ll sum=0;
		For(i,1,n)sum+=a[i];
		if (mark[sum]){
			cout<<n<<endl;
			For(i,1,n)cout<<i<<' ';puts("");
			return;
		}
		For(i,1,n)if(mark[sum-a[i]]){
			cout<<n-1<<endl;
			For(j,1,n)if(j!=i)cout<<j<<' ';puts("");
			return;
		}
		For(i,1,n)For(j,i+1,n)if (mark[sum-a[i]-a[j]]){
			cout<<n-2<<endl;
			For(k,1,n)if(k!=i&&k!=j)cout<<k<<' ';puts("");
			return;
		}
		assert(0); 
}
int main(){
	init(30000);
	for(ll T=read();T--;){
		did();
	}
}