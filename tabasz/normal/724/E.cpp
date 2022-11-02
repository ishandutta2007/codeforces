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

int n;
LL T[2][10004], dp[2][10004], c, res=1000000000000000000LL;

int main()
{
  ios_base::sync_with_stdio(0);
  cin>> n >> c;
  for(int j=0; j<2; j++)
    for(int i=1; i<=n; i++)
	    cin>> T[j][i];
	for(int i=1; i<=n; i++)
	{
	  dp[i%2][0]=dp[(i+1)%2][0]+T[0][i];
	//  printf("%d, 0: %d\n", i, dp[i%2][0]);
	  for(int j=1; j<=i; j++)
	  {
	    if(j<i)
	      dp[i%2][j]=min(dp[(i+1)%2][j-1]+T[1][i], dp[(i+1)%2][j]+T[0][i]+c*j);
	    else
	      dp[i%2][j]=dp[(i+1)%2][j-1]+T[1][i];
	   // printf("%d, %d: %d\n", i, j, dp[i%2][j]);
	  }
	}
	for(int i=0; i<=n; i++)
	  res=min(res, dp[n%2][i]);
	cout<< res << '\n';
	return 0;
}