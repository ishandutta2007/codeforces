#include<queue>
#include<set>
#include<map>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long
#define mk make_pair
#define rep(i,x,y)  for(i=x;i<=y;++i)
#define dep(i,x,y)	for(i=x;i>=y;--i)
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll N=400010;
ll pre[N],nxt[N],tr[N],n,a[N],b[N],pos[N],ans;
void change(ll l,ll r,ll p,ll v){
	if (l==r)	return tr[p]=1,void(0);
	ll mid=(l+r)>>1;
	v<=mid?change(l,mid,p<<1,v):change(mid+1,r,p<<1|1,v);
	tr[p]=1;
}
void clear(ll l,ll r,ll p,ll s,ll t){
	if (l==s&&r==t){
		if (l==r)	return tr[p]=0,void(0);
		ll mid=(l+r)>>1;
		if (tr[p<<1])	clear(l,mid,p<<1,s,mid);
		if (tr[p<<1|1])	clear(mid+1,r,p<<1|1,mid+1,t);
		tr[p]=0;	return;
	}ll mid=(l+r)>>1;
	if (t<=mid)	clear(l,mid,p<<1,s,t);
	else if (s>mid)	clear(mid+1,r,p<<1|1,s,t);
	else clear(l,mid,p<<1,s,mid),clear(mid+1,r,p<<1|1,mid+1,t);
	tr[p]=tr[p<<1]|tr[p<<1|1];
}
ll query(ll l,ll r,ll p,ll s,ll t){
	if (l==s&&r==t)	return tr[p];
	ll mid=(l+r)>>1;
	if (t<=mid)	return query(l,mid,p<<1,s,mid);
	else if (s>mid)	return query(mid+1,r,p<<1|1,mid+1,t);
	else return query(l,mid,p<<1,s,mid)+query(mid+1,r,p<<1|1,mid+1,t); 
}
bool calc(ll x){
	memset(tr,0,sizeof tr);
	if (x<abs(a[2]-a[1]))	return 0;
	bool fl=0;
	if (abs(a[3]-a[1])<=x)	change(1,n,1,pos[1]),fl=1;
	if (abs(a[3]-a[2])<=x)	change(1,n,1,pos[2]),fl=1;
	if (!fl)	return 0;
	pre[0]=0;	nxt[n+1]=n+1;
	For(i,1,n){	pre[i]=pre[i-1];	while(b[i]-b[pre[i]]>x)	pre[i]++;	}
	FOr(i,n,1){	nxt[i]=nxt[i+1];	while(b[nxt[i]]-b[i]>x)	nxt[i]--;	}
	For(i,4,n){
		ll L=pre[pos[i]],R=nxt[pos[i]];
		fl=(abs(a[i-1]-a[i])<=x)&&fl;
		if (L>1)	clear(1,n,1,1,L-1);
		if (R<n)	clear(1,n,1,R+1,n);
		if (fl)	change(1,n,1,pos[i-1]);
		fl=tr[1];
	}return tr[1];
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();	a[1]=read();	a[2]=read();	n+=2;
	For(i,3,n)	a[i]=read();
	For(i,1,n)	b[i]=a[i];
	sort(b+1,b+n+1);
	b[0]=-1e9-1;
	b[n+1]=2e9+1;
	For(i,1,n)	pos[i]=lower_bound(b+1,b+n+1,a[i])-b;
	ll l=0,r=1e9;
	while(l<=r){
		ll mid=(l+r)>>1;
		if (calc(mid))	r=mid-1,ans=mid;
		else	l=mid+1;
	}writeln(ans);
}
/*

*/