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
ll mark[100],n,k;
int main(){
	n=read();	k=read();
	For(i,1,n){
		ll now=0;
		For(j,1,k)	now=now<<1|read();
		mark[now]++;
	}
	For(i,0,15)	For(j,0,15)
	if (mark[i]&&mark[j]&&!(i&j))	return puts("YES"),0;
	puts("NO");
}