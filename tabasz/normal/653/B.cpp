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

int dp[10][10], T[10][10], n, m;

int main()
{
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
			T[i][j]=-1;
	ios_base::sync_with_stdio(0);
	dp[1][0]=1;
	cin>> n >> m;
	for(int i=0; i<m; i++)
	{
		string a, b;
		cin>> a >> b;
		T[(int)a[0]-(int)'a'][(int)a[1]-(int)'a']=(int)b[0]-(int)'a';
	}
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<6; j++)
		{
			for(int k=0; k<6; k++)
			{
				if(T[j][k]!=-1)
					dp[i][j]+=dp[i-1][T[j][k]];
			}
		}
	}
	int res=0;
	for(int i=0; i<6; i++)
		res+=dp[n][i];
	printf("%d\n", res);
	return 0;
}