#include <bits/stdc++.h>
#define Maxn 5007
using namespace std;
int n,q;
int a[Maxn];
int ans[Maxn][Maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		ans[i][0]=a[i];
	for (int k=1;k<n;k++)
		for (int i=1;i+k<=n;i++)
			ans[i][k]=ans[i][k-1]^ans[i+1][k-1];
	for (int i=1;i<=n;i++)
		for (int k=1;k<=n-i;k++)
			ans[i][k]=max(ans[i][k],ans[i][k-1]);
	for (int j=1;j<=n;j++)
		for (int k=1;j-k>=1;k++)
			ans[j-k][k]=max(ans[j-k][k],ans[j-k+1][k-1]);
	scanf("%d",&q);
	while (q--)
	{
		int lx,rx;
		scanf("%d%d",&lx,&rx);
		printf("%d\n",ans[lx][rx-lx]);
	}
	return 0;
}