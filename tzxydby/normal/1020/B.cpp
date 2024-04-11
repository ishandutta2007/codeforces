#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int p[N],vis[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		int now=i;
		while(!vis[now])
		{
			vis[now]=1;
			now=p[now];
		}
		printf("%d ",now);
	}
	printf("\n");
	return 0;
}