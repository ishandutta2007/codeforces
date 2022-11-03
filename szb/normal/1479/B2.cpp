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
const double eps = 1e-7;
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
const ll mod=998244353,N=1600100;
ll n,x,a[N],f[N],tr[N],u,v,p1,p2,total,ans;
void build(ll l,ll r,ll p){
	if (l==r){
		if (l==1)tr[p]=0;
		else tr[p]=1e9;
		return;
	}ll mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	tr[p]=min(tr[p<<1],tr[p<<1|1]); 
}
ll query(ll l,ll r,ll p,ll s,ll t){
	if (l==s&&r==t){
		return tr[p];
	}ll mid=(l+r)>>1;
	if (t<=mid)return query(l,mid,p<<1,s,t); 
	else if (s>mid)return query(mid+1,r,p<<1|1,s,t);
	else return min(query(l,mid,p<<1,s,mid),query(mid+1,r,p<<1|1,mid+1,t)); 
}
void modify(ll l,ll r,ll p,ll pos,ll v){
	if (l==r){
		tr[p]=v;
		return;
	}ll mid=(l+r)>>1;
	pos<=mid?modify(l,mid,p<<1,pos,v):modify(mid+1,r,p<<1|1,pos,v);
	tr[p]=min(tr[p<<1],tr[p<<1|1]); 
}
ll ask(ll x,ll y){
	if (x>y)return 1e9;
	return query(1,n+1,1,x,y);
}
int main(){
	n=read();
	a[0]=1;
	For(i,1,n)a[i]=read()+1;
	build(1,n+1,1);
//	modify(1,n+1,1,1,1);
//	modify(1,n+1,1,2,2);
//	modify(1,n+1,1,3,3);
//	modify(1,n+1,1,4,4);
	For(i,1,n){
		ll cur=total;
		total+=a[i]!=a[i-1]; 
//		cout<<min(min(min(ask(1,a[i]-1)+1,ask(a[i]+1,n+1)+1),ask(a[i],a[i])),ask(a[i-1],a[i-1])+(a[i]!=a[i-1]))+cur<<endl;
		modify(1,n+1,1,a[i-1],min(min(min(ask(1,a[i]-1)+1,ask(a[i]+1,n+1)+1),ask(a[i],a[i])),ask(a[i-1],a[i-1])+(a[i]!=a[i-1]))+cur-total);
	}
	cout<<query(1,n+1,1,1,n+1)+total<<endl;
}