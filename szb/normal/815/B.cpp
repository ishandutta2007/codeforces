#include<cstdio>
#include<algorithm>
#include<memory.h>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define maxn 210010
const ll mod=1e9+7;
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
void writeln(ll x){ wrote(x);   puts("");   }
ll fac[maxn],inv[maxn],a[maxn],b[maxn],c[maxn],n;	bool flag;
void init(){
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	For(i,2,n)	inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	For(i,2,n)	fac[i]=fac[i-1]*i%mod,inv[i]=inv[i-1]*inv[i]%mod;
}
ll C(ll n,ll m){	return fac[n]*inv[m]%mod*inv[n-m]%mod;	}
int main(){
	n=read();
	For(i,1,n)	a[i]=read();
	if (n==1)	return writeln(a[1]),0;
	n+=100;
	init();
	n-=100;
	ll now=(n-1)%4,tim=(n-1)/4*2;	++now;
	For(i,1,now)	For(j,0,tim)	b[i]=(b[i]+a[i+j*2]*C(tim,j))%mod;
	n=now;
	For(sum,1,n-1){
		For(i,1,n-sum){
			c[i]=flag?(b[i]-b[i+1])%mod:(b[i]+b[i+1])%mod;
			flag^=1;
		}
		memcpy(b,c,sizeof c);
	}
	writeln((b[1]%mod+mod)%mod);
}