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
const ll mod=998244353;
ll n;
bool ok(ll x){
	ll v1,v2,v3;
	if (x==1)v1=1e9;
	else{
		cout<<'?'<<' '<<x-1<<endl;
		fflush(stdout);
		v1=read();
	} 
	cout<<'?'<<' '<<x<<endl;
	fflush(stdout);
	v2=read();
	if (x==n)v3=1e9;
	else{
		cout<<'?'<<' '<<x+1<<endl;
		fflush(stdout);
		v3=read();
	}
	return (v2<v1)&&(v2<v3); 
}
int main(){
	srand(time(0));
	n=read();
	ll l=1,r=n;
	for(;l+3<r;){
		ll mid1=(l+r)/2,mid2=mid1+1,
		  v1,v2;
		cout<<'?'<<' '<<mid1<<endl;
		fflush(stdout);
		v1=read();
		cout<<'?'<<' '<<mid2<<endl;
		fflush(stdout);
		v2=read();
		if (v1>v2)l=mid1+1;
		else r=mid2-1;
	}
	For(i,l,r)if (ok(i)){
		cout<<'!'<<' '<<i<<endl; 
		fflush(stdout);
		return 0;
	}
}