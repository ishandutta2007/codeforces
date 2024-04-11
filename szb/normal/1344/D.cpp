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
const	ll N=100100;
const	long double eps=1e-8;
priority_queue<pa>q;
ll n,k,ret[N],ans[N];
pa a[N];
ll max(ll a,ll b){return a<b?b:a;}
ll min(ll a,ll b){return a<b?a:b;}
ll check(ll t){
	ll sum=0;
	For(i,1,n){
		ll res=0;
		if ((9-(ld)12.0*(t+1-a[i].fi))>=0) res=min(max(0ll,(ll)((3.0+sqrt(9.0-(ld)12.0*(t+1.0-a[i].fi)))/6+eps)),a[i].fi);
		ret[i]=res;
		sum+=res;
	}
	return sum;
}
void doit(ll t){
	ll sum=0;//,ans=0;
	For(i,1,n){
		ll res=0;
		if ((9-(ld)12*(t+1-a[i].fi))>=0) res=min(max(0ll,(ll)((3.0+sqrt(9.0-(ld)12.0*(t+1.0-a[i].fi)))/6+eps)),a[i].fi);
		ret[i]=res;
//		ans+=ret[i]*(a[i].fi-ret[i]*ret[i]);
		sum+=ret[i];
		if (ret[i]<a[i].fi)q.push(mk(a[i].fi-1-3*ret[i]*ret[i]-3*ret[i],i));
	}
//	For(i,1,n)cout<<ret[i]<<' ';
//	cout<<endl;
	while(sum<k){
		pa tmp=q.top();	q.pop();
		++sum;
//		ans+=tmp.fi;
//		cout<<tmp.fi<<endl;
		if(++ret[tmp.se]<a[tmp.se].fi)q.push(mk(a[tmp.se].fi-1-3*ret[tmp.se]*ret[tmp.se]-3*ret[tmp.se],tmp.se));	
	}
	For(i,1,n)ans[a[i].se]=ret[i];
//	cout<<t<<endl;
	For(i,1,n)cout<<ans[i]<<' ';
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();	k=read();
	For(i,1,n)a[i]=mk(read(),i);
	sort(a+1,a+n+1);
	ll l=-3e18,r=3e18;
//	ll l=-1e17,r=1e17	;
	while(l+1<r){
		ll mid=(l+r)>>1;
		if (check(mid)>=k)l=mid;
		else	r=mid;
	}
	doit(r+1);
}