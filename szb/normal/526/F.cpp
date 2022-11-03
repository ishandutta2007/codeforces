#include<queue>
#include<cstring>
#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<cmath>
#define pa pair<ll,ll>
#define ll long long
#define maxn 2000020
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
ll a[maxn],mx[maxn],mn[maxn],ans,cnt[maxn],n;
void solve(ll l,ll r){
	if (l==r)	return ++ans,void(0);
	ll mid=(l+r)>>1;	solve(l,mid);	solve(mid+1,r);
	mx[mid]=mn[mid]=a[mid];
	mx[mid+1]=mn[mid+1]=a[mid+1];
	FOr(i,mid-1,l)	mx[i]=max(mx[i+1],a[i]),mn[i]=min(mn[i+1],a[i]);
	For(i,mid+2,r)	mx[i]=max(mx[i-1],a[i]),mn[i]=min(mn[i-1],a[i]);
	For(i,l,mid){
		ll j=mx[i]-mn[i]+i;
		if (j<=mid||j>r||mx[j]>mx[i]||mn[j]<mn[i])	continue;
		++ans;
	}
	For(i,mid+1,r){
		ll j=mn[i]-mx[i]+i;
		if (j>mid||j<l||mx[j]>mx[i]||mn[j]<mn[i])	continue;
		++ans;
	}
	ll L=mid+1,R=mid+1;
	FOr(i,mid,l){
		while(mx[R]<mx[i]&&R<=r)	++cnt[mn[R]+R],++R;
		while(mn[L]>mn[i]&&L<=r)	--cnt[mn[L]+L],++L;
		if (R>L)	ans+=cnt[mx[i]+i];
	}
	while(R<=r)	++cnt[mn[R]+R],++R;
	while(L<=r)	--cnt[mn[L]+L],++L;
	L=R=mid;
	For(i,mid+1,r){
		while(mx[L]<mx[i]&&L>=l)	++cnt[mn[L]-L+n],--L;
		while(mn[R]>mn[i]&&R>=l)	--cnt[mn[R]-R+n],--R;
		if (R>L)	ans+=cnt[mx[i]-i+n];
	}
	while(L>=l) ++cnt[mn[L]-L+n],--L;
	while(R>=l) --cnt[mn[R]-R+n],--R;
}
int main(){
	n=read();
	For(i,1,n){	ll x=read(),y=read();a[x]=y;	}
	solve(1,n);
	writeln(ans);
}/*
5
2 1 5 3 4
*/