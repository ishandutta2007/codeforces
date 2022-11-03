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
ll a[N],b[N],v[N],t[N],n,m;
int main(){
	ll T=read();
	for(;T--;){
		n=read();m=read();
		For(i,1,m)v[i]=0;
		For(i,1,n)a[i]=read(),v[a[i]]++;
		For(i,1,m)b[i]=read();
		ll R=m; 
		For(i,1,m){
			while((R>i)&&!v[R])--R;
			if ((R>i)&&(v[R])){
				 v[R]--;
				 v[i]++;
			} 
		}
		ll ans=0;
		For(i,1,m)ans+=v[i]*b[i];
		cout<<ans<<endl;
	}
}