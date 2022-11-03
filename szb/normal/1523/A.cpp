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
const ll N=200010,mod=998244353;
ll a[N],b[N],n,m;
char s[N];
int main(){
	ll T=read();
	for(;T--;){
		n=read();	m=read();
		scanf("%s",s+1);
		a[n+1]=0;
		For(i,1,n)a[i]=s[i]-'0';
		m=min(m,n);
		For(j,1,m){
			For(i,1,n)b[i]=a[i]|(a[i-1]+a[i+1]==1);
			For(i,1,n)a[i]=b[i];
		}
		For(i,1,n)write(a[i]);puts("");
	}
}