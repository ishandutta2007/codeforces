#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
queue <pair <int,int> > q;
char a[100][100];
int fx[4]={-1,1,0,0};
int fy[4]={0,0,-1,1};
int vis[100][100];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,ans=1;
		cin >> n >> m;
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++)
				a[i][j]='#';
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin >> a[i][j];
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cnt+=a[i][j]=='G';
				if(a[i][j]=='B')
				{
					if(a[i-1][j]=='G'||a[i][j-1]=='G'||a[i][j+1]=='G'||a[i+1][j]=='G')
						ans=0;
					else
					{
						if(a[i-1][j]=='.') a[i-1][j]='#';
						if(a[i+1][j]=='.') a[i+1][j]='#';
						if(a[i][j-1]=='.') a[i][j-1]='#';
						if(a[i][j+1]=='.') a[i][j+1]='#';
					}
				}
			}
		}
		if(!ans||a[n][m]=='#'&&cnt)
		{
			puts("No");
			continue;
		}
		q.push({n,m});
		vis[n][m]=1;
		while(!q.empty())
		{
			int x=q.front().first,y=q.front().second;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int nx=x+fx[i],ny=y+fy[i];
				if(vis[nx][ny]||a[nx][ny]=='#') continue;
				vis[nx][ny]=1;
				q.push({nx,ny});
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]=='G'&&!vis[i][j]) ans=0;
		if(!ans)
		{
			puts("No");
			continue;
		}
		puts("Yes");
	}
	return 0;
}