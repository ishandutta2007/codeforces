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

bool B[1001];
int n, k, mini=1000, maxi;
int dp[1000005];
vector<int> V;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		mini=min(mini, a);
		B[a]=1;
		maxi=max(maxi, a);
	}
	for(int i=mini+1; i<=maxi; i++)
		if(B[i])
			V.PB(i-mini);
	maxi-=mini;
	maxi*=k;
	printf("%d ", mini*k);
	for(int i=1; i<=maxi; i++)
	{
		dp[i]=1000000;
		for(int j=0; j<(int)V.size(); j++)
		{
			if(i<V[j])
				break;
			dp[i]=min(dp[i], dp[i-V[j]]+1);
		}
		if(dp[i]<=k)
			printf("%d ", mini*k+i);
	}
	printf("\n");
	return 0;
}