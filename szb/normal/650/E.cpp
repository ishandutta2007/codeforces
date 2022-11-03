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
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define ld double
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=500010;
struct data{	ll x,y,z,w;	}ans[N];
vector<ll>to[2][N];
ll f[N],fa[2][N],cnt,n;
ll find(ll x){	return x==f[x]?x:f[x]=find(f[x]);	}
void dfs(ll id,ll x){
	for(ll i=0;i<to[id][x].size();i++)
	if (to[id][x][i]!=fa[id][x])	fa[id][to[id][x][i]]=x,dfs(id,to[id][x][i]);
}
void Dfs(ll x){
	for(ll i=0;i<to[0][x].size();i++)
	if (to[0][x][i]!=fa[0][x]){
		ll u=to[0][x][i];
		Dfs(u);
		if (u!=fa[1][x]&&x!=fa[1][u])		ans[++cnt]=(data){u,x,find(u),fa[1][find(u)]};
	}
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	For(id,0,1)	For(i,2,n){
		ll x=read(),y=read();
		to[id][x].push_back(y);
		to[id][y].push_back(x);
	}
	dfs(0,1);	dfs(1,1);
	For(i,2,n){
		ll x=fa[1][i];
		f[i]=fa[0][i]==x||fa[0][x]==i?x:i;
	}Dfs(1);
	writeln(cnt);
	For(i,1,cnt)	printf("%d %d %d %d\n",ans[i].x,ans[i].y,ans[i].z,ans[i].w);
}
/*

*/