#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S i
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
ll x=read(),bin[100],ans[100];
ll check(ll now){
	ll sum=now;
	while(now)	sum+=now%10,now/=10;
	return sum==x;
}
int main(){
	bin[0]=1;	For(i,1,12)	bin[i]=bin[i-1]*10;
	For(i,x-100,x)	if (i>0){
		if (check(i))	ans[++ans[0]]=i;
	}
	writeln(ans[0]);
	For(i,1,ans[0])	writeln(ans[i]);
}