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
const ll N=200010;
struct data{	ll x,y,w;	}p[N];
ll fa[N],n,m,ans;	bool vis[N];
bool cmp(data a,data b){	return a.w>b.w;	}
ll find(ll x){	return x==fa[x]?x:fa[x]=find(fa[x]);	}
int main(){
	n=read();	m=read();
	For(i,1,m)	p[i].x=read(),p[i].y=read(),p[i].w=read();
	sort(p+1,p+m+1,cmp);
	For(i,1,n)	fa[i]=i;
	For(i,1,m){
		ll x=find(p[i].x),y=find(p[i].y);
		if (x!=y){
			if (!vis[x]||!vis[y])	fa[x]=y,vis[y]|=vis[x],ans+=p[i].w;
		}else	if (!vis[x])	vis[x]=1,ans+=p[i].w;
	}writeln(ans);
}
/*
 :Ni ti , pi, k
 , w().
*/