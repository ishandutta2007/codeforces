#include<bits/stdc++.h>
using namespace std; 
#define ll int
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define fi first
#define se second
#define max(x,y)	x<y?y:x
#define min(x,y)	x<y?x:y
typedef complex<double> E;
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=5010;
vector<ll>g[2][N];
bool vis[2][N];
ll n,m,x[N],y[N],dis[N];
void dfs(ll x,ll tp){	if (vis[tp][x])	return;	vis[tp][x]=1;	rep(i,0,g[tp][x].size())	dfs(g[tp][x][i],tp);	}
int main(){
	n=read();	m=read();
	For(i,1,m){
		x[i]=read();	y[i]=read();
		g[0][x[i]].push_back(y[i]);
		g[1][y[i]].push_back(x[i]);
	}dfs(1,0);	dfs(n,1);
	memset(dis,60,sizeof dis);	dis[1]=0;
	For(t,1,n*2+1)	For(i,1,m)	if (vis[0][x[i]]&&vis[1][y[i]])
		dis[y[i]]=min(dis[y[i]],dis[x[i]]+2),
		dis[x[i]]=min(dis[x[i]],dis[y[i]]-1);
	For(i,1,m)	if (vis[0][x[i]]&&vis[1][y[i]]&&(dis[x[i]]+2<dis[y[i]]||dis[x[i]]+1>dis[y[i]]))	return puts("No"),0;
	puts("Yes");
	For(i,1,m)	writeln(max(min(2,dis[y[i]]-dis[x[i]]),1));
}