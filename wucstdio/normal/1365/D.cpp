#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int t,n,m;
char s[55][55];
bool f[55][55];
queue<int>qx,qy;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		  scanf("%s",s[i]+1);
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]!='B')continue;
				for(int k=0;k<4;k++)
				{
					int x=i+dx[k];
					int y=j+dy[k];
					if(x>n||x<1||y>m||y<1)continue;
					if(s[x][y]=='G')
					{
						flag=0;
						break;
					}
					if(s[x][y]=='B')continue;
					s[x][y]='#';
				}
			}
		}
		if(s[n][m]!='#')
		{
			qx.push(n);
			qy.push(m);
			f[n][m]=1;
		}
		while(!qx.empty())
		{
			int x=qx.front();
			int y=qy.front();
			qx.pop();
			qy.pop();
			for(int k=0;k<4;k++)
			{
				int xx=x+dx[k];
				int yy=y+dy[k];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&(s[xx][yy]=='.'||s[xx][yy]=='G')&&!f[xx][yy])
				{
					f[xx][yy]=1;
					qx.push(xx);
					qy.push(yy);
				}
			}
		}
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		    if(s[i][j]=='G'&&!f[i][j])
		      flag=0;
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}