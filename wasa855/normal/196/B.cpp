#include<bits/stdc++.h>
using namespace std;
int mapp[1505][1505];//0 : # ; 1 : . ; 2 : S
int n,m;
char read()
{
	char t=getchar();
	while(t!='#'&&t!='.'&&t!='S')
	{
		t=getchar();
	}
	return t;
}
int used[1505][1505][3];// 0 yes or no ; 1 x zhou ; 2 y zhou
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
bool ok;
void dfs(int x,int y,int rx,int ry)
{
//	printf("%d %d %d %d\n",x,y,rx,ry);
	if(used[x][y][0]==true&&(used[x][y][1]!=rx||used[x][y][2]!=ry))
	{
		ok=true;
		return ;
	}
	if(used[x][y][0]==true&&(used[x][y][1]==rx&&used[x][y][2]==ry))
	{
		return ;
	}
	used[x][y][0]=true;
	used[x][y][1]=rx;
	used[x][y][2]=ry;
	for(int i=1;i<=4;i++)
	{
		int tx=(x+dx[i]+n)%n;
		int ty=(y+dy[i]+m)%m;
//		printf("%d %d\n",tx,ty);
		if(mapp[tx][ty]==0)
		{
			continue;
		}
		dfs(tx,ty,rx+dx[i],ry+dy[i]);
	}
}
int main()
{
	cin>>n>>m;
	char t;
	int bx,by;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			t=read();
			if(t=='#')
			{
				mapp[i][j]=0;
			}
			else if(t=='.')
			{
				mapp[i][j]=1;
			}
			else
			{
				mapp[i][j]=2;
				bx=i;
				by=j;
			}
		}
	}
	dfs(bx,by,bx,by);
	if(ok==true)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}