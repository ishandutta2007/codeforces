#include<algorithm>
#include<cmath>
#include<memory.h>
#include<cstdio>
#include<map>
#include<queue>
#define ll long long
#define maxn 1000010
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pa pair<ll,ll>
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
void writeln(ll x){ write(x);   puts("");   }
ll mod,n,s0,s1,a[maxn];	map<ll,bool>mp;
ll ppow(ll x,ll k){
	ll ans=1;
	while(k){
		if (k&1)	ans=ans*x%mod;	x=x*x%mod;
		k>>=1;
	}return ans;
}
int main(){
	mod=read();	n=read();
	For(i,1,n){
		a[i]=read();
		s0=s0+a[i];
		s1=(s1+a[i]*a[i])%mod;
		mp[a[i]]=1;
	}sort(a+1,a+n+1);
	if (n==mod)	return puts("1 1"),0;
	if (n==1)	return printf("%lld 0\n",a[1]),0;
	For(i,2,n){
		ll k=a[i]-a[1],a0=((s0-n*(n-1)/2*k)%mod*ppow(n,mod-2)%mod+mod)%mod;
		if ((((n*(n-1)*(2*n-1)/6%mod*k%mod*k%mod+a0*k%mod*n%mod*(n-1)%mod+a0*a0%mod*n%mod)%mod+mod)%mod)==s1){
			ll x=a0-k;
			For(i,1,n){
				x=(x+k)%mod;
				if (!mp[x])	return puts("-1"),0;
			}return	printf("%lld %lld\n",a0,k),0;
		}
	}puts("-1");
}
/*
n<=m/2
x,x+k*d,k*d
n<=m/2k*dn-k
k*d
d,
*/