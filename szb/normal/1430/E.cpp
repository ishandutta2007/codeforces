#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const ll N=800010;
ll n,sum[N],tr[N],ans;
char s[N],t[N];
ll fabs(ll x){return x<0?(-x):x;} 
void build(ll l,ll r,ll p){
	if (l==r){
		sum[p]=1;
		tr[p]|=1<<(s[l]-'a');
		return;
	}
	ll mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	sum[p]=sum[p<<1]+sum[p<<1|1];
	tr[p]=tr[p<<1]|tr[p<<1|1];
}
ll query(ll l,ll r,ll p,ll v){
	if (l==r){
		sum[p]=tr[p]=0;
		return 0;
	}
	ll mid=(l+r)>>1;
	if (tr[p<<1]>>v&1)	ans=query(l,mid,p<<1,v);
	else	ans=query(mid+1,r,p<<1|1,v)+sum[p<<1];
	sum[p]=sum[p<<1]+sum[p<<1|1];
	tr[p]=tr[p<<1]|tr[p<<1|1];
	return ans;
}
int main(){
	n=read();
	scanf("%s",s+1);
	build(1,n,1);
	cpy(t,s);
	reverse(t+1,t+n+1);
	ll ans=0;
	For(i,1,n){
		ans+=query(1,n,1,t[i]-'a');
	}write(ans);
}