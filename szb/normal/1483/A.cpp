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
const ll N=1000010;
vector<ll>g[N];
ll n,m,sum[N],sum1[N],ans[N];
int main(){
	ll T=read();
	for(;T--;){
		n=read();	m=read();
		For(i,1,m)g[i].clear();
		For(i,1,n)sum[i]=0,sum1[i]=0;
		For(i,1,m){
			ll k=read();
			For(j,1,k){
				ll x=read();
				g[i].pb(x);
				if (k==1)
				++sum1[x];
			}
		}
		ll fl=1,id=0;
		For(i,1,n)if (sum1[i]>(m/2)+(m&1)){
			puts("NO");
			fl=0;
			break;
		}
		if (fl){
			puts("YES");
			For(i,1,m)ans[i]=g[i][0],++sum[g[i][0]];
			For(i,1,m)if ((sum[g[i][0]]>(m/2)+(m&1))&&(g[i].size()>1))
				ans[i]=g[i][1],--sum[g[i][0]];
			For(i,1,m)write(ans[i]),putchar(' ');puts("");
		}
	}
}