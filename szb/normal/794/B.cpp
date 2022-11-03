#include<algorithm>
#include<memory.h>
#include<map>
#include<cstdio>
#include<cmath>
#define ll int
#define maxn 201000
#define ld long double
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){  write(x);   puts("");   }
ll n,h;
ld ans,sum;
int main(){
	n=read();	h=read();
	ans=h/sqrt(n);
	For(i,1,n-1){
		sum+=sqrt((ld)i);
		printf("%.12lf ",(double)(ans*sqrt((ld)i)));
	}
}