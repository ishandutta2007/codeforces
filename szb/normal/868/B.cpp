#include<queue>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define maxn 100010
#define pa pair<ll,ll>
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
ll h,m,s,t1,t2;
bool pd(ll t1,ll h,ll t2){	return	(t1<=h&&h<=t2);}
int main(){
	h=read()*5*3600;	m=read()*3600;	s=read()*3600;	t1=read()*5*3600;	t2=read()*5*3600;
	m=m+s/60;	h=h+m/60;
	if (t1>t2)	swap(t1,t2);
	if (pd(t1,h,t2)&&pd(t1,m,t2)&&pd(t1,s,t2))	return puts("YES"),0;
	if (!pd(t1,h,t2)&&!pd(t1,m,t2)&&!pd(t1,s,t2))	return puts("YES"),0;
	puts("NO");
}