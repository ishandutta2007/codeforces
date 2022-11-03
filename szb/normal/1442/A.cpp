#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
#define FOr(i,x,y)	for(ll i=(x);i>=(y);--i)
#define rep(i,x,y)	for(ll i=(x);i<(y);++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define	pb	push_back
#define mk	make_pair
#define pa	pair<ll,ll>
#define y1	y11111111111111
#define fi	first
#define se	second
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
ll a[N],n;
int main(){
	for(ll T=read();T--;){
		n=read();	ll dec=1e9,inf=0,fl=1;
		For(i,1,n){
			a[i]=read();
		}
		For(i,1,n){
			a[i]-=inf;
  			if (a[i]<0){
				fl=0;
				break;
			}
			if (dec>a[i])dec=a[i],a[i]=0;
			else{///
				a[i]-=dec;
				inf+=a[i];
			}
		}
		if (fl)puts("YES");
		else puts("NO");
	}return 0;
}