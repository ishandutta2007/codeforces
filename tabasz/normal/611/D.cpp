#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
const LL mod=1e9+7;
const LL p=1e4+7;

int n;
LL P[5005], H[5005], dp[5005][5005], res;
char C[5005];

LL has(int ind, int l)
{
	LL r=H[ind+l-1]-(H[ind-1]*P[l])%mod;
	if(r<0)
		r+=mod;
	return r;
}

bool les(int ind1, int ind2, int l)
{
	if(has(ind1, l)==has(ind2, l))
		return false;
	int st=0, en=l, mid=(st+en)/2, r=0;
	while(st<=en)
	{
		if(has(ind1, mid)==has(ind2, mid))
		{
			r=max(r, mid);
			st=mid+1;
		}
		else
			en=mid-1;
		mid=(st+en)/2;
	}
	return (int)C[ind1+r-1]<(int)C[ind2+r-1];
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%s", &n, C);
	P[0]=1;
	for(int i=1; i<=n; i++)
	{
		P[i]=(P[i-1]*p)%mod;
		H[i]=(H[i-1]*p+(int)C[i-1])%mod;
	}
	dp[0][0]=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			if(C[i-j]=='0')
			{
				dp[i][j]=dp[i][j-1];
				continue;
			}
			if(j+j>i || !les(i-2*j+1, i-j+1, j))
				dp[i][j]=dp[i][j-1]+dp[i-j][min(j-1, i-j)];
			else
				dp[i][j]=dp[i][j-1]+dp[i-j][j];
			if(dp[i][j]>=mod)
				dp[i][j]-=mod;
		}
	}
	printf("%lld\n", dp[n][n]);
	return 0;
}