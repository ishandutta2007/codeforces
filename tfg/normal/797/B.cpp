#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
	int n;
	while(std::cin >> n)
	{
		std::vector<ll> odd;
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			ll temp;
			std::cin >> temp;
			if((temp % 2 + 2) % 2 == 0)
				ans += std::max(0LL, temp);
			else
				odd.push_back(-temp);
		}
		std::sort(odd.begin(), odd.end());
		for(int i = 0; i < odd.size(); i++)
			odd[i] = -odd[i];
		ll tot_ans = -INF;
		ll sum = 0;
		for(int i = 0; i < odd.size(); i++)
		{
			sum += odd[i];
			if((sum % 2 + 2) % 2 == 1)
			{
				//std::cout << "on sum " << sum << ", got " << ans << " + " << sum << "\n";
				tot_ans = std::max(tot_ans, ans + sum);
			}
		}
		std::cout << tot_ans << '\n';
	}
}