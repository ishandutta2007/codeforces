#include <iostream>
#include <string>

typedef long long ll;

const ll MOD = int(1e9) + 7;
const int ms = int(1e6) + 1000;

ll dp[ms];
ll bs[ms];

int main()
{
	std::string str;
	std::cin >> str;
	for(int i = str.size() - 1; i >= 0; i--)
	{
		dp[i] = dp[i + 1];
		if(str[i] == 'a')
		{
			dp[i] += bs[i + 1];
			bs[i] = 2 * bs[i + 1] % MOD;
		}
		else
		{
			bs[i] = (bs[i + 1] + 1) % MOD;
		}
		dp[i] %= MOD;
	}
	std::cout << dp[0] << '\n';
}