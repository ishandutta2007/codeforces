#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define For(i,x,y) for(ll i =(x);i <= (y);++i)
#define FOr(i,x,y) for(ll i = (x);i >= (y);--i)
#define rep(i,x,y) for(ll i = (x);i < (y);++i)
#define mk make_pair
#define pb push_back
#define y1 y111111111111
#define Debug puts("@@@@@@@@@@@@@@@@")
#define fi first
#define se second
#define clr(a,b) memset(a,b,sizeof a)
#define cpy(a,b) memcpy(a,b,sizeof a)
#define pa pair<ll,ll>
 
inline ll read(){
	ll x = 0,f= 1;char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
void write(ll x){
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) write(x/10);
	putchar('0'+x%10);
}
const ll N=100010;
ll n,x,a[N];
int main(){
	srand(time(0));
	ll T=read();
	for(;T--;){
		n=read();x=read();ll sum=0;
		For(i,1,n)a[i]=read(),sum+=a[i];
		sort(a+1,a+n+1);
		if (sum==x){
			puts("NO");continue;
		}
		sum=0;
		For(i,1,n){
			sum+=a[i];
			if (sum==x)swap(a[i],a[n]);
		}
		puts("YES");
		For(i,1,n)write(a[i]),putchar(' ');puts("");
	}
}