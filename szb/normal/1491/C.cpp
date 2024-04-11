
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
const ll N=100010;
ll n,s[N],vis[N],ans;
int main(){
	ll T=read();
	for(;T--;){
		n=read();	ans=0;
		For(i,1,n)	s[i]=read(),vis[i]=0;
		For(i,1,n){
			ans+=max(0ll,s[i]-1-vis[i]);
			vis[i]=max(vis[i],s[i]-1);
			ll R=min(n,i+s[i]);
			vis[i+1]+=max(0ll,vis[i]-(s[i]-1));
			For(j,i+2,R){
				++vis[j];
			}
		}
		cout<<ans<<endl;
	}
}