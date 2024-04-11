#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const ll N=300010,mod=998244353;
ll ppow(ll x,ll k){
   	ll ans=1;
   	while(k){
   		if (k&1)	ans=ans*x%mod;
   		x=x*x%mod;	k>>=1;
   	}return ans;
}
ll f[N],a[N],xi[N],vi[N],n,m,ans;
int main(){
   	n=read();
   	For(i,1,n)	a[i]=read(),m+=a[i];
   	xi[0]=1;						vi[0]=0;
   	xi[1]=1;						vi[1]=-n+1;
   	For(i,1,m-1){
   		xi[i+1]=(xi[i]*(m*(n-1)%mod-(m-i)*(n-2)%mod)%mod-xi[i-1]*i%mod*(n-1)%mod)%mod*ppow(m-i,mod-2)%mod;
   	
   		vi[i+1]=(vi[i]*(m*(n-1)%mod-(m-i)*(n-2)%mod)%mod-vi[i-1]*i%mod*(n-1)%mod-(m*(n-1))%mod)%mod*ppow(m-i,mod-2)%mod;

   	}
   	ll x=(mod-vi[m])*ppow(xi[m],mod-2)%mod;
   	For(i,0,m)f[i]=(xi[i]*x%mod+vi[i])%mod;
   	For(i,1,n)ans=(ans+f[a[i]])%mod;
   	ans=(ans-f[0]*(n-1))%mod;
   	ans=ans*ppow(n,mod-2)%mod;
   	ans=(ans+mod)%mod;
   	cout<<ans<<endl;
}