#include<bits/stdc++.h>
using namespace std;
const int N=105,M=20005;
int n,a[N],p[M],dp[N][M];
vector<int>v;
void sol()
{
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int j=0;j<=20000;j++)
		dp[0][j]=-1;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=20000;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]&&dp[i-1][j-a[i]]>=0)
				dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+1);
		}
	}
	int mx=0,mp;
	for(int j=0;j<=20000;j++)
		if(p[j]&&dp[n][j]>mx)
			mx=dp[n][j],mp=j;
	v.clear();
	for(int i=n;i>=1;i--)
	{
		if(mp>=a[i]&&dp[i-1][mp-a[i]]==mx-1)
		{
			v.push_back(i);
			mx--;
			mp-=a[i];
		}
	}
	printf("%d\n",v.size());
	for(auto i:v)
		printf("%d ",i);
	puts("");
}
int main()
{
	for(int i=2;i<=20000;i++)
		for(int j=2;j*j<=i;j++)
			if(i%j==0)
				p[i]=1;
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}