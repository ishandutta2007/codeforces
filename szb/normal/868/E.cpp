#include<cstdio> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#include<ctime> 
using namespace std; 
#define ll long long 
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=60,inf=1LL<<30;
ll f[2][N],dfn[N],ff[N][N][N][N],head[N],nxt[N<<1],vet[N<<1],val[N<<1],sz[N],dis[N][N],n,m,tot,rt;
void insert(ll x,ll y,ll w){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	val[tot]=w;	}
void dfs(ll x,ll pre){	for(ll i=head[x];i;i=nxt[i])	if (vet[i]^pre)	dfs(vet[i],x),sz[x]+=sz[vet[i]];	}
ll dp(ll x,ll y,ll a,ll b){
	ll &ans=ff[x][y][a][b];
	if (ans!=-1)	return ans;
	if (!a&&!b)		return 0;
	if (!a)			return inf;
	if (dfn[y]==1)	return (ans=dp(y,x,b,0)+dis[x][y]);
	for(ll i=head[y];i;i=nxt[i])	if (vet[i]^x)
	For(j,0,a)	dp(y,vet[i],j,a+b-j);
	ll cur=0,now=1;	memset(f[cur],0,sizeof f[cur]);
	f[cur][0]=inf;
	for(ll i=head[y];i;i=nxt[i])	if (vet[i]^x){
		memset(f[now],0,sizeof f[now]);
		For(j,0,a)	For(k,0,a-j)	f[now][j+k]=max(f[now][j+k],min(f[cur][j],dp(y,vet[i],k,a+b-k)));
		cur^=1;	now^=1;
	}return ans=dis[x][y]+f[cur][a];
}
int main(){
	n=read();
	For(i,2,n){
		ll x=read(),y=read(),w=dis[x][y]=dis[y][x]=read();
		insert(x,y,w);	insert(y,x,w);
		++dfn[x];	++dfn[y];
	}rt=read();	m=read();
	For(i,1,m)	sz[read()]++;
	dfs(rt,0);	ll ans=inf;
	memset(ff,-1,sizeof ff);
	for(ll i=head[rt];i;i=nxt[i])	ans=min(ans,dp(rt,vet[i],sz[vet[i]],m-sz[vet[i]]));
	writeln(ans);
}
/*
4
1 2 2
1 3 1
1 4 1
2
4
3 1 4 1
*/