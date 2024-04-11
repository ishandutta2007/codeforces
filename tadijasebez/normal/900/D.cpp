#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=1e5;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
vector<int> d;
int dp[N];
int main()
{
	int x,y;
	scanf("%i %i",&x,&y);
	if(y%x) return printf("0\n"),0;
	int num=y/x,i,j;
	for(i=1;i*i<=num;i++)
	{
		if(num%i) continue;
		j=num/i;
		d.push_back(i);
		if(j==i) continue;
		d.push_back(j);
	}
	sort(d.begin(),d.end());
	for(i=0;i<d.size();i++)
	{
		dp[i]=pow(2,d[i]-1);
		for(j=0;j<i;j++)
			if(!(d[i]%d[j]))
			{
				dp[i]-=dp[j];
				if(dp[i]<0) dp[i]+=mod;
			}
	}
	int n=d.size()-1;
	printf("%i\n",dp[n]);
	return 0;
}