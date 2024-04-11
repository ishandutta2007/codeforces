#include<queue>
#include<ctime>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<memory.h>
#include<stack>
#include<map>
#include<ctime>
#include<algorithm>
#include<ctime>
#include<set>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define rep(i,j,k)	for(ll i=j;i<k;++i)
#define ld double
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=200010,mod=1e9+7;
struct dt{	ll u,l,r,s;	}a[N];
stack<ll>tr[277777];
ll h,w,n,v,f[N],ans;
bool cmp(dt a,dt b){	return a.u<b.u;	}
void change(ll l,ll r,ll p,ll s,ll t,ll v){
	if (l==s&&r==t)	return tr[p].push(v),void(0);
	ll mid=(l+r)>>1;
	if (t<=mid)	change(l,mid,p<<1,s,t,v);
	else if (s>mid)	change(mid+1,r,p<<1|1,s,t,v);
	else change(l,mid,p<<1,s,mid,v),change(mid+1,r,p<<1|1,mid+1,t,v);
}
void ask(ll l,ll r,ll p,ll pos,ll up){
	for(;!tr[p].empty();tr[p].pop()){
		ll x=tr[p].top();
		if (a[x].u+a[x].s>=up)	break;
	}
	if (!tr[p].empty()&&(v==-1||a[tr[p].top()].u>a[v].u))	v=tr[p].top();
	if (l==r)	return;	ll mid=(l+r)>>1;
	pos<=mid?ask(l,mid,p<<1,pos,up):ask(mid+1,r,p<<1|1,pos,up);
}
ll QQQ(ll up,ll pos){	v=-1;	ask(1,w,1,pos,up);	return v==-1?1:f[v];	}
int main(){
	h=read();	w=read();	n=read();
	For(i,1,n)	a[i].u=read(),a[i].l=read(),a[i].r=read(),a[i].s=read();
	sort(a+1,a+n+1,cmp);
	For(i,1,n){
		if (a[i].l==1)	f[i]=QQQ(a[i].u,a[i].r+1)*2%mod;
		else	if (a[i].r==w)	f[i]=QQQ(a[i].u,a[i].l-1)*2%mod;
		else	f[i]=(QQQ(a[i].u,a[i].l-1)+QQQ(a[i].u,a[i].r+1))%mod;
		change(1,w,1,a[i].l,a[i].r,i);
	}
	For(i,1,w)	ans=(ans+QQQ(h+1,i))%mod;
	writeln(ans);
}