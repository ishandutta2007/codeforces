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
const ll N=410;
ll f[N][N],g[N],h[N],c[N][N],u[N][N],n,mod;
void Add(ll &x,ll y){
	x=(x+y)%mod;
}
int main(){
	n=read();	mod=read();
	c[0][0]=1;
	For(i,1,n){
		c[i][0]=1;
		For(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	For(i,0,n)For(j,0,n){
		if (i==0||j==0)u[i][j]=1;
		else u[i][j]=(u[i-1][j]+u[i][j-1])%mod;
	}
	For(i,1,n){
		For(j,0,i-1)h[i]=(h[i]+u[j][i-j-1])%mod;
	}
	f[0][0]=1;
	For(i,0,n)For(j,0,i)if (f[i][j])For(k,(i==0?1:2),n-i){
		ll bei=0;
		if (i==0)bei=k;
		else     bei=k-1;
//		cout<<i+k<<' '<<j+bei<<' '<<i<<' '<<j<<' '<<f[i][j]*h[bei]%mod*c[j+bei][j]<<endl;
		Add(f[i+k][j+bei],f[i][j]*h[bei]%mod*c[j+bei][j]);
	}
	ll ans=0;
	For(i,1,n)ans=(ans+f[n][i])%mod;
	write(ans);
}