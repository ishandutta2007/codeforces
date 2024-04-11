#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>path;
int vis[20][20],n;
void out()
{
	for(int i=0;i<path.size();i++)
		printf("%c%d ",path[i].second+'a'-1,path[i].first);
	printf("\n");
	exit(0);
}
void dfs(int x,int y,int s)
{
	path.push_back(make_pair(x,y));
	if(s==n-1)
	{
		if(x==8||y==8)
		{
			path.push_back(make_pair(8,8));
			out();
		}
		return;
	}
	for(int i=1;i<=8;i++)
	{
		if(!vis[x][i])
		{
			vis[x][i]=1;
			dfs(x,i,s+1);
			path.pop_back();
			vis[x][i]=0;
		}
	}
	for(int i=1;i<=8;i++)
	{
		if(!vis[i][y])
		{
			vis[i][y]=1;
			dfs(i,y,s+1);
			path.pop_back();
			vis[i][y]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	vis[1][1]=vis[8][8]=1;
	dfs(1,1,0);
	return 0;
}