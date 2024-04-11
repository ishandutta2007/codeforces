#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,d,x,y,flag;
int vis[N];
vector<pair<int,int>>e;
void dfs(int k)
{
	if(k==y)
	{
		flag=1;
		return;
	}
	vis[k]=1;
	for(int i=1;i<e.size();i++)
		if(!vis[i])
			if((e[k].first>e[i].first&&e[k].first<e[i].second)||(e[k].second>e[i].first&&e[k].second<e[i].second))
				dfs(i);
}
int main()
{
	e.push_back(make_pair(0,0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&d,&x,&y);
		if(d==1)
			e.push_back(make_pair(x,y));
		if(d==2)
		{
			memset(vis,0,sizeof(vis));
			flag=0;
			dfs(x);
			if(flag)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}
//