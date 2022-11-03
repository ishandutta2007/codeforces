#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
ll n,c[410][410],f[410][410];
const ll mod=1e9+7;
inline void add(ll &x,ll y){	x=(x+y)%mod;	}
int main(){
	For(i,0,400){
		c[i][0]=c[i][i]=1;
		For(j,1,i-1)	c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	n=read();
	f[1][0]=1;	f[1][1]=1;
	For(i,2,n)	For(j,0,n)	For(k,0,n)if (j+k<=n){
		if (j+k+1<=n)	add(f[i][j+k+1],f[i-1][j]*f[i-1][k]);
		if (j+k<=n)	add(f[i][j+k],f[i-1][j]*f[i-1][k]%mod*(j+k)*2%mod+f[i-1][j]*f[i-1][k]%mod);
		if (j||k)	add(f[i][j+k-1],f[i-1][j]*f[i-1][k]%mod*c[j+k][2]*2);
	}else	break;writeln(f[n][1]);
}
/*
f[i][j]
ij
*/