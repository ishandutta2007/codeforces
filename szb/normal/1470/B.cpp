#include<bits/stdc++.h>
using namespace std; 
#define ll int
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
ll a[N],b[N],v[N],t[N],id[N],u[N],n,m,q;
int main(){
	ll T=read();
	for(;T--;){
		n=read();
		For(i,1,n){
			ll x=read();
			for(ll j=2;j*j<=x;++j)while(x%(j*j)==0)x/=j*j; 
			a[i]=x;
		}
		sort(a+1,a+n+1); 
		ll ans=0,ans1=0;
		a[n+1]=-1;
		For(i,1,n){
			ll sum=1;
			while(a[i+1]==a[i]){
				sum++;	i++;
			}
			ans=max(ans,sum);
			if ((sum%2==0)||(a[i]==1))ans1+=sum;
		}
		q=read();
		For(i,1,q){
			long long w;
			scanf("%lld",&w); 
			if (w==0)write(ans),puts("");
			else write(max(ans1,ans)),puts("");
		}
	}
}