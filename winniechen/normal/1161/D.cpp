#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <map>
using namespace std;
#define N 1005
#define ll long long
#define mod 998244353
struct node{int to,next,val;}e[N*10];
char s[N];int n,head[N<<1],cnt,dis[N<<1],vis[N<<1],flag;
void add(int x,int y,int z){e[cnt]=(node){y,head[x],z};head[x]=cnt++;}
void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(!vis[to1])dis[to1]=dis[x]^e[i].val,dfs(to1);
		else if(dis[to1]!=(dis[x]^e[i].val))flag=0;
	}
}
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);int ans=0;
	if(s[n]=='1')return puts("0"),0;
	for(int i=2;i<=n;i++)
	{
		int la=n-i+1,tot=0;cnt=0;
		memset(dis,0,sizeof(dis));memset(head,-1,sizeof(head));memset(vis,0,sizeof(vis));flag=1;
		for(int j=1;j<=n;j++)if(s[j]=='0'||s[j]=='1')add(j,j+n,s[j]-'0'),add(j+n,j,s[j]-'0');
		for(int j=1;j<=n;j++)add(j,n-j+1,0);for(int j=1;j<=la;j++)add(j+n+i-1,n+la-j+i,0);
		for(int j=1;j<i;j++)
			if(!vis[j+n])dis[j+n]=0,dfs(j+n);else if(dis[j+n]!=0)flag=0;
		if(!vis[i+n])dis[i+n]=1,dfs(i+n);else if(dis[i+n]!=1)flag=0;
		// printf("%d %d\n",i,flag);
		for(int j=1;j<=n+n;j++)if(!vis[j])tot++,dfs(j);
		if(flag)ans=(ans+q_pow(2,tot))%mod;
	}
	printf("%d\n",ans);
}