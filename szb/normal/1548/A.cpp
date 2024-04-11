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
const ll N=2000010,mod=998244353;
ll mx[N],n,m,ans,q;
int main(){
	n=read();	m=read();
	ans=n;
	For(i,1,m){
		ll x=read(),y=read();
		if (x>y)swap(x,y);
		ans-=mx[x]==0;
		mx[x]++;
	}
	q=read();
	For(i,1,q){
		ll opt=read();
		if(opt==1){
			ll x=read(),y=read();
			if (x>y)swap(x,y);
			ans-=mx[x]==0;
			mx[x]++;
		}else if (opt==2){
			ll x=read(),y=read();
			if (x>y)swap(x,y);
			ans+=mx[x]==1;
			mx[x]--;
		}else{
			cout<<ans<<endl;
		}
	}
}