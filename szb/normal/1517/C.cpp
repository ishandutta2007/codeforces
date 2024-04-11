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
#define pa pair<ll,ll>
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
const ll N=510;
ll n,p[N],a[N][N];
int main(){
	n=read();	
	For(i,1,n)p[i]=read();
	For(i,1,n){
		ll x=i,y=i;
		For(j,1,p[i]){
			a[x][y]=p[i];
			if(!a[x][y-1]&&(y>1))--y;
			else{
				++x;
			}
		}
	}
	For(i,1,n){
		For(j,1,i)write(a[i][j]),putchar(' ');puts("");
	}
}
/*
6
67
675
6754
67548
6
*/