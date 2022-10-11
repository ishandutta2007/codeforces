#include <iostream>
#include <algorithm>

typedef long long ll;

int n, k;
ll M;

ll a[105], sum = 0;

ll solve(int x)
{
	if(x * sum > M)
		return 0;
	ll ans = x * (k + 1);
	ll tim = M - x * sum;
	for(int i = 0; i < k; i++)
	{
		for(int j = x; j < n; j++)
		{
			if(a[i] <= tim)
			{
				tim -= a[i];
				ans++;
			}
			else
				return ans;
		}
	}
	return ans;
}

int main()
{
	std::cin >> n >> k >> M;
	for(int i = 0; i < k; i++)
		std::cin >> a[i];
	for(int i = 0; i < k; i++)
		sum += a[i];
	std::sort(a, a + k);
	ll ans = 0;
	for(int i = 0; i <= n; i++)
		ans = std::max(ans, solve(i));
	std::cout << ans << '\n';
}