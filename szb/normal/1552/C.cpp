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
const ll N=1010,mod=31607;
ll a[N],x[N],y[N],mark[N],q[N];
ll n,fl,k;
int main(){
	for(ll T=read();T--;){
		n=read();	k=read(); 
		memset(mark,0,sizeof mark);
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		For(i,1,k)x[i]=read(),y[i]=read(),mark[x[i]]=mark[y[i]]=1;
		ll pos=1,sm=0;*q=0;
		For(i,1,2*n)if(!mark[i])q[++*q]=i;
                For(i,1,*q/2){
                    x[++k]=q[i];y[k]=q[i+*q/2];
                }
		For(i,1,n)if(x[i]>y[i])swap(x[i],y[i]);
		ll ans=0;
		For(i,1,n)For(j,1,n)ans+=x[i]<x[j]&&x[j]<y[i]&&y[i]<y[j];
		cout<<ans<<endl;
	}
}