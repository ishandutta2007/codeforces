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
const ll N=100010,mod=31607;
char s[N],t[N];
ll mx[N],mn[N],n,m;
int main(){
	for(ll T=read();T--;){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);m=strlen(t+1);
		t[0]=t[m+1]='?';
		For(i,1,n){
			mx[i]=0;
			For(j,i,n){
				if (t[j-i+1]==s[j]){
					mx[i]=j;
				}else break;
			}
		}
		For(i,1,n){
			mn[i]=0;
			For(j,i,n){
				if (t[m-(j-i)]==s[j]){
					mn[i]=j;
				}else break;
			}
		}
		bool ans=0;
		For(i,1,n)For(j,i,n){
			ll len=j-i+1;len=m-len;
			if (j-len>=1&&j-len<=n&&mx[i]>=j&&mn[j-len]>=j){
				ans=1;
			}
		}
		if (ans)puts("YES");
		else puts("NO");
	}
}