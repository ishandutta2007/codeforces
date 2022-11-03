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
const ll N=1001000,mod=1e9+7;
char s1[N],s2[N];
ll n,T,f[N][2][2];
ll calc(ll a,ll b){
	if (a==0)return 0;
	else if (b==0)return 1;
	return 2;
}
int main(){
	T=read();
	for(;T--;){
		n=read();
		scanf("%s%s",s1+1,s2+1);
		f[0][0][0]=0;
		f[0][0][1]=f[0][1][0]=f[0][1][1]=-10000000;
		For(i,1,n){
			For(a,0,1)For(b,0,1)f[i][a][b]=-10000000;
			For(a,0,1)For(b,0,1){
				ll a1=a,b1=b;
				if (s1[i]=='0')a1=1;else b1=1;
				if (s2[i]=='0')a1=1;else b1=1;
				f[i][a1][b1]=max(f[i][a1][b1],f[i-1][a][b]);
			}
			For(a,0,1)For(b,0,1)f[i][0][0]=max(f[i][0][0],f[i][a][b]+calc(a,b));
		}
		cout<<f[n][0][0]<<endl;
	}
}