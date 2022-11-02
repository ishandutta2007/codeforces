#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
const LL mod=1000000007LL;

string a, s[100005];
int n;
LL dp[100005][10], MOD[100005][10], res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> a >> n;
	for(int i=0; i<n; i++) cin>> s[i];
	for(int j=0; j<10; j++)
	{
		dp[n][j]=j;
		MOD[n][j]=10;
	}
	for(int i=n-1; i>=0; i--)
	{
		for(int j=0; j<10; j++)
		{
			MOD[i][j]=1;
			if((int)s[i][0]-(int)'0'==j)
			{
				LL mo=1;
				for(int k=(int)s[i].size()-1; k>2; k--)
				{
					int c=(int)s[i][k]-(int)'0';
					dp[i][j]+=(dp[i+1][c]*mo)%mod;
					if(dp[i][j]>=mod) dp[i][j]-=mod;
					mo=(mo*MOD[i+1][c])%mod;
					MOD[i][j]=mo;
				}
			}
			else
			{
				dp[i][j]=dp[i+1][j];
				MOD[i][j]=MOD[i+1][j];
			}
		}
	}
	LL mo=1;
	for(int i=(int)a.size()-1; i>=0; i--)
	{
		int c=(int)a[i]-(int)'0';
		res+=(dp[0][c]*mo)%mod;
		if(res>=mod) res-=mod;
		mo=(mo*MOD[0][c])%mod;
	}
	cout<< res << '\n';
	return 0;
}