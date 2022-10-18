#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool ok[1005][1005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i+1][j]=='#'&&a[i+1][j-1]=='#'&&a[i+1][j+1]=='#'&&a[i][j+1]=='#'&&a[i][j-1]=='#'&&a[i-1][j]=='#'&&a[i-1][j-1]=='#'&&a[i-1][j+1]=='#')
			{
				ok[i+1][j]=true;
				ok[i+1][j-1]=true;
				ok[i+1][j+1]=true;
				ok[i][j+1]=true;
				ok[i][j-1]=true;
				ok[i-1][j]=true;
				ok[i-1][j-1]=true;
				ok[i-1][j+1]=true;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#'&&ok[i][j]==false)
			{
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n";
	return 0;
}
//asdf