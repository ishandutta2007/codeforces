#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n;
int p[maxn];
bool vis[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)
	{
		int u=i;
		memset(vis,0,sizeof(vis));
		while(!vis[u])vis[u]=1,u=p[u];
		printf("%d ",u);
	}
	return 0;
}