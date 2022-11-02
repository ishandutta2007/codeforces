#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 

int n, res;
vector<int> V;
int dp[1000006];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		V.PB(a);
	}
	for(int i=0; i<n; i++)
	{
		dp[V[i]]=max(1, dp[V[i]]);
		res=max(res, dp[V[i]]);
		for(int j=2; V[i]*j<=1000000; j++)
			dp[V[i]*j]=max(dp[V[i]*j], dp[V[i]]+1);
	}
	printf("%d\n", res);
	return 0;
}