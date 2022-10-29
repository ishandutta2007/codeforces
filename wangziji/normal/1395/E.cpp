#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#pragma GCC optimize 2
using namespace std;
vector <pair <int,int> > e[200005];
bitset <200005> s[10][10];
int D[200005];
int pd[10][10][10][10];
int ans=0,p[10],k;
inline void dfs(int x)
{
	if(x==k+1)
	{
		++ans;
		return ;
	}
	for(int i=1;i<=x;i++)
	{
		int flag=1;
		if(s[x][i][200001]) continue;
		for(int j=1;j<x;j++)
		{
			if(!pd[x][i][j][p[j]])
			{
				flag=0;
				break;
			}
		}
		if(flag) p[x]=i,dfs(x+1);
	}
}
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({w,v});
		++D[u];
	}
	for(int i=1;i<=n;i++)
	{
		sort(e[i].begin(),e[i].end());
		for(int j=0;j<e[i].size();j++)
		{
			if(s[D[i]][j+1][e[i][j].second]&&!s[D[i]][j+1][200001])
				s[D[i]][j+1][200001]=1;
			s[D[i]][j+1][e[i][j].second]=1;
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=i;j++)
		{
		//	cout << i << " " << j << " " << s[i][j] << "\n";
			for(int x=1;x<i;x++)
			{
				for(int y=1;y<=x;y++)
				{
					if((s[i][j]&s[x][y]).none())
					{
						pd[i][j][x][y]=1;
					//	cout << i << " " << j << " " <<  x<< " " << y << "\n";
					}
				}
			}
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}