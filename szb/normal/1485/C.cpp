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
const ll N=300300;
ll calc(ll u,ll v){
	ll ans=0;
	for(ll i=u,j;i<=v;i=j+1){
		j=v/(v/i);
		ans+=(j-i+1)*(v/i);
	}
	return ans;
}
int main(){
	ll T=read();
	for(;T--;){
		ll a=read(),b=read()+1,ans=0;
		ll i=2;
		for(;i<=b;++i){
			if (a/i<i-2){break;}
			else	ans+=i-2;
		}
		b=min(b,a);
		ans+=calc(i,a);
		ans-=calc(b+1,a);
		cout<<ans<<endl;
	}
}