#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y)	for(ll i=(ll)x;i<=(ll)y;++i)
#define FOr(i,x,y)	for(ll i=(ll)x;i>=(ll)y;--i)
#define rep(i,x,y)	for(ll i=(ll)x;i<(ll)y;++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define fi	first
#define se	second
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
const ll N=200010;
ll n,k,a[N];
int main(){
	ll t=read();
	for(;t;){
		For(i,1,n)a[i]=0;
		n=read();	k=read();
		For(i,1,n){
			a[i]=read();
			if (a[i]<k)a[i]=1;
			else if (a[i]==k)a[i]=2;
			else if (a[i]>k)a[i]=3;
		}
		ll sum1=0;
		For(i,1,n)sum1+=a[i]==2;
		if (!sum1){
			puts("no");
			--t;
			continue;
		}
		For(i,1,n)if (a[i]==3)				a[i]=2;
		ll ok=0;
		For(i,1,n)if (a[i]==2&&a[i+1]==2)	ok=1;
		For(i,1,n)if (a[i]==2&&a[i+2]==2)	ok=1;
		if (n==1){
			if (a[1]==2)puts("yes");
			else puts("no");
			--t;
			continue;
		}
		if (ok){
			puts("yes");
			--t;
			continue;
		}else{
			puts("no");
			--t;
			continue;
		}
	}
}