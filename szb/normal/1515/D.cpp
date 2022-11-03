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
const ll N=200010;
ll n,l,r,sum[N];
int main(){
	ll T=read();
	for(;T--;){
		n=read();	l=read();	r=read();
		For(i,1,n)sum[i]=0;
		For(i,1,l)sum[read()]--;
		For(i,1,r)sum[read()]++;
		ll ans=0,ans1=0;
		For(i,1,n){
			if (sum[i]>=2){
				ll change=max(0ll,min(r-l,sum[i]/2*2));
				sum[i]-=change;
				r-=change/2;
				l+=change/2;
				ans+=change/2;
			}
			if (sum[i]<=-2){
				ll change=max(0ll,min(l-r,(-sum[i])/2*2));
				sum[i]+=change;
				l-=change/2;
				r+=change/2;
				ans+=change/2;
			}
			ans1+=abs(sum[i]);
//		cout<<ans<<' '<<ans1<<endl;
			
		}
		ans+=abs(r-l)/2;
		ans+=ans1/2;
		write(ans);puts("");
	}
}