#include<ctime>
#include<algorithm>
#include<cstdio>
#include<set>
#include<memory.h>
#include<queue>
#include<cmath>
using namespace std;
#define ll int
#define maxn 300010
#define M 12000000
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)
inline ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
inline void writeln(ll x)  {   write(x);   puts("");   }
ll ls[M],rs[M],sz[M],a[maxn],rt[maxn],n,q,cnt,ned;
void change(ll &x,ll y,ll l,ll r,ll v){
	x=++cnt;	ls[x]=ls[y];	rs[x]=rs[y];	sz[x]=sz[y]+1;
	if (l==r)	return;
	ll mid=(l+r)>>1;
	if (v<=mid)	change(ls[x],ls[y],l,mid,v);
	else	change(rs[x],rs[y],mid+1,r,v);
}
ll query(ll x,ll y,ll rnk,ll l,ll r){
	if (l==r)	return sz[x]-sz[y]>ned?l:0;
	ll mid=(l+r)>>1;
	if (sz[ls[x]]-sz[ls[y]]>=rnk)	return query(ls[x],ls[y],rnk,l,mid);
	else	return query(rs[x],rs[y],rnk-sz[ls[x]]+sz[ls[y]],mid+1,r);
}
int main(){
	n=read();	q=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	change(rt[i],rt[i-1],1,n,a[i]);
	For(i,1,q){
		ll l=read(),r=read(),k=read();	ned=(r-l+1)/k;	bool fl=0;
		if (!ned){	writeln(query(rt[r],rt[l-1],1,1,n));	continue;	}
		for(ll hh=ned;hh<=r-l+1;hh+=ned){
			ll x=query(rt[r],rt[l-1],hh,1,n);
			if (x)	writeln(x),fl=1;
			if (fl)	break;
		}if (!fl)	puts("-1");
	}
}