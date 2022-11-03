#include<algorithm>
#include<cmath>
#include<memory.h>
#include<cstdio>
#include<map>
#include<queue>
#define ll long long
#define maxn 100010
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pa pair<ll,ll>
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
void writeln(ll x){ write(x);   puts("");   }
const ll block=256;
ll nxt[maxn],head[maxn],vet[maxn],a[maxn],dep[maxn],fa[maxn],tot,n,Q,f[maxn][256],anc[maxn];
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
void dfs(ll x){
	for(ll i=head[x];i;i=nxt[i])
	if (vet[i]^fa[x])	dep[vet[i]]=dep[x]+1,fa[vet[i]]=x,dfs(vet[i]);
	if (dep[x]>=block){
		ll cur=x,v;
		For(i,0,block-1)	v=(i^a[cur])>>8,f[x][v^255]=max(f[x][v^255],255<<8|(i^a[cur])),cur=fa[cur];
		anc[x]=cur;
		For(j,0,7)	For(i,0,block-1)	if (!~f[x][i]&&~f[x][i^1<<j])	f[x][i]=f[x][i^1<<j]^block<<j;
	}
}
int main(){
	memset(f,-1,sizeof f);
	n=read();	Q=read();
	For(i,1,n)	a[i]=read();
	For(i,2,n){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}dfs(dep[1]=1);
	while(Q--){
		ll u=read(),v=read(),t=dep[v]-dep[u]+1,cur=v,ans=0;
		for(ll i=0;i<t/block;i++)	ans=max(ans,f[cur][i]),cur=anc[cur];
		for(ll i=t/block*block;i<t;i++)	ans=max(ans,a[cur]^i),cur=fa[cur];
		writeln(ans);
	}
}
/*
max(a[i]^dis(i,v))

8 
8
f[x][i]xi*256
max(a[j]^dis(x,j)^(i*256))
i*256
  
*/