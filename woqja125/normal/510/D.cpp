#include<stdio.h>
#include<map>
int in[301];
int c[301];
int gcd(int a, int b)
{
	return b?gcd(b, a%b):a;
}
int main()
{
	int n, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", in+i);
	for(i=1; i<=n; i++) scanf("%d", c+i);
	for(i=1; i<=n; i++)
	{
		for(j=2; j*j<=in[i]; j++)
		{
			if(in[i] % j == 0)
			{
				while(in[i]%j == 0) in[i]/=j;
				in[i] *= j;
			}
		}
	}
	std::map<int, int> dp, dt;
	dp[0] = 0;
	for(i=1; i<=n; i++)
	{
		for(auto t: dp)
		{
			int xx = gcd(t.first, in[i]);
			int xy = t.second + c[i];
			if(dp.count(xx) == 0 || dp[xx] > xy)
			{
				if(dt.count(xx) == 0 || dt[xx] > xy) dt[xx] = xy;
			}
		}
		for(auto t: dt)
		{
			dp[t.first] = t.second;
		}
		dt.clear();
	}
	if(dp.count(1) == 0)printf("-1");
	else printf("%d", dp[1]);
	return 0;
}