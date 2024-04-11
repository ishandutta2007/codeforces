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
const ll N=1200010;
ll n,k;
ll calc(ll p){
	if (p==-1)return 1;
	else return 1ll<<(p); 
}
int main(){
	ll T=read();
	for(;T--;){
		n=read();	k=read();
		For(i,1,n-62)	write(i),putchar(' ');
		ll m=max(n-62,0ll);	n-=m;
		if (k>(1ll<<(n-1))){
			puts("-1");
			continue;
		}
		For(i,1,n){
			For(j,i,n){
				ll now=calc(n-j-1);
//				cout<<now<<' '<<n-j-1<<' '<<k<<endl;
				if (now<k){
					k-=now;
				}else{
					For(l,i,j)write(i+j-l+m),putchar(' ');
					i=j;
					break;
				}
			}
		}
		puts("");
	}
}
/*
5
3 3
1 2 3
1 3 2
2 1 3
3 2 1
*/