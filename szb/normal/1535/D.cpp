/*
 
*/ 
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
const ll N=4000010,mod=1e9+7;
char s[N];
ll L[N],R[N],ans[N],pos[N],dep[N],tot,n,k;
void Build(ll l,ll r,ll p){
	if (l==r){ans[p]=1;dep[p]=1;return;}
	ll mid=(l+r)>>1;
	Build(l,mid,p<<1);
	Build(mid+1,r,p<<1|1);
	dep[p]=dep[p<<1]+1;
}
void updata(ll p){
	if (s[pos[p]]=='0')		ans[p]=ans[p<<1];
	else if (s[pos[p]]=='1')ans[p]=ans[p<<1|1];
	else					ans[p]=ans[p<<1]+ans[p<<1|1]; 
}
void build(ll l,ll r,ll p,ll Dep){
	if (dep[p]==Dep){
		pos[p]=++tot;
		L[tot]=l;
		R[tot]=r;
		updata(p);
		return;
	}
	ll mid=(l+r)>>1;
	build(l,mid,p<<1,Dep);
	build(mid+1,r,p<<1|1,Dep); 
}
void change(ll l,ll r,ll p,ll s,ll t){
	if (l==s&&r==t){
		updata(p);
		return;
	}
	ll mid=(l+r)>>1;
	if(t<=mid)	change(l,mid,p<<1,s,t);
	else		change(mid+1,r,p<<1|1,s,t);
	updata(p);
}
int main(){
	k=read();
	scanf("%s",s+1);
	Build(1,(1<<k),1);
	For(i,2,k+1)
	build(1,(1<<k),1,i); 
	ll q=read();
	for(;q--;){
		ll pos=read(); char ch=getchar();
		s[pos]=ch;
//		cout<<pos<<' '<<L[pos]<<' '<<R[pos]<<' '<<ch<<endl;
		change(1,(1<<k),1,L[pos],R[pos]); 
		cout<<ans[1]<<endl;
	}
}
/*
2
6
*/