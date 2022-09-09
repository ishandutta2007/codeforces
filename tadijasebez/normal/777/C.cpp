#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<vector<int> > dp,a;
int best[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	a.resize(n+5);dp.resize(n+5);
	for(i=0;i<n+5;i++) a[i].resize(m+5),dp[i].resize(m+5);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%i",&a[i][j]);
			if(i==1 || a[i-1][j]>a[i][j]) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j]+1;
			best[i]=max(best[i],dp[i][j]);
		}
	}
	int q,l,r;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		if(best[r]>=(r-l+1)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}