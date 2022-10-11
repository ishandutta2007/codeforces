#include <iostream>
#include <queue>
#include <cstdio>
#include <utility>

typedef long long ll;
typedef std::pair<ll, int> ii;

int n, k;
ll cost[300300];
int on[300300];

int main()
{
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lli", cost + i);
	}
	std::priority_queue<ii> hp;
	ll sum = 0;
	ll ans = 0;
	for(int i = 1; i <= k; i++)
	{
		sum += cost[i];
		ans += sum;
		hp.push(ii(cost[i], i));
	}
	for(int i = k + 1; i <= k + n; i++)
	{
		if(i <= n)
		{
			sum += cost[i];
			hp.push(ii(cost[i], i));
		}
		sum -= hp.top().first;
		on[hp.top().second] = i;
		hp.pop();
		ans += sum;
	}
	std::cout << ans << '\n';
	for(int i = 1; i <= n; i++)
	{
		if(i != 1)
			printf(" ");
		printf("%i", on[i]);
	}
	std::cout << '\n';
}