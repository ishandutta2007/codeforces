#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
const int m=1000000007;

vector<int> V[2002];
int dp[2002][2002];


int main()
{
	//ios_base::sync_with_stdio(0);
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			if(i%j==0)
			{
				V[i].PB(j);
				//printf("%d %d\n", i, j);
			}
		}
	}
	for(int i=1; i<=n; i++) dp[1][i]=1;
	for(int i=2; i<=k; i++)
	{
		for(int j=1; j<=n; j++)
		{
			for(int k=0; k<V[j].size(); k++) dp[i][j]=(dp[i][j]+dp[i-1][V[j][k]])%m;
		}
	}
	int w=0;
	for(int i=1; i<=n; i++) w=(w+dp[k][i])%m;
	printf("%d\n", w);
	return 0;
}