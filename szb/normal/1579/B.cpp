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
	ll x;
	scanf("%lld",&x);
	return x;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
const ll N=1001000,mod=1e9+7;
struct dt{
	ll x,y,z;
};
vector<dt>ans;
ll n,a[N];
int main(){
	for(ll T=read();T--;){
		n=read();ans.clear();
		For(i,1,n)a[i]=read();
		For(i,1,n){
			ll pos=i;
			For(j,i,n)if (a[j]<a[pos])pos=j;
			if (pos!=i){
				ans.pb((dt){i,pos,pos-i}); 
			}
			ll tmp=a[pos];
			FOr(j,pos,i+1)a[j]=a[j-1];
			a[i]=a[pos];
		}
		cout<<ans.size()<<endl;
		rep(i,0,ans.size())write(ans[i].x),putchar(' '),write(ans[i].y),putchar(' '),write(ans[i].z),puts(""); 
	}
}
/*
2 4 1 3
2 1 3 4
2 3 1 4
1 2 3 4
*/