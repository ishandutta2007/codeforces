#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define ll long long
#define maxn 400010
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
void writeln(ll x)  {   write(x);   puts("");   }
ll f[maxn],lazy[maxn],mx[maxn],las[maxn],a[maxn],n,k;
void pushdown(ll p){
	lazy[p<<1]+=lazy[p];
	lazy[p<<1|1]+=lazy[p];
	lazy[p]=0;
}
void updata(ll p){
	mx[p]=max(mx[p<<1]+lazy[p<<1],mx[p<<1|1]+lazy[p<<1|1]);
}
void build(ll l,ll r,ll p){
	lazy[p]=0;
	if (l==r){	mx[p]=f[l];	return;	}
	ll mid=(l+r)>>1;
	build(l,mid,p<<1);	build(mid+1,r,p<<1|1);
	updata(p);
}
void add(ll l,ll r,ll p,ll s,ll t){
	if (l==s&&r==t){	lazy[p]++;	return;}
	ll mid=(l+r)>>1;	pushdown(p);
	if (t<=mid)	add(l,mid,p<<1,s,t);
	else if (s>mid)	add(mid+1,r,p<<1|1,s,t);
	else	add(l,mid,p<<1,s,mid),add(mid+1,r,p<<1|1,mid+1,t);
	updata(p);
}
ll query(ll l,ll r,ll p,ll s,ll t){
	if (l==s&&r==t)	return lazy[p]+mx[p];
	ll mid=(l+r)>>1,answ;	pushdown(p);
	if (t<=mid)	answ=query(l,mid,p<<1,s,t);
	else	if (s>mid)	answ=query(mid+1,r,p<<1|1,s,t);
	else	answ=max(query(l,mid,p<<1,s,mid),query(mid+1,r,p<<1|1,mid+1,t));
	updata(p);	return answ;
}
int main(){
	n=read();	k=read();
	For(i,1,n)	a[i]=read();
	For(i,1,k){
		build(0,n,1);
		For(j,1,n)	las[j]=0;
		For(j,1,n){
			add(0,n,1,las[a[j]],j-1);	las[a[j]]=j;
			f[j]=query(0,n,1,0,j-1);
		}
	}
	writeln(f[n]);
}