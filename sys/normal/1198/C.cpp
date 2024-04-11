#include <bits/stdc++.h>
using namespace std;
const int Maxn=500005;
int T,n,m;
bool vis[Maxn],edge[Maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int cnt=0;
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(bool[3*n+1]));
		memset(edge,0,sizeof(bool[m+1]));
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(!vis[a]&&!vis[b]) edge[i]=true,vis[a]=true,vis[b]=true;
		}
		for(int i=1;i<=3*n;i++)
			if(!vis[i]) cnt++;
		if(cnt>=n)
		{
			printf("IndSet\n");
			int t=0;
			for(int i=1;i<=3*n;i++)
			{
				if(!vis[i]) printf("%d ",i),t++;
				if(t==n) break;
			}
			printf("\n");
		}
		else
		{
			printf("Matching\n");
			int t=0;
			for(int i=1;i<=m;i++)
			{
				if(edge[i]) printf("%d ",i),t++;
				if(t==n) break;
			}
			printf("\n");
		}
	}
	return 0;	
}