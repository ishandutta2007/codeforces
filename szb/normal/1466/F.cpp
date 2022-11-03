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
const ll N=1002000,mod=1e9+7;
vector<ll>ans;
ll fa[N],vis[N],n,m;
ll find(ll x){
	return (x==fa[x])?x:fa[x]=find(fa[x]);
}
ll ppow(ll x,ll k){
	ll ans=1;
	for(;k;k>>=1,x=x*x%mod)if (k&1)ans=ans*x%mod;
	return ans;
}
int main(){
	n=read();	m=read();
	For(i,1,m)	fa[i]=i;
	For(i,1,n){
		ll opt=read();
		if (opt==2){
			ll x=find(read()),y=find(read());
			if (x==y)continue;
			if (vis[x]&&vis[y])continue;
			vis[x]|=vis[y];
			fa[y]=x;
			ans.pb(i);
		}else{
			ll x=find(read());
			if (vis[x])continue;
			vis[x]=1;
			ans.pb(i);
		}
	}
	cout<<ppow(2,ans.size())<<' '<<ans.size()<<endl;
	rep(i,0,ans.size())write(ans[i]),putchar(' ');puts("");
}