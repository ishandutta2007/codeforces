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
const ll N=10010;
char s[N];
ll n,a[100][100],m;
void insert(ll x,ll y){
	For(i,-1,1)For(j,-1,1)a[x+i][y+j]=1;
	a[x][y]=2;
}
int main(){
	ll T=read();
	for(;T--;){
		n=read();	m=read();
		For(i,1,n)For(j,1,m)a[i][j]=0;
		For(i,1,n)if (!a[i][1])insert(i,1);
		For(i,2,m-1)if (!a[n][i])insert(n,i);
		For(i,1,n)if(!a[i][m])insert(i,m);
		FOr(i,m-1,2)if (!a[1][i])insert(1,i);
		For(i,1,n){For(j,1,m)putchar(a[i][j]==2?'1':'0');puts("");}
	}
}