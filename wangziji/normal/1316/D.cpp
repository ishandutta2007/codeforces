#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
char ans[1005][1005];
int x[1005][1005],y[1005][1005];
int fx[4]={1,-1,0,0},fy[4]={0,0,1,-1};
char ANS[4]={'U','D','L','R'};
queue <pair<int,int> > q;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d",&x[i][j],&y[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i][j]==i&&y[i][j]==j) ans[i][j]='X',q.push({i,j});
			while(!q.empty())
			{
				int X=q.front().first,Y=q.front().second;
				q.pop();
			//	cout << X << " " << Y << "   :   ";
				for(int k=0;k<=3;k++)
				{
					int nx=X+fx[k],ny=Y+fy[k];
			//		cout << ANS[k]<< nx << " " << ny << "    "; 
					if(x[nx][ny]==i&&y[nx][ny]==j&&!ans[nx][ny])
						ans[nx][ny]=ANS[k],q.push({nx,ny});
				}
			//	cout << endl;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i][j]==-1&&y[i][j]==-1)
			{
				if(x[i-1][j]==-1)
					ans[i][j]='U';
				if(x[i+1][j]==-1)
					ans[i][j]='D';
				if(x[i][j-1]==-1)
					ans[i][j]='L';
				if(x[i][j+1]==-1)
					ans[i][j]='R';
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!ans[i][j])
			{
				puts("INVALID");
				return 0;
			}
		}
	}
	puts("VALID");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout << ans[i][j];
		}
		cout << "\n";
	}
	return 0;
}