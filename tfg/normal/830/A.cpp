#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

typedef long long ll;

const int ms = 1010;
const ll INF = 1e15;

ll n, k, p;
ll a[ms];
ll b[2 * ms];

ll memo[ms][2 * ms];

ll labs(ll x)
{
	if(x < 0)
		return -x;
	else
		return x;
}

ll dp(int person, int key)
{
	if(person == n)
		return 0;
	if(key == k)
		return INF;
	ll &ans = memo[person][key];
	if(ans != -1)
		return ans;
	ans = std::min(
					std::max(labs(a[person] - b[key]) + labs(b[key] - p), dp(person + 1, key + 1))
				  , dp(person, key + 1));
	return ans;
}

int main()
{
	while(std::cin >> n >> k >> p)
	{
		for(int i = 0; i < n; i++)
			std::cin >> a[i];
		for(int i = 0; i < k; i++)
			std::cin >> b[i];
		std::sort(a, a + n);
		std::sort(b, b + k);
		memset(memo, -1, sizeof memo);
		std::cout << dp(0, 0) << '\n';
	}
}