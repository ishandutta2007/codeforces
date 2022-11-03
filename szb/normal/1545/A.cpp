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
const ll N=200010;
ll n,a[N],b[N],sum[N][2];
int main(){
	ll T=read();
	for(;T--;){
		memset(sum,0,sizeof sum);
		n=read();
		For(i,1,n){
			a[i]=read();
			++sum[a[i]][i&1]; 
		}
		sort(a+1,a+n+1);
		For(i,1,n){
			--sum[a[i]][i&1];
		}
		bool fl=1;
		For(i,1,100000)	fl&=sum[i][0]==0,
						fl&=sum[i][1]==0;
		if (fl)puts("YES");
		else	puts("NO");
	}
}