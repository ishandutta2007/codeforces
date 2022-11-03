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
ll a[N],b[N],n,m,tot;
char s[N];
void print(){
	For(i,1,tot){
		write(b[i]);
		if (i!=tot)putchar('.'); 
	}
	puts("");
}
int main(){
	ll T=read();
	for(;T--;){
		n=read();
		For(i,1,n)a[i]=read();
		b[1]=1;tot=1;
		print();
		For(i,2,n){
			if (a[i]==a[i-1]+1){
				++b[tot];
			}else if (a[i]==1){
				++tot;
				b[tot]=1;
			}else{
				for(;(tot>1&&b[tot]+1!=a[i]);--tot);
				if (tot==1&&b[tot]+1!=a[i])assert(0);
				++b[tot];
			}
			print();
		}
	}
}
/*
4
1 1 2 3

1 1 1 2 2 1 2 1 2
*/