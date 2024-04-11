#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long long ll;

ll abss(ll x)
{
	if(x<0)
		return -x;
	else
		return x;
}

const int ms = 100100;

ll a[ms], dp[ms][2];

int main()
{
	int n;
	std::cin >> n;
	for(int i=1;i<=n;i++)
		//std::cin >> a[i];
		scanf("%lli", a+i);
		
	ll ans = -1e10;
	for(int i=2;i<=n;i++)
	{
		dp[i][0] = std::max(dp[i-1][1] + abss(a[i] - a[i-1]), abss(a[i] - a[i-1]));
		dp[i][1] = std::max(dp[i-1][0] - abss(a[i] - a[i-1]), dp[i-1][0] - abss(a[i] - a[i-1]));
		//std::cout << "ans on " << i << " is " << dp[i][0] << ", " << dp[i][1] << '\n';
		ans = std::max(ans, std::max(dp[i][0], dp[i][1]));
	}
	std::cout << ans << '\n';
}