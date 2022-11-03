#include<queue>
#include<map>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define maxn 200010
#define pa pair<ll,ll>
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
ll n;
int main(){
	n=read();
	puts("YES");
	For(i,1,n){
		ll x=read(),y=read(),ans=1;	read(),read();
		if (x&1)	ans+=2;
		if (y&1)	ans++;
		writeln(ans);
	}
}