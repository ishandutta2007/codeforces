#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000050;
const ll inf=1e18;
ll dp[N][3][3];
int a[N],b[N];
int main()
{
	int n,i,j,k,l,m;
	scanf("%i %i",&m,&n);
	for(i=1;i<=m;i++) scanf("%i",&b[i]),a[b[i]]++;
	for(i=1;i<=n;i++) for(j=0;j<3;j++) for(k=0;k<3;k++) dp[i][j][k]=-inf;
	dp[0][0][0]=0;
	for(i=1;i<=n;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				for(l=0;l<3;l++)
					if(j+k+l<=a[i])
						dp[i][k][l]=max(dp[i][k][l],dp[i-1][j][k]+l+(a[i]-l-k-j)/3);
	printf("%lld\n",dp[n][0][0]);
	return 0;
}