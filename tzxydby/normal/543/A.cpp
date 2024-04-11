#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N],dp[N][N];
int main()
{
	int n,m,b,mod;
	scanf("%d%d%d%d",&n,&m,&b,&mod);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for(int i=0;i<=b;i++) 
		dp[0][i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=a[i];k<=b;k++) 
				dp[j][k]=(dp[j][k]+dp[j-1][k-a[i]])%mod;
	printf("%d\n",dp[m][b]);
	return 0;
}