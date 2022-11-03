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
const ll maxn=200010,inf=2e9;
ll c[maxn],d[maxn],n,mn,mx;
int main(){
	n=read();
	For(i,1,n){
		c[i]=read()+c[i-1];
		d[i]=read();
	}
	if (d[1]==1)	mn=1900,mx=inf;
	else	mx=1899,mn=-inf;
	For(i,2,n){
		if (d[i]==1)	mn=max(mn,1900LL-c[i-1]);
		if (d[i]==2)	mx=min(mx,1899LL-c[i-1]);
	}
	if (mn>mx)	return puts("Impossible"),0;
	if (mx>1e9)	return puts("Infinity"),0;
	writeln(mx+c[n]);
}