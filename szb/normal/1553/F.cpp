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
const ll N=600010,mod=31607;
char s[N],t[N];
ll vis[N],mx[N],mn[N],p[N],a[N],b[N],c[N],c1[N],d[N],d1[N],e[N],sum[N],n,m;
vector<ll>ans;
void add(ll x){
	ll v=x;
	For(j,x/600+1,500){
		c1[j]++;
		d1[j]+=v;
	}
	ll up=(x/600+1)*600-1;
	For(j,x,up){
		c[j]++;
		d[j]+=v;
	}
}
inline ll ask1(ll x){
	return c1[x/600]+c[x];
}
inline ll ask2(ll x){
	return d1[x/600]+d[x];
}
inline ll query_num(ll l,ll r){
	if (l>300000ll)return 0;
	r=min(r,300000ll);
	return ask1(r)-ask1(l-1);
}
inline ll query_sum(ll l,ll r){
	if (l>300000ll)return 0;
	r=min(r,300000ll);
	return ask2(r)-ask2(l-1);
}
ll calc1(int x){
	ll ans=0;
	int l=1,r,t=min(590,x),p;
	for(;l<=t;l++){
		ans-=x/l*(d[l]-d[l-1]);
	}
	for(;l<=x;l=r+1){
		p=x/l;
		r=x/p;
		ans-=p*query_sum(l,r);
	}
	ans+=query_num(1,300000)*x;
//	cout<<ans<<endl;
	return ans;
}
ll calc2(ll x){
	if(x<=600)return e[x];
	else{
		ll ans=query_sum(0,x-1);
		for(ll y=x,t=1;y<=300000;y+=x,++t){
			ans+=query_sum(y,y+x-1)-query_num(y,y+x-1)*x*t;
//			cout<<y<<' '<<y+x-1<<' '<<query_sum(y,y+x-1)<<' '<<query_num(y,y+x-1)*x*t<<endl;
		}
//		cout<<ans<<endl;
		return ans;
	}
}
int main(){
	n=read();
	For(i,1,n)a[i]=read();
	ll ans=0;
	For(i,1,n){
		ans+=calc1(a[i]);
		ans+=calc2(a[i]); 
		add(a[i]);
		For(j,1,600)e[j]+=a[i]%j;
		write(ans);putchar(' ');
	}
}