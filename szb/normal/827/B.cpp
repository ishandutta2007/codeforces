#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll int
#define maxn 400010
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
ll X[maxn],Y[maxn],dep[maxn],n,k,tot;
inline void insert(ll x,ll y){
	X[++tot]=x;	Y[tot]=y;
}
int main(){
	n=read();	k=read();
	For(i,2,k+1)	insert(1,i),dep[i]=1;
	For(i,k+2,n)	insert(i-k,i),dep[i]=dep[i-k]+1;
	writeln(dep[n-1]+dep[n]);
	For(i,1,n-1)	printf("%d %d\n",X[i],Y[i]);
}