#include <iostream>
#include <algorithm>
#include <utility>

typedef long long ll;
typedef std::pair<ll, int> ii;

ii cost[100100];

int main()
{
	int n, d, a, b;
	std::cin >> n >> d >> a >> b;
	for(int i = 0; i < n; i++)
	{
		long long x, y;
		std::cin >> x >> y;
		cost[i] = ii(x * a + y * b, i + 1);
	}
	std::sort(cost, cost + n);
	long long sum = 0;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		sum += cost[i].first;
		if(sum > d)
			break;
		else
			ans++;
	}
	std::cout << ans << '\n';
	for(int i = 0; i < ans; i++)
	{
		std::cout << cost[i].second << (i + 1 == n ? '\n' : ' ');
	}
}