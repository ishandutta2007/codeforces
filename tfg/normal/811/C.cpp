#include <iostream>
#include <vector>

const int ms = 5050;

std::vector<int> num[ms];
int a[ms];
int dp[ms];
int dp2[ms];
int step[ms];


int main()
{
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++)
	{
		std::cin >> a[i];
		num[a[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++)
	{
		int cur_xor = 0;
		int l = n;
		for(int j = i; j > 0; j--)
		{
			if(num[a[j]].back() > i)
				break;
			l = std::min(l, num[a[j]][0]);
			if(step[a[j]] != i)
			{
				//std::cout << "including " << a[j] << '\n';
				cur_xor ^= a[j];
			}
			step[a[j]] = i;
			if(j <= l)
			{
				//std::cout << "to " << j << '\n';
				dp[i] = std::max(dp[i], dp2[j - 1] + cur_xor);
			}
		}
		//std::cout << "on " << i << " got ans " << dp[i] << '\n';
		dp2[i] = std::max(dp[i], dp2[i - 1]);
	}
	std::cout << dp2[n] << '\n';
}