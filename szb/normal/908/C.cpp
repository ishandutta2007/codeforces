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
const ll N=1010;
double x[N],y[N];
ll n,r,tot;
double sqr(double x){	return x*x;	}
void insert(){
	x[++tot]=read();	y[tot]=r;
	For(i,1,tot-1){
		if (abs(x[i]-x[tot])<=2*r){
			y[tot]=max(y[tot],sqrt(sqr(2*r)-sqr(x[i]-x[tot]))+y[i]);
		}
	}
	printf("%.10lf ",y[tot]);
}
int main(){
	n=read();	r=read();
	For(i,1,n)	insert();
}