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
const ll N=1001000,mod=1e9+7;
multiset<ll>s;
pa p[N];
ll mark[N],f[N][3],a[N],n,m,pos;
bool operator <(pa a,pa b){
	return a.fi==b.fi?a.se<b.se:a.fi<b.fi;
}
ll calc(ll pos,ll l,ll r){
	ll ans=0;
	For(i,1,m)if (p[i].fi>=l&&p[i].se<=r)ans=max(ans,min(abs(p[i].fi-pos),abs(p[i].se-pos)));
	return ans;
}
ll cal(ll inf1,ll inf2,ll l,ll r){
	for(;p[pos].fi<l;)++pos;
	ll ans=1e17;
	ll pos1=pos;
	for(;pos1<m&&p[pos1+1].fi<=r;)++pos1;
	ll cnt=0;
	For(i,pos,pos1)if (p[i].fi>l&&p[i].se<r)mark[i]=1,++cnt;
	if (cnt==0)return 0;
	For(i,pos,pos1)if (mark[i])s.insert(p[i].se);
	ans=inf2*(r-*s.begin());
	For(i,pos,pos1)if (mark[i]){
		s.erase(s.lower_bound(p[i].se)); 
		--cnt;
		if (cnt==0)	ans=min(ans,inf1*(p[i].fi-l));
		else		ans=min(ans,inf1*(p[i].fi-l)+inf2*(r-*s.begin()));
		mark[i]=0; 
	}
	return ans;
}
int main(){
	ll T=read();
	for(;T--;){
		n=read();	m=read();
		For(i,1,n)a[i]=read();sort(a+1,a+n+1);
		For(i,1,m)p[i].fi=read(),p[i].se=read(); 
		sort(p+1,p+m+1);
		p[m+1].fi=p[m+1].se=1e17;
		a[0]=-1e17;
		a[n+1]=1e17;
		pos=1;
		For(i,1,n){
			f[i][1]=min(cal(1,2,a[i-1],a[i])+f[i-1][1],
						cal(2,2,a[i-1],a[i])+f[i-1][2]); 
			f[i][2]=min(cal(1,1,a[i-1],a[i])+f[i-1][1],
						cal(2,1,a[i-1],a[i])+f[i-1][2]);
		}
		ll ans=min(f[n][1]+calc(a[n],a[n],1e17),f[n][2]+calc(a[n],a[n],1e17)*2);
		cout<<ans<<endl;
	}
}