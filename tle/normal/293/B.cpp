#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
ll MOD=1000000007;
#define SZ 233
int n,m,K,st[SZ][SZ],bl[SZ],a[SZ][SZ];
ll ans=0;
bool uf[SZ];
ll p[SZ][SZ];
void dfs(int x,int y,int tot)
{
	if(tot>K) return;
	if(y>m) {++x; y=1;}
	if(x>n)
	{
		int free=0;
		for(int i=1;i<=tot;i++) free+=!uf[i];
		ans+=p[K-(tot-free)][free];
		ans%=MOD;
		return;
	}
	st[x][y]=st[x-1][y]|st[x][y-1];
	if(a[x][y])
	{
		int cur=a[x][y];
		if(bl[cur])
		{
			if(st[x][y]&(1<<bl[cur])) return;
			st[x][y]^=1<<bl[cur];
			dfs(x,y+1,tot);
			st[x][y]^=1<<bl[cur];
		}
		else for(int i=1;i<=tot+1;i++)
		{
			if(!(st[x][y]&(1<<i))&&!uf[i])
			{
				st[x][y]^=1<<i;
				uf[i]=1; bl[cur]=i;
				dfs(x,y+1,max(tot,i));
				st[x][y]^=1<<i;
				uf[i]=0; bl[cur]=0;
			}
		}
	}
	else for(int i=1;i<=tot+1;i++)
	{
		if(!(st[x][y]&(1<<i)))
		{
			st[x][y]^=1<<i;
			dfs(x,y+1,max(tot,i));
			st[x][y]^=1<<i;
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	if(n+m-1>K) {printf("0\n"); return 0;}
	for(int i=0;i<=K;i++)
	{
		for(int j=0;j<=i;j++)
		{
			p[i][j]=1;
			for(int g=i;g>=i-j+1;g--) p[i][j]=p[i][j]*g%MOD;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	dfs(1,1,0);
	printf("%d\n",(int)(ans%MOD));
}