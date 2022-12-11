#include <bits/stdc++.h>
#define Maxn 157
using namespace std;
int a[Maxn][Maxn];
int n;
int main()
{
	memset(a,0,sizeof(a));
	a[0][0]=1,a[1][1]=1;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		a[i][0]=a[i-2][0];
		for (int j=1;j<=i;j++)
			a[i][j]=(a[i-1][j-1]+a[i-2][j])%2;
	}
	printf("%d\n",n);
	for (int i=0;i<=n;i++)
		printf("%d ",a[n][i]);
	printf("\n");
	printf("%d\n",n-1);
	for (int i=0;i<n;i++)
		printf("%d ",a[n-1][i]);
	printf("\n");
	return 0;
}