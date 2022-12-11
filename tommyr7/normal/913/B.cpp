#include <bits/stdc++.h>
#define Maxn 4007
using namespace std;
int n,f[Maxn],d[Maxn],g[Maxn];
bool vis[Maxn];
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&f[i]);
		++d[i];
		++d[f[i]];
	}
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=n;i++)
		if (d[i]==1) vis[i]=true;
	for (int i=2;i<=n;i++)
		if (vis[i]) ++g[f[i]];
	bool check=true;
	for (int i=1;i<=n;i++)
		if (g[i]<3&&!vis[i]) check=false;
	if (check) printf("Yes\n"); else printf("No\n");
	return 0;
}