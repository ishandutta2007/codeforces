#include<bits/stdc++.h>
using namespace std;
const int N=55;
int a[N][N],b[N][N];
vector<pair<int,int>>ans;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i][j]&&a[i][j+1]&&a[i+1][j]&&a[i+1][j+1])
			{
				b[i][j]=b[i][j+1]=b[i+1][j]=b[i+1][j+1]=1;
				ans.emplace_back(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				puts("-1");
				return 0;
			}
		}
	}
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%d %d\n",i.first,i.second);
	return 0;
}