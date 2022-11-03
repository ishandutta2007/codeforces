#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<ctime>
#include<map>
using namespace std;
#define ll int
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
void writeln(ll x)  {   write(x);   puts("");   }
int main(){
	ll T=read();
	while(T--){
		ll n=read(),ans=0;
		if (n&1)	n-=9,++ans;
		if (n<0){	puts("-1");	continue;}
		if ((n%4))	n-=6,++ans;
		if (n<0){	puts("-1");	continue;}
		writeln(n/4+ans);
	}
}
//4 6 9