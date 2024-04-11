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
int n,m,col[503],d[503];
bool e[503][503];
int ff[503];
int gf(int x)
{
	return ff[x]?ff[x]=gf(ff[x]):x;
}
bool vis[503];
void dfs(int x,int dep)
{
	vis[x]=1; col[x]=dep%2;
	for(int i=1;i<=n;i++)
	{
		if(!e[x][i]&&!vis[i]) dfs(i,dep+1);
	}
}
int main()
{
	memset(ff,0,sizeof(ff));
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("Yes\na\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		e[a][b]=e[b][a]=1;
		++d[a]; ++d[b];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(e[i][j]) continue;
			int ga=gf(i),gb=gf(j);
			if(ga!=gb) ff[ga]=gb;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(gf(i)!=i) continue;
		dfs(i,0);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(!e[i][j])
			{
			if(col[i]==col[j])
			{
				printf("No\n");
				return 0;
			}
			}
			else
			{
			if((n-1!=d[i]&&n-1!=d[j])&&((col[i]&&!col[j])||(col[j]&&!col[i])))
			{
				printf("No\n");
				return 0;
			}
			}
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++) if(n-1==d[i]) putchar('b'); else if(col[i]) putchar('a'); else putchar('c');
	putchar(10);
}