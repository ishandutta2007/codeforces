#include <bits/stdc++.h>
#define modp 1000000007
#define Maxn 507
using namespace std;
int n,a[Maxn][Maxn],d[Maxn][Maxn],f[Maxn][Maxn];
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for (int i=0;i<n;i++)
		d[i][i]=1,f[i][i]=1;
	for (int len=2;len<=n;len++)
		for (int i=0;i<n;i++)
		{
			int j=(i+len-1)%n;
			for (int k=i;k!=j;k=(k+1)%n)
			{
				if (a[i][j]) d[i][j]=(d[i][j]+1LL*f[i][k]*f[(k+1)%n][j])%modp;
				f[i][j]=(f[i][j]+1LL*d[i][(k+1)%n]*f[(k+1)%n][j])%modp;
			}
		}
	printf("%d\n",f[0][n-1]);
	return 0;
}