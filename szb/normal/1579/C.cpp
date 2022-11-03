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
const ll N=50,mod=1e9+7;
ll n,m,k,a[N][N],b[N][N];
char s[N];
int main(){
	for(ll T=read();T--;){
		n=read();	m=read();	k=read();
		bool fl=1;
		For(i,0,49)For(j,0,49)a[i][j]=b[i][j]=0;
		For(i,1,n){
			scanf("%s",s+1);
			For(j,1,m)a[i][j]=s[j]=='*';
		}
		For(i,k,n)For(j,k,m-k+1){
			int fll=1;
			For(l,0,k)	fll&=a[i-l][j+l],
						fll&=a[i-l][j-l];
			if (fll){
				int l=0; 
				for(;;){
					if(!a[i-l][j+l]||!a[i-l][j-l])break; 
					b[i-l][j+l]=1;
					b[i-l][j-l]=1;
					l++;
				}
			}
		}
		For(i,1,n)For(j,1,m)fl&=a[i][j]==b[i][j];
		if (fl)puts("YES");
		else	puts("NO");
	}
}