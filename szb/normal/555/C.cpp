#include<bits/stdc++.h>
#define ll int
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
using namespace std;
ll read(){	char ch=getchar();	ll x=0,f=1;	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';	return x*f;		}
void write(ll x){	if (x<0)	putchar('-'),x=-x;	if (x>=10)	write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}
char ch[2];	const ll N=200001;
ll n,m,L[N],U[N];
struct SGT{
	ll mx[N*8];
	void change(ll l,ll r,ll p,ll s,ll t,ll v){
		if (l==s&&r==t)	return mx[p]=max(mx[p],v),void(0);
		ll mid=(l+r)>>1;	mx[p<<1]=max(mx[p<<1],mx[p]);	mx[p<<1|1]=max(mx[p<<1|1],mx[p]);
		if (t<=mid)	change(l,mid,p<<1,s,t,v);
		else if (s>mid)	change(mid+1,r,p<<1|1,s,t,v);
		else change(l,mid,p<<1,s,mid,v),change(mid+1,r,p<<1|1,mid+1,t,v);
	}
	ll query(ll l,ll r,ll p,ll pos){
		if (l==r)	return mx[p];
		ll mid=(l+r)>>1;	mx[p<<1]=max(mx[p<<1],mx[p]);	mx[p<<1|1]=max(mx[p<<1|1],mx[p]);
		return pos<=mid?query(l,mid,p<<1,pos):query(mid+1,r,p<<1|1,pos);
	}
}sgt[2];
struct data{	ll x,y,opt;	}ask[N];
ll q[N],vis[N],tot;
int main(){
//	freopen("burn.in","r",stdin);
//	freopen("burn.out","w",stdout);
	n=read();	m=read();
	For(i,1,m){
		ask[i].x=read();	ask[i].y=read();	scanf("%s",ch);
		ask[i].opt=ch[0]=='L';	q[++tot]=ask[i].x;
	}sort(q+1,q+tot+1);	tot=unique(q+1,q+tot+1)-q-1;
	For(i,1,m){
		ll x=lower_bound(q+1,q+tot+1,ask[i].x)-q,y=tot-x+1;
		if (vis[x]){	puts("0");	continue;	}	vis[x]=1;
		if (ask[i].opt){
			ll z=sgt[1].query(1,tot,1,y);
			if (z!=tot)	sgt[0].change(1,tot,1,z+1,x,y);
			writeln(z?q[x]-q[z]:q[x]);
		}else{
			ll z=sgt[0].query(1,tot,1,x);
			if (z!=tot)	sgt[1].change(1,tot,1,z+1,y,x);
			writeln(z?(n-q[tot-y+1]+1-(n-q[tot-z+1]+1)):(n-q[tot-y+1]+1));
		}
	}
}