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
const ll N=300100;
char s[N];
ll n,a[N],b[N],m,ans;
bool cmp(ll a,ll b){return a>b;}
int main(){
	ll T=read();
	for(;T--;){
		n=read();	ans=0;
		For(i,1,n)a[i]=read();
		For(i,1,n)b[i]=read();
		sort(a+1,a+n+1);
		For(i,n+1,2*n)a[i]=100;
		sort(b+1,b+n+1,cmp);
		For(i,n+1,2*n)b[i]=0;
		ll l=1+n/4,r=n,ss=n-n/4;
		For(i,l,r)ans+=a[i];
		For(i,1,n-n/4)ans-=b[i];
		for(;ans<0;){
			++r;
			ll t=1+r/4;
			for(;l<t;){
				ans-=a[l];
				++l;
			}
			ans+=a[r];
			if (ss<r-r/4){
				ans-=b[++ss];
			}
		}
		cout<<r-n<<endl;
	}
}