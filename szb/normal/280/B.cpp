#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define ll int
#define maxn 100020
#define ld double
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
void writeln(ll x)  {   write(x);   puts("");   }
ll a[maxn],q[maxn],n,top,ans;
int main(){
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n){
		while(a[q[top]]<a[i]&&top)	ans=max(ans,a[q[top--]]^a[i]);
		q[++top]=i;
	}top=0;
	FOr(i,n,1){
		while(a[q[top]]<a[i]&&top)	ans=max(ans,a[q[top--]]^a[i]);
		q[++top]=i;
	}
	writeln(ans);
}