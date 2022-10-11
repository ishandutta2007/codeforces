#include <iostream>

const int ms = 100100;

typedef long long ll;

ll a[ms];
ll dp[2][ms], val[2][ms];

int main()
{
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++)
	{
		std::cin >> a[i];
		a[i] -= i;
		//std::cout << a[i] << ' ';
	}
	//std::cout << '\n';
	// left
	val[0][1] = a[1];
	for(int i = 2; i <= n; i++)
		val[0][i] = std::max(val[0][i - 1], a[i]);
	for(int i = 2; i <= n; i++)
		dp[0][i] = dp[0][i - 1] + val[0][i] - a[i];
	// right
	for(int i = 1; i <= n; i++)
	{
		a[i] += 2 * i;
		//std::cout << a[i] << ' ';
	}
	//std::cout << '\n';
	val[1][n] = a[n];
	for(int i = n - 1; i > 0; i--)
		val[1][i] = std::max(val[1][i + 1], a[i]);
	for(int i = n - 1; i > 0; i--)
		dp[1][i] = dp[1][i + 1] + val[1][i] - a[i];

	ll ans = 1e18;
	for(int i = 0; i <= n; i++)
	{
		ll cur_ans = dp[0][i] + dp[1][i + 1];
		if(i != 0 && i != n)
		{
			ll l = val[0][i] + i;
			ll r = val[1][i + 1] - (i + 1);
			if(l == r)
				cur_ans++;
		}
		//std::cout << "on " << i << " is " << cur_ans << ", (" << dp[0][i] << ", " << dp[1][i + 1] << ")\n";
		ans = std::min(ans, cur_ans);
	}
	std::cout << ans << '\n';
}