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
const ll N=200010;
vector<ll>g[N];	bool fl=0;
ll head[N],nxt[N],vet[N],dfn[N],cur[N],n,tot,vis[N],st[N];
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	++dfn[x];}
void dfs(ll x,ll pre){
	vis[x]=1;
	for(ll i=head[x];i;i=nxt[i])
	if (!vis[vet[i]]){
		if (dfn[vet[i]]>=3)	return;
		dfs(vet[i],x);
	}
}
void Dfs(ll x,ll pre){
	ll child=0;
	for(ll i=head[x];i;i=nxt[i])
	if (vet[i]!=pre&&(dfn[vet[i]]>0))	Dfs(vet[i],x),++child;
	if (child>1){
		puts("No");
		exit(0);
	}
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	For(i,2,n){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}
	For(i,1,n)	if (dfn[i]==1)	dfs(i,-1);
	memcpy(st,dfn,sizeof dfn);
	memset(dfn,0,sizeof dfn);
	For(x,1,n)	if (!vis[x]){
		for(ll i=head[x];i;i=nxt[i])
		if (!vis[vet[i]])	g[x].push_back(vet[i]),++dfn[vet[i]];
	}memcpy(cur,dfn,sizeof dfn);
	For(x,1,n)if (cur[x]==1&&st[x]==3){	dfn[x]--;		for(ll i=0;i<g[x].size();i++)	dfn[g[x][i]]--;	}
	For(x,1,n)	fl|=dfn[x]>0;
	ll cnt=0;
	For(x,1,n)	if (dfn[x]==1){
		Dfs(x,-1);
		puts("Yes");	return 0;
	}
	puts(fl?"No":"Yes");
}