#include<cstring>
#include<cstdio>
#include<algorithm>
#include<numeric>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<vector>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int n, k, a[2001], dp[2011];
long long le, ri, mid, l, r;

bool check(long long mid)
{
	int rtn = n - 1;
	for(int i = 1; i <= n; i++)
	{
		dp[i] = i - 1;
		for(int j = 1; j < i; j++) if(abs(a[j] - a[i]) <= mid * (i - j))
			dp[i] = min(dp[i], dp[j] + i - j - 1);
	}
	for(int i = 1; i <= n; i++) rtn = min(rtn, dp[i] + n - i);
	return rtn <= k;
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	le = 0; ri = 2000000000;
	while(le < ri - 1)
	{
		mid = (le + ri) / 2;
		if(check(mid)) ri = mid; else le = mid;
	}
	if(check(le)) printf("%I64d\n", le); else printf("%I64d\n", ri);	
 	fclose(stdin);
	return 0;
}