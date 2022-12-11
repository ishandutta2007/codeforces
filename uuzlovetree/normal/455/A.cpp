#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int n;
int c[maxn];
ll dp[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
	    int x;
		scanf("%d",&x);
		c[x]++;
	}
	for(int i=1;i<=100000;++i)
	{
		dp[i]=max(dp[i-1],dp[i-2]+1ll*i*c[i]);
	}
	printf("%I64d\n",dp[100000]);
	return 0;
}