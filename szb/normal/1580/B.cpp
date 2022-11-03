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
const ll N=128;
ll mod,n,m,k,c[N][N],f[N][N][N],h[N];
inline void Add(ll &x,ll y){x=(x+y)%mod;}
int main(){
	n=read();	m=read();	k=read();	mod=read();
	f[1][1][1]=1;
	c[0][0]=1;
	For(i,1,n){
		c[i][0]=1;
		For(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod; 
	}
	h[0]=h[1]=1;
	For(i,2,n)h[i]=h[i-1]*i%mod; 
	For(i,1,n)f[1][1][i]=h[i];
	For(i,1,m)f[i][0][0]=1; 
	For(dep,1,m-1)For(tot1,0,k)For(sum1,tot1,n)if (f[dep][tot1][sum1])For(tot2,0,k-tot1)For(sum2,tot2,n-sum1) if (f[dep][tot2][sum2])
		Add(f[dep+1][tot1+tot2][sum1+sum2+1],f[dep][tot1][sum1]*f[dep][tot2][sum2]%mod*c[sum1+sum2][sum1]%mod);
//	cout<<f[1][1][1]<<endl;
//	cout<<f[2][1][2]<<endl;
//	cout<<f[3][1][3]<<endl;
///	cout<<f[4][1][4]<<endl;
///	cout<<f[5][1][5]<<endl;
	write(f[m][k][n]);
}