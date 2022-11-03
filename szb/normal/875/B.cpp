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
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S i
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=300010;
ll fa[N],sz[N],p[N],n;	bool vis[N];
ll find(ll x){	return x==fa[x]?x:fa[x]=find(fa[x]);	}
int main(){
	n=read();
	For(i,1,n)	fa[i]=i;
	printf("1 ");
	For(i,1,n){
		p[i]=read();
		vis[p[i]]=1;	sz[p[i]]=1;
		if (vis[p[i]-1]&&p[i]!=1){
			sz[find(p[i])]+=sz[find(p[i]-1)];
			fa[find(p[i]-1)]=find(p[i]);
		}
		if (vis[p[i]+1]&&p[i]!=n){
			sz[find(p[i]+1)]+=sz[find(p[i])];
			fa[find(p[i])]=find(p[i]+1);
		}printf("%d ",1+i-sz[n]);
	}
}