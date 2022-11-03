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
const ll N=1600010,mod=998244353;
struct dt{
	ll fi,se,tim;
}tr[N];
ll n,q,a[N],c[N];
dt merge(dt a,dt b){
	dt ans;
	ans.fi=a.fi+b.fi;
	ans.se=max(a.se,a.fi+b.se); 
	ans.tim=min(a.tim,a.fi+b.tim);
	return ans;
}
void build(ll l,ll r,ll p){
	if (l==r){
		tr[p].fi=a[l];
		tr[p].se=a[l];
		tr[p].tim=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	tr[p]=merge(tr[p<<1],tr[p<<1|1]);
}
dt query(ll l,ll r,ll p,ll s,ll t){
	if (l==s&&r==t)return tr[p];
	ll mid=(l+r)>>1;
	if (t<=mid)return query(l,mid,p<<1,s,t);
	else if (s>mid)return query(mid+1,r,p<<1|1,s,t);
	else return merge(query(l,mid,p<<1,s,mid),query(mid+1,r,p<<1|1,mid+1,t)); 
}
int main(){
	n=read();	q=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	a[i]-=read();
	build(1,n,1);
	for(;q--;){
		ll l=read(),r=read();
		dt res=query(1,n,1,l,r);
		if (res.fi!=0||res.se>0)puts("-1");
		else cout<<-res.tim<<endl;
	}
}
/*
*/