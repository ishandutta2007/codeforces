#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int b[505][505];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				x++;
			}
		}
		if(x%2!=0)
		{
			cout<<"No\n";
			return 0;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int x=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]!=b[i][j])
			{
				x++;
			}
		}
		if(x%2!=0)
		{
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}