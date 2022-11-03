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
const ll N=6010,mod=998244353;
bool f[N][N];
ll n,x[N],y[N],ans1,ans2,tot;
ll sum[2][2];
int main(){
	n=read();
	For(i,1,n)x[i]=read()/2,y[i]=read()/2;
	For(i,1,n){
		sum[0][0]=sum[0][1]=sum[1][0]=sum[1][1]=0;
		For(j,1,n)if(j!=i)++sum[abs(x[j]-x[i])&1][abs(y[j]-y[i])&1];
		ans1+=sum[1][0]*(sum[1][0]-1)/2;
		ans1+=sum[0][1]*(sum[0][1]-1)/2;
		ans1+=sum[1][1]*(sum[1][1]-1)/2;
		ans2+=sum[0][0]*(sum[0][0]-1)/2;
	}
	cout<<ans1+ans2/3<<endl;
}