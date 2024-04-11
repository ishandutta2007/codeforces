#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int b[505][505];
map<int,int> mp[1005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			mp[i+j-1][a[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&b[i][j]);
			mp[i+j-1][b[i][j]]--;
			if(mp[i+j-1][b[i][j]]<0)
			{
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n";
	return 0;
}