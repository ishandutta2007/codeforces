#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll int
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
#define pa pair<ll,ll>
#define y1 yyyyyyyyyyyyyyyyy
#define pb push_back
#define mk make_pair
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}
const ll N=4000010;
ll x[N],y[N],w[N],u[N],v[N],ls[N],rs[N],n,m,cnt,tr[N],rt[N];
void Max(ll &x,ll y){
	x=x<y?y:x;
}
ll query(ll l,ll r,ll p,ll s,ll t){
	if (s>t)return 0;
	if (l==s&&r==t)return tr[p];
	ll mid=(l+r)>>1;
	if (t<=mid)return query(l,mid,ls[p],s,t);
	else if(s>mid)return query(mid+1,r,rs[p],s,t);
	else return max(query(l,mid,ls[p],s,mid),query(mid+1,r,rs[p],mid+1,t));
}
void change(ll l,ll r,ll &p,ll pos,ll v){
	if (!p)p=++cnt;
	if (l==r){
		Max(tr[p],v);
		return;
	}
	ll mid=(l+r)>>1;
	pos<=mid?change(l,mid,ls[p],pos,v):change(mid+1,r,rs[p],pos,v);
	tr[p]=max(tr[ls[p]],tr[rs[p]]);
}
int main(){
	n=read();m=read();
	ll ans=0;
	For(i,1,m){
		ll x=read(),y=read(),w=read(),res=query(1,100010,rt[x],1,w)+1;
		change(1,100010,rt[y],w+1,res);
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}