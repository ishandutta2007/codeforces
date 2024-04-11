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
const ll N=1600010,mod=998244353;
ll fac[N],inv[N],ans[N],siz[N],x[N],y[N],answ,n,m;
ll ppow(ll x,ll k){
	ll ans=1;
	for(;k;k>>=1,x=x*x%mod)if(k&1)ans=ans*x%mod;
	return ans; 
}
ll C(ll n,ll m){
	if (n<m)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll calc(ll n,ll m){
	return C(2*n-1-m,n);
}
void updata(ll p){
	siz[p]=siz[p<<1]+siz[p<<1|1];
	ans[p]=ans[p<<1]+ans[p<<1|1]; 
}
ll ask(ll l,ll r,ll p,ll pos){
	if (l==r)return l;
	ll mid=(l+r)>>1,u=mid-l+1-siz[p<<1];
	if (pos<=u)return ask(l,mid,p<<1,pos);
	else return ask(mid+1,r,p<<1|1,pos-u); 
}
void change(ll l,ll r,ll p,ll pos,ll v){
	if (l==r){
		if (v==1){
			if (ans[p]==0)ans[p]=1;
			siz[p]++;
		}else
			ans[p]=2;
		return;
	}
	ll mid=(l+r)>>1;
	pos<=mid?	change(l,mid,p<<1,pos,v):
				change(mid+1,r,p<<1|1,pos,v);
	updata(p); 
}
void dfs(ll l,ll r,ll p){
	if (l==r){
		answ+=ans[p]==1;
		siz[p]=ans[p]=0;
		return;
	}
	ll mid=(l+r)>>1;
	if (ans[p<<1])dfs(l,mid,p<<1);
	if (ans[p<<1|1])dfs(mid+1,r,p<<1|1);
	updata(p);
}
//m  < 
int main(){
	fac[0]=1;For(i,1,600000)fac[i]=fac[i-1]*i%mod;
	For(i,0,600000)inv[i]=ppow(fac[i],mod-2); 
	for(ll T=read();T--;){
		n=read();	m=read();
		ll cur=1;
		For(i,1,m){
			x[i]=read();y[i]=read();
		}
		FOr(i,m,1){
			ll pos=ask(1,n,1,y[i]);
			change(1,n,1,pos,1);
			if (y[i]>1){
				pos=ask(1,n,1,y[i]-1);
				change(1,n,1,pos,2);
			}
		}
		answ=0;
		dfs(1,n,1);
	//	cout<<answ<<endl;
		cout<<calc(n,answ)<<endl;
	}
}