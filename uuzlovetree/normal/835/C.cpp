#include<bits/stdc++.h>
using namespace std;
int n,q,c;
int a[12][105][105],s[12][105][105];
bool vis[105][105];
vector<int> p[105][105];
int main()
{
	scanf("%d%d%d",&n,&q,&c);
	for(int i=1;i<=n;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[0][x][y]+=z;
		p[x][y].push_back(z);
		vis[x][y]=1;
	}
	for(int i=1;i<=c;++i)
		for(int x=1;x<=100;++x)
			for(int y=1;y<=100;++y)if(vis[x][y])
			{
				for(int j=0;j<p[x][y].size();++j)
				{
					p[x][y][j]++;
					p[x][y][j]%=(c+1);
					a[i][x][y]+=p[x][y][j];
				}
			}
	for(int i=0;i<=c;++i)
		for(int x=1;x<=100;++x)
			for(int y=1;y<=100;++y)s[i][x][y]=s[i][x-1][y]+s[i][x][y-1]-s[i][x-1][y-1]+a[i][x][y];
	while(q--)
	{
		int t,x,y,xx,yy;
		scanf("%d%d%d%d%d",&t,&x,&y,&xx,&yy);
		t%=(c+1);
		int ans=s[t][xx][yy]-s[t][x-1][yy]-s[t][xx][y-1]+s[t][x-1][y-1];
		printf("%d\n",ans);
	}
	return 0;
}