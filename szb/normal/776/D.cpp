#include<algorithm> 
#include<memory.h> 
#include<cmath> 
#include<bitset> 
#include<cstdio> 
#include<map> 
#define ll int
#define maxn 400010 
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
ll fa[maxn],dis[maxn],c[maxn],n,m,ls[maxn],rs[maxn];
ll find(ll x){
	if (x==fa[x])	return x;
	ll t=fa[x];
	fa[x]=find(fa[x]);
	dis[x]^=dis[t];
	return fa[x];
}
int main(){
	n=read();	m=read();
	For(i,1,n)	c[i]=1^read();
	For(i,1,m){
		ll sz=read();	fa[i]=i;
		For(j,1,sz){
			ll x=read();
			if (ls[x])	rs[x]=i;
			else	ls[x]=i;
		}
	}
//	For(i,1,m)	printf("%d %d\n",ls[i],rs[i]);
	For(i,1,n){
		ll x=ls[i],y=rs[i],a=find(x),b=find(y);
		if (a==b&&dis[x]^dis[y]^c[i])	return puts("NO"),0;
		fa[b]=a;	dis[b]=c[i]^dis[x]^dis[y];
	}
	puts("YES");
}