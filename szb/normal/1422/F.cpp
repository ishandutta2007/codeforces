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
const ll N=40000010,mod=1e9+7;
ll cur[200010],mn[200010],a[200010];
int ls[N],rs[N],tr[N],rt[200010];
ll n,cnt,q;
void init(ll n){
	For(i,2,n)if (!mn[i])For(j,1,n/i)mn[i*j]=i; 
}
void build(ll l,ll r,int &p){
	p=++cnt;	tr[p]=1;
	if (l==r)return; 
	ll mid=(l+r)>>1;
	build(l,mid,ls[p]);
	build(mid+1,r,rs[p]); 
}
void change(ll l,ll r,ll s,ll t,int &p,ll v){
	++cnt;	ls[cnt]=ls[p];	rs[cnt]=rs[p];	tr[cnt]=tr[p];
	p=cnt;
	if (l==s&&r==t){
		tr[p]=1ll*tr[p]*v%mod;
		return;
	}
	ll mid=(l+r)>>1;
	if (t<=mid)change(l,mid,s,t,ls[p],v);
	else if(s>mid)change(mid+1,r,s,t,rs[p],v);
	else change(l,mid,s,mid,ls[p],v),change(mid+1,r,mid+1,t,rs[p],v); 
}
ll query(ll l,ll r,ll p,int pos){
	if (l==r)return tr[p];
	ll mid=(l+r)>>1;
	return pos<=mid?1ll*query(l,mid,ls[p],pos)*tr[p]%mod:
					1ll*query(mid+1,r,rs[p],pos)*tr[p]%mod;
}
int main(){
	init(200000);
	n=read();
	For(i,1,n)	a[i]=read();
	build(1,n,rt[0]);
	For(i,1,n){
		rt[i]=rt[i-1];
		ll x=a[i];
		for(;x!=1;){
			ll y=0,now=mn[x],nownow=1;
			for(;mn[x]==now;x/=now)++y;
			For(j,1,y){
				nownow=nownow*now;
				change(1,n,cur[nownow]+1,i,rt[i],now);
//				cout<<nownow<<' '<<cur[nownow]+1<<' '<<i<<endl;
				cur[nownow]=i; 
			}
		}
	}
	ll lastans=0;
	q=read();
	For(i,1,q){
		ll l=(read()+lastans)%n+1,r=(read()+lastans)%n+1;
		if (l>r)swap(l,r);
		lastans=query(1,n,rt[r],l);
		write(lastans);	puts(""); 
	}
}