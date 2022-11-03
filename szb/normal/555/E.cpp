#include<queue>
#include<ctime>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#include<ctime>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define ld double
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=400010;
vector<ll>gg[N];
ll dep[N],fa[N][21],bel[N],head[N],nxt[N],vet[N],vis[N],low[N],dfn[N],q[N],bk[N],top,tot=1,ind,blk,cnt,f[N],g[N],n,m,Q;
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
void tarjan(ll x,ll pre){
	low[x]=dfn[x]=++ind;	vis[x]=1;	q[++top]=x;	bk[x]=blk;
	for(ll i=head[x];i;i=nxt[i]){
		if (!(i^pre^1))	continue;
		if (!dfn[vet[i]])	tarjan(vet[i],i),low[x]=min(low[x],low[vet[i]]);
		else	if (vis[vet[i]])	low[x]=min(low[x],dfn[vet[i]]);
	}
	if (low[x]==dfn[x]){
		++cnt;
		while(q[top+1]!=x)	bel[q[top]]=cnt,vis[q[top--]]=0;
	}
}
void dfs(ll x){
	vis[x]=1;
	For(i,1,20)	fa[x][i]=fa[fa[x][i-1]][i-1];
	for(ll i=0;i<gg[x].size();i++)
	if (gg[x][i]!=fa[x][0])	fa[gg[x][i]][0]=x,dep[gg[x][i]]=dep[x]+1,dfs(gg[x][i]);
}
ll lca(ll x,ll y){
	if (dep[x]<dep[y])	swap(x,y);
	ll t=dep[x]-dep[y];
	For(i,0,20)	if ((1<<i)&t)	x=fa[x][i];
	FOr(i,20,0)	if (fa[x][i]!=fa[y][i])	x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
void Dfs(ll x){
	for(ll i=0;i<gg[x].size();i++)
	if (gg[x][i]!=fa[x][0]){
		Dfs(gg[x][i]);
		f[x]+=f[gg[x][i]];
		g[x]+=g[gg[x][i]];
	}
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();	m=read();	Q=read();
	For(i,1,m){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}
	For(i,1,n)	if (!dfn[i])	++blk,tarjan(i,tot+1);
	For(x,1,n)	for(ll i=head[x];i;i=nxt[i])	if (bel[x]!=bel[vet[i]])	gg[bel[x]].push_back(bel[vet[i]]);
	For(i,1,cnt)	if (!vis[i])	dfs(i);
	while(Q--){
		ll x=read(),y=read();
		if (bk[x]!=bk[y])	return puts("No"),0;
		ll t=lca(bel[x],bel[y]);
		g[bel[x]]++;	g[t]--;
		f[bel[y]]++;	f[t]--;
	}
	For(i,1,cnt)	if (!dep[i])	Dfs(i);
	For(i,1,cnt)	if (f[i]&&g[i])	return puts("No"),0;
	puts("Yes");
}
/*
nmquvmuv<=2e5
*/