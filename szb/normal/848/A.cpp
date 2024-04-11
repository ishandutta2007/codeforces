#include<ctime>
#include<algorithm>
#include<cstdio>
#include<memory.h>
using namespace std;
#define ll long long
#define LL long long
#define maxn 100010
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)
inline ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
inline void writeln(ll x)  {   write(x);   puts("");   }
ll n;
ll f[maxn],g[maxn];
int main(){
	n=read();	if (!n)	return puts("a"),0;
	memset(f,60,sizeof f);	f[0]=0;
	For(i,1,n)	For(j,1,n+2){
		if(j*(j-1)/2>i)	break;
		if (f[i-j*(j-1)/2]<f[i])	f[i]=f[i-j*(j-1)/2]+1,g[i]=j;
	}
	while(n){
		For(j,1,g[n])	putchar('a'+f[n]-1);
		n-=g[n]*(g[n]-1)/2;
	}
}