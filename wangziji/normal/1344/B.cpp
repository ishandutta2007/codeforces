#include <iostream>
#include <queue>
using namespace std;
int a[1005][1005],hang[1005],lie[1005];
int vis[1005][1005],fa[1000005];
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
int n,m;
inline int id(int x,int y)
{
	return (x-1)*m+y;
}
int main(int argc, char** argv) {
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin >> c;
			if(c=='#') a[i][j]=hang[i]=lie[j]=1;
		}
	}
	int flag1=0,flag2=0;
	for(int i=1;i<=n;i++) flag1|=hang[i]==0;
	for(int i=1;i<=m;i++) flag2|=lie[i]==0;
	if(flag1^flag2)
	{
		puts("-1");
		return 0;
	}
	int qwq=1;
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1&&flag==2)
				qwq=0;
			if(a[i][j]==1&&flag<=1)
				flag=1;
			if(a[i][j]==0&&flag>=1)
				flag=2;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]==1&&flag==2)
				qwq=0;
			if(a[i][j]==1&&flag<=1)
				flag=1;
			if(a[i][j]==0&&flag>=1)
				flag=2;
		}
	}
	if(!qwq)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n*m;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]&&a[i+1][j])
				fa[ff(id(i,j))]=ff(id(i+1,j));
			if(a[i][j]&&a[i-1][j])
				fa[ff(id(i,j))]=ff(id(i-1,j));
			if(a[i][j]&&a[i][j+1])
				fa[ff(id(i,j))]=ff(id(i,j+1));
			if(a[i][j]&&a[i][j-1])
				fa[ff(id(i,j))]=ff(id(i,j-1));
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) ans+=a[i][j]&(ff(id(i,j))==id(i,j));
	cout << ans;
	return 0;
}