#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
int abs(int x){ return x>0?x:-x;}
vector<int> a,b;
int x,p;
long long dp[N];
long long sol;
long long max(long long a, long long b){ return a>b?a:b;}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(i>1) a.push_back(abs(x-p));
		if(i>2) b.push_back(abs(x-p));
		p=x;
	}
	for(i=0;i<a.size();i++) if(i&1) a[i]=-a[i];
	for(i=0;i<b.size();i++) if(i&1) b[i]=-b[i];
	dp[0]=a[0];
	sol=max(sol,dp[0]);
	for(i=1;i<a.size();i++)
	{
		dp[i]=dp[i-1]+a[i];
		sol=max(sol,dp[i]);
		if(dp[i]<0) dp[i]=0;
	}
	if(b.size()>0)
	{
		dp[0]=b[0];
		sol=max(sol,dp[0]);
		for(i=1;i<b.size();i++)
		{
			dp[i]=dp[i-1]+b[i];
			sol=max(sol,dp[i]);
			if(dp[i]<0) dp[i]=0;
		}
	}
	printf("%lld\n",sol);
	return 0;
}