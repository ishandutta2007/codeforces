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
const ll N=1000010,mod=1e9+7;
char s[N];
ll n,a[N],A,B,xianA,xianB;
vector<ll>ans;
ll find(ll x){
	ll ans=0;
	For(i,1,n)if (a[i]==x)ans=i;
	return ans;
}
int main(){
	for(ll T=read();T--;){
		n=read();	bool fl=1;ans.clear();
		For(i,1,n){
			a[i]=read();
			fl&=(a[i]&1)==(i&1);
		}
		if(!fl)puts("-1");
		else{ 
			for(ll i=n;i>=3;i-=2){
				ll p;
				p=find(i);
				if (p>0&&p!=1)ans.pb(p), 
				reverse(a+1,a+p+1);
				p=find(i-1)-1;
				if (p>0&&p!=1)ans.pb(p), 
				reverse(a+1,a+p+1);
				p=find(i-1)+1;
				if (p>0&&p!=1)ans.pb(p), 
				reverse(a+1,a+p+1);
				p=find(i);
				if (p>0&&p!=1)ans.pb(p),
				reverse(a+1,a+p+1);
				ans.pb(i);
				reverse(a+1,a+i+1);
			}
		cout<<ans.size()<<endl; 
		rep(i,0,ans.size())write(ans[i]),putchar(' ');puts("");
		}
	}
}