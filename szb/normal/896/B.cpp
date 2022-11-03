#include<ctime>
#include<algorithm>
#include<cstdio>
#include<set>
#include<memory.h>
#include<queue>
#include<cmath>
using namespace std;
#define ll long long
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
ll n,clc[10010],m,c;
bool ok(){
	For(i,1,n)	if (!clc[i])	return 0;
	For(i,2,n)	if (clc[i-1]>clc[i])	return 0;
	return 1;
}
int main(){
	n=read();	m=read();	c=read();
	For(i,1,m){
		if (ok())	return 0;
		ll x=read();
		if (x<=c/2){
			For(j,1,n)	if (!clc[j]||clc[j]>x){	writeln(j);clc[j]=x;fflush(stdout);	break;	}
		}
		else
			FOr(j,n,1)	if (!clc[j]||clc[j]<x){	writeln(j);clc[j]=x;fflush(stdout);	break;	}
	}
}