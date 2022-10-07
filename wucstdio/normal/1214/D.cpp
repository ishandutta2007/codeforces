#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
char _s[2000005],*s[1000005];
bool _flag1[2000005],*flag1[1000005];
bool _flag2[2000005],*flag2[1000005];
bool _flag[2000005],*flag[1000005];
int n,m;
queue<int>qx,qy;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",_s+1+(i-1)*m);
		s[i]=_s+(i-1)*m;
		flag1[i]=_flag1+(i-1)*m;
		flag2[i]=_flag2+(i-1)*m;
		flag[i]=_flag+(i-1)*m;
	}
	flag[1][1]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(s[i][j]=='#')flag[i][j]=0;
		if(flag[i][j])
		{
			if(i<n)flag[i+1][j]=1;
			if(j<m)flag[i][j+1]=1;
		}
	}
	if(!flag[n][m])
	{
		printf("0\n");
		return 0;
	}
	for(int i=n;i>=1;i--)
	for(int j=m;j>=1;j--)
	{
		if(i==n&&j==m)continue;
		if(i==n&&s[i][j+1]=='#')s[i][j]='#';
		if(j==m&&s[i+1][j]=='#')s[i][j]='#';
		if(i!=n&&j!=m&&s[i+1][j]=='#'&&s[i][j+1]=='#')s[i][j]='#';
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i==1&&j==1)continue;
		if(i==1&&s[i][j-1]=='#')s[i][j]='#';
		if(j==1&&s[i-1][j]=='#')s[i][j]='#';
		if(i!=1&&j!=1&&s[i-1][j]=='#'&&s[i][j-1]=='#')s[i][j]='#';
	}
	for(int i=1;i<=m;i++)
	{
		if(s[n][i]=='#')
		{
			flag1[n][i]=1;
			qx.push(n);
			qy.push(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i][1]=='#')
		{
			flag1[i][1]=1;
			qx.push(i);
			qy.push(1);
		}
	}
	while(!qx.empty())
	{
		int x=qx.front();
		int y=qy.front();
		qx.pop();
		qy.pop();
		for(int k=0;k<8;k++)
		{
			int xx=x+dx[k];
			int yy=y+dy[k];
			if(xx>n||xx<1||yy>m||yy<1||(xx==1&&yy==1)||(xx==n&&yy==m))continue;
			if(flag1[xx][yy])continue;
			if(s[xx][yy]=='.')continue;
			flag1[xx][yy]=1;
			qx.push(xx);
			qy.push(yy);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(s[1][i]=='#')
		{
			flag2[1][i]=1;
			qx.push(1);
			qy.push(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i][m]=='#')
		{
			flag2[i][m]=1;
			qx.push(i);
			qy.push(m);
		}
	}
	while(!qx.empty())
	{
		int x=qx.front();
		int y=qy.front();
		qx.pop();
		qy.pop();
		for(int k=0;k<8;k++)
		{
			int xx=x+dx[k];
			int yy=y+dy[k];
			if(xx>n||xx<1||yy>m||yy<1||(xx==1&&yy==1)||(xx==n&&yy==m))continue;
			if(flag2[xx][yy])continue;
			if(s[xx][yy]=='.')continue;
			flag2[xx][yy]=1;
			qx.push(xx);
			qy.push(yy);
		}
	}
	int ans=2;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i==1&&j==1)continue;
		if(i==n&&j==m)continue;
		if(flag1[i][j]&&flag2[i][j])
		{
			printf("0\n");
			return 0;
		}
		bool f1=0,f2=0;
		for(int k=0;k<8;k++)
		{
			int x=i+dx[k];
			int y=j+dy[k];
			if(x>n||x<1||y>m||y<1||(x==1&&y==1)||(x==n&&y==m))continue;
			if(flag1[x][y])f1=1;
			if(flag2[x][y])f2=1;
		}
		if(f1&&f2)ans=1;
		if(f1&&(i==1||j==m))ans=1;
		if(f2&&(i==n||j==1))ans=1;
	}
	if(n==1||m==1)ans=min(ans,1);
	printf("%d\n",ans);
	return 0;
}