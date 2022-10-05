#include <bits/stdc++.h>
using namespace std;
int n,m,a[2005][2005],nums[2005]; 
bool vis[2005];
int main()
{
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar()-'0';
			nums[j]+=a[i][j];
		}
		getchar();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
				if(nums[j]==1) goto A;
		}
		printf("YES");return 0;
		A:;
	}
	printf("NO");
	return 0;
}