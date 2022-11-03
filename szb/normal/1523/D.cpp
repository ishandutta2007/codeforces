#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define fi first
#define se second
#define pa pair<ll,ll>
#define pb push_back
#define y1 y11111111111111
#define debug puts("@@@@@@@@@@@@@@@@@@@")
 
#define cpy(a,b) memcpy(a,b,sizeof(b))
inline ll read()
{
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
 
void write(ll x)
{
	if(x < 0) putchar('-'), x= -x;
	if(x > 9)write(x/10);
	putchar(x%10+'0');
}
const ll N=200010,mod=998244353;
char s[100];
ll f[N],S,a[200010],cunt[1000010],g[1000010],num[100],pos[100],n,m,p;
int main(){
	srand(time(0)); 
	n=read();	m=read();	p=read();
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m)f[i]|=1ll*(s[j]-'0')<<(j);
	}
	ll ans=0,S1=0;
	For(i,1,1000000)cunt[i]=cunt[i-(i&(-i))]+1; 
	For(tim,1,20){
		ll x=f[(rand()<<15|rand())%n+1];
		ll tot=0;
		For(j,1,m)if (x>>j&1)pos[tot]=j,num[j]=tot++;
		rep(i,0,(1<<tot))g[i]=0;
		For(i,1,n){
			ll S=0;
			For(j,1,m)if ((x>>j&1)&&(f[i]>>j&1)){
				S|=1ll<<num[j];
			}
//			cout<<x<<' '<<S<<endl;
			++g[S]; 
		}
		rep(j,0,tot)rep(i,0,(1<<tot))if (i>>j&1){
			g[i^(1<<j)]+=g[i];
		}
		rep(i,0,(1<<tot)){
			if (g[i]>=(n/2+(n&1))){ 
				if (cunt[i]>ans){
/*				cout<<tot<<endl;
				cout<<x<<endl;
				cout<<i<<endl;
				For(j,0,tot-1)cout<<pos[j]<<' ';puts("");
*/
					ans=cunt[i];
					S1=0;
					For(j,0,tot-1)if (i>>j&1){
						S1|=1ll<<pos[j];
					}
				}
			}
		}
	}
	For(i,1,m)if (S1>>i&1)	putchar('1');
	else						putchar('0');
}
/*
5 40 2
1000000000000000000000000000000000000001
1000000000000000000000000000000000000001
1000000000000000000000000000000000000001
1000000000000000000000000000000000000001
1000000000000000000000000000000000000001
*/