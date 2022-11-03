#include<bits/stdc++.h>
//#include<unistd.h>
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
const ll N=1000010;
ll n,a[N];
int main(){
	for(ll T=read();T--;){
		n=read();	ll mx=-1e9,ans=0,answ=1;
		For(i,1,n){
			a[i]=read();
			mx=max(mx,a[i]);
			ans=max(ans,mx-a[i]);
		}
		for(;(1ll<<(answ))<=ans;answ++);
//		cout<<ans<<endl;
		if (ans==0)cout<<0<<endl;
		else	cout<<answ<<endl;
	}
}