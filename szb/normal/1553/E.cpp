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
const ll N=600010,mod=31607;
char s[N],t[N];
ll vis[N],mx[N],mn[N],p[N],b[N],sum[N],n,m;
vector<ll>ans;
bool check(ll x){
	For(i,1,n)b[i]=(p[i]+n+n-1-x)%n+1,vis[i]=0;
	ll tot=0;
	For(i,1,n)if (!vis[i]){
		for(ll x=i;!vis[x];x=b[x]){
			vis[x]=1;
			++tot;
		}
		--tot;
	} 
	return tot<=m; 
}
int main(){
	for(ll T=read();T--;){
		n=read();	m=read();	ans.clear();
		For(i,1,n)	p[i]=read();
		For(i,1,n)	++sum[(p[i]-i+n)%n];
		For(i,0,n-1)if (sum[i]>=n-m*2){
			if (check(i)){
				ans.pb((n-i)%n); 
			}
		}
		sort(ans.begin(),ans.end());
		write(ans.size());putchar(' ');rep(i,0,ans.size())write(ans[i]),putchar(' ');puts(""); 
	}
}