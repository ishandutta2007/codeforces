#include<stdio.h>
#include<ctime>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<string>
#define pa pair<ll,ll>
#define ll int
#define lf else if
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll N=200010;
ll head[N],nxt[N],vet[N],fa[N],sz[N],low[N],dfn[N],q[N],top,ans,n,m,tot,ind,vis[N],mark[N],x[N],y[N];
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
void tarjan(ll x){
	low[x]=dfn[x]=++ind;	q[++top]=x;	vis[x]=1;
	for(ll i=head[x];i;i=nxt[i]){
		if (vis[vet[i]])	low[x]=min(low[x],dfn[vet[i]]);
		else	if (!dfn[vet[i]])	tarjan(vet[i]),low[x]=min(low[x],low[vet[i]]);
	}
	if (low[x]==dfn[x]){
		ll sz=0;
		while(q[top+1]!=x)	vis[q[top--]]=0,++sz;
		if (sz>1)	mark[x]=1;
	}
}
ll find(ll x){	return x==fa[x]?x:fa[x]=find(fa[x]);	}
int main(){
	n=read();	m=read();
	For(i,1,m){
		x[i]=read(),y[i]=read();
		insert(x[i],y[i]);
	}
	For(i,1,n)	if (!dfn[i])	tarjan(i);
	For(i,1,n)	fa[i]=i,sz[i]=1;
	For(i,1,m){
		ll xx=find(x[i]),yy=find(y[i]);
		fa[xx]=yy;	mark[yy]|=mark[xx] ;
		if (xx!=yy)	sz[yy]+=sz[xx];
	}
	For(i,1,n)	if (find(i)==i)	ans+=sz[i]-(1^mark[i]);
	writeln(ans);
}