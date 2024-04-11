#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
bool vis[1001][1001];
char str[1001][1001];
queue<int>que;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
signed main()
{
	int t,n,m,x,y,nx,ny;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)vis[i][j]=false;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(str[i][j]!='B')continue;
				for(int k=0;k<4;k++)
				{
					if(i+dx[k]<1||i+dx[k]>n||j+dy[k]<1||j+dy[k]>m)continue;
					if(str[i+dx[k]][j+dy[k]]=='.')str[i+dx[k]][j+dy[k]]='#';
				}
			}
		}
		if(str[n][m]=='.')que.push(n*m);
		while(!que.empty())
		{
			x=(que.front()-1)/m+1;
			y=(que.front()-1)%m+1;
			que.pop();
			for(int k=0;k<4;k++)
			{
				nx=x+dx[k];
				ny=y+dy[k];
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny]==0&&str[nx][ny]!='#')
				{
					vis[nx][ny]=true;
					que.push((nx-1)*m+ny);
				}
			}
		}
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(str[i][j]=='G'&&vis[i][j]==false)
				{
					flag=true;
					printf("NO\n");
					break;
				}
				if(str[i][j]=='B'&&vis[i][j]==true)
				{
					flag=true;
					printf("NO\n");
					break;
				}
			}
			if(flag==true)break;
		}
		if(flag==false)printf("YES\n");
	}
	return 0;
}