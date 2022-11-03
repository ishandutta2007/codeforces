#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
#define FOr(i,x,y)	for(ll i=(x);i>=(y);--i)
#define rep(i,x,y)	for(ll i=(x);i<(y);++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define fi	first
#define se	second
#define	pb	push_back
#define mk	make_pair
#define pa	pair<ll,ll>
#define y1	y11111111111111
#define debug	puts("@@@@@@@@@@@@@@@@@@@@@@@")
ll read(){
	ll x=0,f=1;	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)	putchar('-'),write(-x);
	else{
		if (x>=10)	write(x/10);
		putchar(x%10+'0');
	}
}
const ll N=1000000,mod=5201314;
ll len[N],mx[N],sum[N],mn[N],lazy[N],a[N],ans,yy,n,q;
void pushdown(ll p){
	if (lazy[p]){
		if (lazy[p]>=mx[p<<1]){
			mn[p<<1]=mx[p<<1]=lazy[p<<1]=lazy[p];
			sum[p<<1]=mx[p<<1]*len[p<<1];
		}
		if (lazy[p]>=mx[p<<1|1]){
			mn[p<<1|1]=mx[p<<1|1]=lazy[p<<1|1]=lazy[p];
			sum[p<<1|1]=mx[p<<1|1]*len[p<<1|1];
		}
	}
}
void updata(ll p){
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
void build(ll l,ll r,ll p){
	len[p]=r-l+1;
	if (l==r){
		sum[p]=mx[p]=mn[p]=a[l];
		return;
	}ll mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	updata(p);
}
void change(ll l,ll r,ll p,ll s,ll t,ll v){
	if (l==s&&r==t){
		if (mx[p]<=v){
			mx[p]=mn[p]=v;
			sum[p]=(r-l+1)*v;
			lazy[p]=v;
			return;
		}
		if (mn[p]>=v){
			return;
		}
		ll mid=(l+r)>>1;pushdown(p);
		change(l,mid,p<<1,s,mid,v);
		change(mid+1,r,p<<1|1,mid+1,t,v);
	}ll mid=(l+r)>>1;pushdown(p);
	if (t<=mid)change(l,mid,p<<1,s,t,v);
	else if (s>mid)change(mid+1,r,p<<1|1,s,t,v);
	else change(l,mid,p<<1,s,mid,v),change(mid+1,r,p<<1|1,mid+1,t,v);
	updata(p);
}
void query(ll l,ll r,ll p,ll s,ll t){
	if (l==s&&r==t){
//		cout<<l<<' '<<r<<' '<<s<<' '<<t<<' '<<ans<<' '<<yy<<' '<<mn[p]<<' '<<mx[p]<<endl;
		if (mn[p]>yy){
			return;
		}
		if (sum[p]<=yy){
			yy-=sum[p];
			ans+=r-l+1;
//			cout<<l<<' '<<r<<' '<<ans<<' '<<yy<<endl;
			return;
		}
		ll mid=(l+r)>>1;pushdown(p);
		query(l,mid,p<<1,s,mid);
		query(mid+1,r,p<<1|1,mid+1,t);
		updata(p);
		return;
	}ll mid=(l+r)>>1;pushdown(p);
	if (t<=mid)query(l,mid,p<<1,s,t);
	else if (s>mid)query(mid+1,r,p<<1|1,s,t);
	else query(l,mid,p<<1,s,mid),query(mid+1,r,p<<1|1,mid+1,t);
	updata(p);
}
int main(){
	n=read();q=read();
	For(i,1,n)a[i]=read();
	build(1,n,1);
	for(;q--;){
		ll opt=read(),x=read(),y=read();
		if (opt==1){
			change(1,n,1,1,x,y);
		}else{
			yy=y;ans=0;
			query(1,n,1,x,n);
			write(ans);puts("");
		}
	}
}
/*
3
5 9 4
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
10 15 3
1 2
2 3
3 4
4 5
5 1
1 7
2 8
3 9
4 10
5 6
7 10
10 8
8 6
6 9
9 7
4 5 4
1 2
2 3
3 4
4 1
1 3
*/