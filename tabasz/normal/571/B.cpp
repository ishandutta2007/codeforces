#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 

int n, k;
vector<int> V;
LL dp[5005][5005];



int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n >> k;
	for(int i=0; i<n; i++)
	{
		int a;
		cin>> a;
		V.PB(a);
	}
	sort(V.begin(), V.end());
	int l=n/k;
	for(int i=0; i<=k-n%k; i++)
	{
		for(int j=0; j<=n%k; j++)
		{
			int a=i*l+j*(l+1);
		//	printf("%d %d %d\n", i, j, a);
			dp[i][j]=1000000000000000000LL;
			if(i>0)
				dp[i][j]=min(dp[i-1][j]+V[a-1]-V[a-l], dp[i][j]);
			if(j>0)
				dp[i][j]=min(dp[i][j-1]+V[a-1]-V[a-l-1], dp[i][j]);
			if(i==0 && j==0)
				dp[i][j]=0;
		}
	}
	cout<< dp[k-n%k][n%k] << '\n';
	return 0;
}