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
		n=read();
		For(i,1,n)a[i]=read();
		cout<<n*3<<endl;
		For(i,1,n/2){
			ll x=i*2-1,y=i*2;
			cout<<1<<' '<<x<<' '<<y<<endl;
			cout<<2<<' '<<x<<' '<<y<<endl;
			cout<<1<<' '<<x<<' '<<y<<endl;
			cout<<1<<' '<<x<<' '<<y<<endl;
			cout<<2<<' '<<x<<' '<<y<<endl;
			cout<<1<<' '<<x<<' '<<y<<endl;
		}
	}
}
/*
a	b

*/