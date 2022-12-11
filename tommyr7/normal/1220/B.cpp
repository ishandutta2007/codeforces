#include <bits/stdc++.h>
using namespace std;
#define Maxn 1007
long long a[Maxn][Maxn];
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	a[1][1]=(1LL*a[1][n]*a[2][1])/a[2][n];
	for (int i=2;i<=n;i++)
		a[i][i]=(1LL*a[1][i]*a[i][1])/a[1][1];
	for (int i=1;i<=n;i++)
		printf("%d ",(int)sqrt(a[i][i]));
	printf("\n");
	return 0;
}