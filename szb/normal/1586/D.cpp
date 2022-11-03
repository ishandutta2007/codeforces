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
const ll N=4001000,mod=1e9+7;
ll n,a[N],ans[N];
ll que(){
	printf("? ");
	For(i,1,n)printf("%lld ",a[i]);
	puts("");
	fflush(stdout); 
	ll x=read();
	return x;
}
void fafa(){
	printf("! ");
	For(i,1,n)printf("%lld ",ans[i]);
	puts("");
	fflush(stdout); 
}
int main(){
	n=read();
	For(i,1,n)a[i]=1;
	ll mx=0;
	For(i,2,n){
		For(j,1,n-1)a[j]=1;
		a[n]=i;
		ll k=que();
		if (!k){
			ans[n]=n-i+2;
			break;
		}
	}
	if (!ans[n])ans[n]=1;
	For(i,1,n)if (i!=ans[n]){
		For(j,1,n-1)a[j]=ans[n];
		a[n]=i;
		ll k=que();
		ans[k]=i;
	}
	fafa();
}