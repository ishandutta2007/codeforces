#include <iostream>

int main()
{
	long long k, l;
	std::cin >> k >> l;
	int ans = -1;
	while(l > 1)
	{
		if(l % k != 0)
		{
			std::cout << "NO\n";
			return 0;
		}
		ans++;
		l /= k;
	}
	std::cout << "YES\n" << ans << "\n";
}