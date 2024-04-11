#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n,a[51][51],r1,c1,r2,c2,len1,len2,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
std::pair<int,int>a1[2501],a2[2501];
bool vis[51][51];
void dfs1(int x,int y)
{
	vis[x][y]=1;
	a1[++len1]=std::make_pair(x,y);
	for(int i=0;i<4;i++)
	{
		int tox=x+dx[i],toy=y+dy[i];
		if(!vis[tox][toy]&&!a[tox][toy]&&tox>0&&tox<=n&&toy>0&&toy<=n)
		{
			dfs1(tox,toy);
		}
	}
}
void dfs2(int x,int y)
{
	vis[x][y]=1;
	a2[++len2]=std::make_pair(x,y);
	for(int i=0;i<4;i++)
	{
		int tox=x+dx[i],toy=y+dy[i];
		if(!vis[tox][toy]&&!a[tox][toy]&&tox>0&&tox<=n&&toy>0&&toy<=n)
		{
			dfs2(tox,toy);
		}
	}
}
long long calc(std::pair<int,int>x,std::pair<int,int>y)
{
	return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}
void checkmin(long long &x,long long y)
{
	if(x>y)
	{
		x=y;
	}
}
int main()
{
	scanf("%d%d%d%d%d\n",&n,&r1,&c1,&r2,&c2);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char c=getchar();
			a[i][j]=c-'0';
		}
		getchar();
	}
	dfs1(r1,c1);
	dfs2(r2,c2);
	long long ans=1e18;
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			checkmin(ans,calc(a1[i],a2[j]));
		}
	}
	printf("%lld",ans);
	return 0;
}