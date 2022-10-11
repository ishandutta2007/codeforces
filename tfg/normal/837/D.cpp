#include <iostream>
#include <bitset>
#include <cstring>

const int ms = 26 * 200 + 1;

int size[101];
int dp[201][ms];

int main()
{
	int n, k;
	std::cin >> n >> k;
	int tot = 0;
	int hmm = 0;
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		long long num = 1e18;
		std::cin >> num;
		int twos, fives;
		twos = fives = 0;
		while(num % 2 == 0)
		{
			twos++;
			num /= 2;
		}
		while(num % 5 == 0)
		{
			fives++;
			num /= 5;
		}
		tot += fives;
		hmm += twos;
		for(int j = i; j >= 1; j--)
		{
			for(int k = std::min(tot, ms - 1); k >= fives; k--)
			{
				if(dp[j - 1][k - fives] == -1)
					continue;
				dp[j][k] = std::max(dp[j][k], dp[j - 1][k - fives] + twos);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < ms; i++)
		ans = std::max(ans, std::min(i, dp[k][i]));
	std::cout << ans << "\n";
}