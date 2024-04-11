#include<ctime>
#include<algorithm>
#include<cstdio>
#include<set>
#include<memory.h>
#include<queue>
#include<cmath>
using namespace std;
#define ll long long
#define maxn 300010
#define M 12000000
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
inline ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
inline void writeln(ll x)  {   write(x);   puts("");   }
const ll mod=1e9+7;
ll f[310][310],c[310][310],n,a[310],fac[310],mark[310],b[310],m;
ll sqr(ll x){	return x*x;	}
void add(ll &a,ll b){	a=(a+b)%mod;	}
int main(){
	n=read();
	For(i,1,300){
		c[i][0]=c[i][i]=1;
		For(j,1,i-1)	c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	c[0][0]=fac[0]=1;	For(i,1,300)	fac[i]=fac[i-1]*i%mod;
	For(i,1,n){
		a[i]=read();
		for(ll j=2;j*j<=a[i];j++)
		while(!(a[i]%(j*j)))	a[i]/=j*j;
	}
	For(i,1,n)	if (!mark[i]){
		b[++m]=1;
		For(j,i+1,n)
		if (!mark[j]&&(a[i]==a[j]))	b[m]++,mark[j]=1;
	}
	f[1][b[1]-1]=1;	ll sum=b[1];
	For(i,2,m){
		For(j,0,sum-1)	For(k,0,b[i]-1)	For(l,0,min(j,k+1))	add(f[i][j+b[i]-1-k-l],f[i-1][j]*c[b[i]-1][k]%mod*c[j][l]%mod*c[sum-1-j+2][k+1-l]);
		sum+=b[i];
	}
	For(i,1,m)	f[m][0]=(f[m][0]*fac[b[i]])%mod;
	writeln(f[m][0]);
}