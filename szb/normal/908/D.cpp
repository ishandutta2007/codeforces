#include<ctime>
#include<algorithm>
#include<cstdio>
#include<set>
#include<memory.h>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
#define ll long long
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll N=2010,mod=1e9+7;
ll f[N][N];
ll n,a,b,add_a,add_b;
ll ppow(ll x,ll k){
	ll ans=1;
	while(k){
		if (k&1)	ans=ans*x%mod;	x=x*x%mod;
		k>>=1;
	}return ans;
}
void add(ll &x,ll y){	x=(x+y)%mod;	}
int main(){
	n=read();	a=read();	b=read();	add_a=a*ppow(a+b,mod-2)%mod;	add_b=1+mod-add_a; 
	ll ans=0,calc=a*ppow(b,mod-2)%mod;
	FOr(i,n,1)	FOr(j,n-1,0){
		if (i+j>=n)	f[i][j]=(i+j+calc)%mod;
		else	f[i][j]=(add_a*f[i+1][j]+add_b*f[i][j+i])%mod;
	}writeln(f[1][0]);
}