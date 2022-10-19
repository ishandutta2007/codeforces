#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int dis[N*2];
char mp[N][N];
vector<int>e[N*2];
queue<int>q;
int main()
{
	int n,m,flag=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='#')
			{
				e[i].push_back(n+j);
				e[n+j].push_back(i);
			}
		}
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		if(k==n)
		{
			printf("%d\n",dis[n]);
			flag=1;
			break;
		}
		for(int i=0;i<e[k].size();i++)
		{
			if(dis[e[k][i]]>dis[k]+1)
			{
				dis[e[k][i]]=dis[k]+1;
				q.push(e[k][i]);
			}
		}
	}
	if(!flag)
		printf("-1\n");
	return 0;
}
//