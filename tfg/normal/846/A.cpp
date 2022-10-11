#include <iostream>

int freq[10239][2];

int main()
{
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int temp;
		std::cin >> temp;
		freq[i][temp]++;
		for(int j = 0; j < 2; j++)
			freq[i][j] += freq[i - 1][j];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans = std::max(ans, 1 + freq[i - 1][0] + freq[n][1] - freq[i][1]);
	}
	std::cout << ans << '\n';
}