#include<bits/stdc++.h>
using namespace std;
int n,m;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=m?m:0);
}
const int max_n=2e5+5;
int dp[max_n];
int main()
{
	scanf("%d%d",&n,&m);
	dp[n]=1;
	int tag=0;
	for(int x=n;x>1;--x)
	{
		add(dp[x],tag);
		for(int i=2,j;i<=x;i=j+1)
		{
			j=x/(x/i);
			dp[x/i]=(dp[x/i]+(j-i+1ll)*dp[x])%m;
		}
		add(tag,dp[x]);
	}
	add(dp[1],tag);
	printf("%d\n",dp[1]);
	return 0;
}