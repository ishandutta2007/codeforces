#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int sum = 0;
	while(n--)
	{
		int temp;
		std::cin >> temp;
		sum += temp;
	}
	std::cin >> n;
	int ans = 1e9 + 10;
	while(n--)
	{
		int l, r;
		std::cin >> l >> r;
		if(r >= sum)
			ans = std::min(ans, std::max(l, sum));
	}
	if(ans == 1e9 + 10)
		ans = -1;
	std::cout << ans << '\n';
}