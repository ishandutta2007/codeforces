#include<queue>
#include<set>
#include<map>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long
#define maxn 400010
#define mk make_pair
#define rep(i,x,y)  for(i=x;i<=y;++i)
#define dep(i,x,y)	for(i=x;i>=y;--i)
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll N=300010;
ll a[N],pre[N],nxt[N],n,ans;
int main(){
	n=read();
	For(i,1,n)	a[i]=read();	a[0]=a[n+1]=-1;
	For(i,1,n){
		pre[i]=i-1;
		while((a[i]|a[pre[i]])==a[i])	pre[i]=pre[pre[i]];
	}
	FOr(i,n,1){
		nxt[i]=i+1;
		while(((a[i]|a[nxt[i]])==a[i])&&(a[nxt[i]]<a[i]))	nxt[i]=nxt[nxt[i]];
	}
	For(i,1,n)	ans+=(nxt[i]-i)*(i-pre[i]);
	writeln(n*(n+1)/2-ans);
}