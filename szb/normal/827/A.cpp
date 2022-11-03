#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll int
#define maxn 4000100
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
ll head[maxn],nxt[maxn],vet[maxn],L[maxn],R[maxn],a[maxn],st[maxn],m,len,n,tot,last;
char s[maxn];
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
int main(){
	n=read();
	For(i,1,n){
		scanf("%s",s+1);	m=strlen(s+1);
		For(j,last+1,last+m)	a[j]=s[j-last];
		L[i]=last+1;	R[i]=last+m;	last+=m;
		ll k=read();
		while(k--){
			ll x=read();
			insert(x,i);
			len=max(len,x+m-1);
		}st[i]=m;
	}
//	For(i,1,last)	writeln(a[i]
	ll cho=0,pos=0;
	For(x,1,len){
		for(ll i=head[x];i;i=nxt[i])
		if (st[vet[i]]+x>st[cho]+pos)	cho=vet[i],pos=x;
//		writeln(pos);
		if (st[cho]+pos-1>=x)	putchar(a[L[cho]+x-pos]);	else	putchar('a');
	}
}