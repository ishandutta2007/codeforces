#include<bits/stdc++.h>
using namespace std;
char a[105][105];
bool mapp[105][105];
int b[105][105];
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='*')
			{
				mapp[i][j]=true;
			}
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			printf("%c ",a[i][j]);
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i+1][j]=='*')
			{
				b[i][j]++;
			}
			if(a[i][j+1]=='*')
			{
				b[i][j]++;
			}
			if(a[i-1][j]=='*')
			{
				b[i][j]++;
			}
			if(a[i][j-1]=='*')
			{
				b[i][j]++;
			}
			if(a[i+1][j+1]=='*')
			{
				b[i][j]++;
			}
			if(a[i-1][j+1]=='*')
			{
				b[i][j]++;
			}
			if(a[i+1][j-1]=='*')
			{
				b[i][j]++;
			}
			if(a[i-1][j-1]=='*')
			{
				b[i][j]++;
			}
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",b[i][j]);
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]=='*')
			{
				continue;
			}
			if(a[i][j]=='.')
			{
				if(b[i][j]!=0)
				{
					cout<<"NO\n";
					return 0;
				}
			}
			else
			{
				if(a[i][j]-'0'!=b[i][j])
				{
					cout<<"NO\n";
					return 0;
				}
			}
		}
	}
	cout<<"YES\n";
	return 0;
}