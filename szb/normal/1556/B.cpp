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
const ll N=1600010,mod=998244353;
ll n,a[N],b[N],c[N],d[N],e[N];
ll calc(ll a[],ll b[]){
	ll ans=0;
	For(i,1,n)	d[i]=d[i-1]+a[i],
				e[i]=e[i-1]+b[i],
				ans+=abs(d[i]-e[i]);
	return ans;
}
int main(){
	for(ll T=read();T--;){
		n=read();ll sum0=0,sum1=0;
		For(i,1,n)a[i]=read()&1,sum0+=a[i]==0,sum1+=a[i]==1;
		For(i,1,n)b[i]=i&1,c[i]=1-(i&1); 
		if (n&1){
			if (sum0==n/2){
				cout<<calc(a,b)<<endl;
			}else if (sum1==n/2){
				cout<<calc(a,c)<<endl;
			}else puts("-1");
		}else{
			if (sum1==n/2){
				cout<<min(calc(a,b),calc(a,c))<<endl;
			}else puts("-1");
		}
	}
}