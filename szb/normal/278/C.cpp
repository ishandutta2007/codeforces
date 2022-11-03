#include<algorithm> 
#include<cmath> 
#include<bitset> 
#include<set>
#include<cstdio> 
#include<map> 
#define ll int
#define maxn 400010 
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
ll n,m,fa[maxn],Cnt,cnt,vis[maxn],f[maxn];
ll find(ll x){	return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	n=read();	m=read();
	For(i,1,n)	fa[i]=i;
	For(i,1,n){
		ll sum=read();
		if (!sum)	f[i]=1;
		while(sum--){
			ll x=read();
			if (vis[x])	fa[find(vis[x])]=find(i);
			else	vis[x]=i;
		}
	}
	For(i,1,n)	if (fa[i]==i)	Cnt+=f[i],cnt+=!f[i];
	if (cnt>1)	Cnt+=cnt-1;
	writeln(Cnt);
}