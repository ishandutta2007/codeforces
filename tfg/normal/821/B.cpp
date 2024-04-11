#include <iostream>

long long comb(long long x)
{
	return x * (x + 1) / 2;
}

int main()
{
	int m, b;
	std::cin >> m >> b;
	long long ans = 0;
	for(int x = 0; x <= b * m; x++)
	{
		long long y = - (x / m) + b;
		if(x % m != 0)
			y--;
		long long got = comb(y) * (x + 1) + comb(x) * (y + 1);
		//std::cout << "on x == " << x << " got " << got << ", height " << y << '\n';
		ans = std::max(ans, got);
	}
	std::cout << ans << '\n';
}