#include<algorithm> 
#include<cmath> 
#include<bitset> 
#include<set>
#include<cstdio> 
#include<map> 
#define ll long long
#define maxn 400010 
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
ll fa[maxn],tot,n,m;
ll find(ll x){	return x==fa[x]?x:fa[x]=find(fa[x]);	}
int main(){
	n=read();	m=read();
	For(i,1,n)	fa[i]=i;
	For(i,1,m){
		ll x=find(read()),y=find(read());
		if (x!=y){
			fa[x]=y;
			++tot;
		}
	}
	writeln(1ll<<tot);
}