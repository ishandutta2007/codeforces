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

int n, P[200005], dp[200005];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", P+i);
		P[i]+=P[i-1];
	}
	dp[n-1]=P[n];
	for(int i=n-2; i>0; i--)
		dp[i]=max(dp[i+1], P[i+1]-dp[i+1]);
	printf("%d\n", dp[1]);
	return 0;
}