#include <bits/stdc++.h>
using namespace std;
int n,m;
bool vis[105];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
			int y;
			scanf("%d",&y);
			vis[y]=true;
		}
	}
	for(int i=1;i<=m;i++)
		if(!vis[i])
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}