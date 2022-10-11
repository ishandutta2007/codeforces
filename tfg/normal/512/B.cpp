#include <iostream>
#include <map>

const long long INF = 1e18;
const int ms = 330;

int gcd(int a, int b)
{
	if(!b)
		return a;
	else
		return gcd(b, a % b);
}

std::map<int, long long> memo;

int n, a[ms], c[ms];

long long dp(int on)
{
	if(on == 1)
	{
		//std::cout << "got to 1\n";
		return 0;
	}
	if(memo.count(on))
		return memo[on];
	//std::cout << "on " << on << '\n';
	long long ans = INF;
	for(int i = 0; i < n; i++)
	{
		int to = gcd(on, a[i]);
		if(to == on)
			continue;
		//std::cout << "from " << on << " to " << to << '\n';
		ans = std::min(ans, c[i] + dp(to));
	}
	return memo[on] = ans;
}

int main()
{
	while(std::cin >> n)
	{
		for(int i = 0; i < n; i++)
			std::cin >> a[i];
		for(int i = 0; i < n; i++)
			std::cin >> c[i];
		memo.clear();
		long long ans = INF;
		for(int i = 0; i < n; i++)
			ans = std::min(ans, c[i] + dp(a[i]));
		if(ans == INF)
			ans = -1;
		std::cout << ans << '\n';
	}
}