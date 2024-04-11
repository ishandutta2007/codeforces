#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,sum[5005][5005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&sum[1][i]);
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		  sum[i][j]=sum[i-1][j-1]^sum[i-1][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		  sum[i][j]=max(sum[i][j],max(sum[i-1][j-1],sum[i-1][j]));
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",sum[r-l+1][r]);
	}
	return 0;
}