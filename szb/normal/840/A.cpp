#include<ctime>
#include<algorithm>
#include<cstdio>
#include<set>
#include<memory.h>
#include<queue>
#include<cmath>
using namespace std;
#define ll long long
#define maxn 200010
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)
inline ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
inline void writeln(ll x)  {   write(x);   puts("");   }
struct data{
	ll v,id;
}b[maxn];
ll a[maxn],n,k,c[maxn];
bool cmp(data a,data b){	return a.v<b.v;	}
int main(){
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	b[i].v=read(),b[i].id=i;
	sort(b+1,b+n+1,cmp);
	sort(a+1,a+n+1);
	For(i,1,n)	c[b[i].id]=i;
	For(i,1,n)	printf("%lld ",a[n+1-c[i]]);
}