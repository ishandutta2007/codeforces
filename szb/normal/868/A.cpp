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
char s[100],a[10010][10];
ll n;
int main(){
	scanf("%s",s);
	ll ned=s[0]*100+s[1];
	n=read();
	For(i,1,n){
		scanf("%s",a[i]);
		if (a[i][0]*100+a[i][1]==ned)	return puts("YES"),0;
	}
		For(i,1,n)	For(j,1,n)
		if ((a[i][1]*100+a[j][0]==ned))	return puts("YES"),0;
		puts("NO");
}