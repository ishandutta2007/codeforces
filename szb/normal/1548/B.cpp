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
#define pa pair<long double,ll>
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
const ll N=400010,mod=998244353;
ll mx[N],n,m,ans,q,a[N],b[N][22],cur[N];
ll calc(ll len){
	if (len==1)return 1;
	if (len==2){
		For(i,1,n-1)if (b[i][0]!=1)return 1;
		return 0;
	}
	For(i,1,n-len+1){
		ll w=cur[len-1],t=__gcd(b[i][w],b[i+len-(1<<w)-1][w]);
		if (t!=1)return 1;
	}
	return 0;
}
int main(){
//	freopen("mk.in","r",stdin);
//	freopen("std.out","w",stdout);
	cur[1]=0;
	For(i,2,200000)cur[i]=cur[i>>1]+1; 
	ll T=read();
	for(;T--;){
		n=read();
		For(i,1,n)a[i]=read();
		For(i,1,n-1)b[i][0]=abs(a[i+1]-a[i]);
		For(t,1,20)
		For(i,1,n-(1<<t-1)-1)b[i][t]=__gcd(b[i][t-1],b[i+(1<<t-1)][t-1]);
		ll l=1,r=n,ans=1;
		for(;l<=r;){
			ll mid=(l+r)>>1;
			if (calc(mid))l=mid+1,ans=mid;
			else r=mid-1; 
		}
		cout<<ans<<endl;
	}
}