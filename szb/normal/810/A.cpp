#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)	for(int i=x;i>=y;--i)
#define maxn 610010
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
int main(){
	ll sum=0,hh=0,n=read(),k=read();
	For(i,1,n)	sum+=read();
	For(i,0,10000000)	if ((sum+k*i)*2>=(2*k-1)*(i+n))	return printf("%d\n",(int)i),0;
}