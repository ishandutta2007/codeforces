#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int n,m,ans,sum[1005][1005];
char s[1005][1005];
bool flag[1005][1005];
queue<int>qx,qy;
void bfs(int stx,int sty)
{
	qx.push(stx);
	qy.push(sty);
	flag[stx][sty]=1;
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
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&s[xx][yy]=='#'&&!flag[xx][yy])
			{
				flag[xx][yy]=1;
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
		  sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='#');
	}
	int num1=0,num2=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=m;
		while(l<=m&&s[i][l]!='#')l++;
		while(r>=1&&s[i][r]!='#')r--;
		if(l>r)
		{
			num1++;
			continue;
		}
		if(sum[i][r]-sum[i][l-1]-sum[i-1][r]+sum[i-1][l-1]!=r-l+1)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int l=1,r=n;
		while(l<=n&&s[l][i]!='#')l++;
		while(r>=1&&s[r][i]!='#')r--;
		if(l>r)
		{
			num2++;
			continue;
		}
		if(sum[r][i]-sum[l-1][i]-sum[r][i-1]+sum[l-1][i-1]!=r-l+1)
		{
			printf("-1\n");
			return 0;
		}
	}
	if((!num1&&num2)||(num1&&!num2))
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(s[i][j]=='#'&&!flag[i][j])
		  bfs(i,j),ans++;
	}
	printf("%d\n",ans);
	return 0;
}