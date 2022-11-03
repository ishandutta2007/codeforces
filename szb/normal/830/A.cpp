#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
#define maxn 400010
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
ll f[2010][2010],n,k,pos,a[2010],b[2010],ans=1e18;
ll dis(ll x,ll y){	return abs(y-x);	}
ll calc(ll x,ll y){	return (dis(a[x],b[y])+dis(b[y],pos));}
int main(){
	n=read();	k=read();	pos=read();
	For(i,1,n)	a[i]=read();
	For(i,1,k)	b[i]=read();
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	memset(f,63,sizeof f);
	For(i,1,n){
		ll ans=1e18;
		if (i==1)	ans=0;
		For(j,1,k)	f[i][j]=max(ans,calc(i,j)),
					ans=min(ans,f[i-1][j]);
	}
	For(i,1,k)	ans=min(f[n][i],ans);
	writeln(ans);
}