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

int n, a, b, t, res=1;
char C[500005];
int dp[2][500005];

int bins(int ind, int lef)
{
	int st=0, en=n-1, mid=(st+en)/2, r=-1000000000;
	while(st<=en)
	{
		if(dp[ind][mid]<=lef)
		{
			r=max(r, mid);
			st=mid+1;
		}
		else
			en=mid-1;
		mid=(st+en)/2;
	}
	return r;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d%d%s", &n, &a, &b, &t, C);
	t--;
	if(C[0]=='w')
		t-=b;
	if(t<0)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1; i<n; i++)
	{
		dp[0][i]=dp[0][i-1]+a+1;
		if(C[i]=='w')
			dp[0][i]+=b;
		//printf("%d: %d\n", i, dp[0][i]);
	}
	for(int i=n-1; i>0; i--)
	{
		dp[1][n-i]=dp[1][n-i-1]+a+1;
		if(C[i]=='w')
			dp[1][n-i]+=b;
		//printf("%d: %d\n", n-i, dp[0][n-i]);
	}
	for(int j=0; j<2; j++)
	{
		for(int i=0; i<n; i++)
		{
			int le=t-dp[j][i]-i*a;
			res=max(res, min(1+i+bins(1-j, le), n));
		}
	}
	printf("%d\n", res);
	return 0;
}