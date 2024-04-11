#include<queue>
#include<ctime>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#include<ctime>
#include<set>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define rep(i,j,k)	for(ll i=j;i<k;++i)
#define ld double
#define fi first
#define se second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=400010,inf=1LL<<60;
ll tag[N],mn[N],sum[N],bin[100],n,Q;
void build(ll l,ll r,ll p){
	tag[p]=-inf;
	if (l==r){
		tag[p]=read();
		For(i,0,10)	if (bin[i]-tag[p]>=0)	return mn[p]=bin[i]-tag[p],void(0);
	}ll mid=(l+r)>>1;
	build(l,mid,p<<1);	build(mid+1,r,p<<1|1);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
void pushdown(ll p){
	if (sum[p]){	tag[p<<1]!=-inf?tag[p<<1]+=sum[p]:sum[p<<1]+=sum[p];	tag[p<<1|1]!=-inf?tag[p<<1|1]+=sum[p]:sum[p<<1|1]+=sum[p];	mn[p<<1]-=sum[p];	mn[p<<1|1]-=sum[p];	sum[p]=0;	}
	if (tag[p]!=-inf){	tag[p<<1]=tag[p<<1|1]=tag[p];	mn[p<<1]=mn[p<<1|1]=mn[p];	tag[p]=-inf;	sum[p<<1]=sum[p<<1|1]=0;	}
}
void cover(ll l,ll r,ll p,ll s,ll t,ll v){
	if (l==s&&r==t){
		tag[p]=v;	sum[p]=0;
		For(i,0,10)	if (bin[i]-tag[p]>=0)	return mn[p]=bin[i]-tag[p],void(0);
	}ll mid=(l+r)>>1;	pushdown(p);
	if (t<=mid)	cover(l,mid,p<<1,s,t,v);
	else if (s>mid)	cover(mid+1,r,p<<1|1,s,t,v);
	else cover(l,mid,p<<1,s,mid,v),cover(mid+1,r,p<<1|1,mid+1,t,v);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
bool add(ll l,ll r,ll p,ll s,ll t,ll v){
	if (l==s&&r==t){
		ll mid=(l+r)>>1,ans=0;
		mn[p]-=v;	if (tag[p]!=-inf)	tag[p]+=v;	else	sum[p]+=v;
		if (mn[p]>0)	return 0;
		if (tag[p]!=-inf)	For(i,0,10)	if (bin[i]-tag[p]>=0)	return mn[p]=bin[i]-tag[p],!mn[p];
		pushdown(p);
		if (mn[p<<1]<=0)	ans|=add(l,mid,p<<1,s,mid,0);
		if (mn[p<<1|1]<=0)	ans|=add(mid+1,r,p<<1|1,mid+1,t,0);
		mn[p]=min(mn[p<<1],mn[p<<1|1]);	return ans;
	}ll mid=(l+r)>>1,ans;	pushdown(p);
	if (t<=mid)	ans=add(l,mid,p<<1,s,t,v);
	else if (s>mid)	ans=add(mid+1,r,p<<1|1,s,t,v);
	else ans=add(l,mid,p<<1,s,mid,v)|add(mid+1,r,p<<1|1,mid+1,t,v);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
	return ans;
}
ll query(ll l,ll r,ll p,ll pos){
	if (l==r)	return tag[p];
	ll mid=(l+r)>>1;	pushdown(p);
	if (pos<=mid)	return query(l,mid,p<<1,pos);
	else	return query(mid+1,r,p<<1|1,pos);
}
int main(){
//	freopen("a.in","r",stdin);
	bin[0]=1;	For(i,1,10)	bin[i]=bin[i-1]*42;
	n=read();	Q=read();
	build(1,n,1);
	while(Q--){
		ll opt=read();
		if (opt==1)	writeln(query(1,n,1,read()));
		if (opt==2){	ll a=read(),b=read(),v=read();	cover(1,n,1,a,b,v);	}
		if (opt==3){	ll a=read(),b=read(),v=read();	while(add(1,n,1,a,b,v));	}
	}
}