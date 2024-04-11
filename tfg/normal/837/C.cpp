#include <iostream>

int n, a, b;
int x[101], y[101];

int solve(int x1, int y1, int x2, int y2)
{
	int ans = (x1 > a - x2 && y1 > b - y2) || std::max(x1, x2) > a || std::max(y1, y2) > b ? 0 : x1 * y1 + x2 * y2;
	//std::cout << "(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << "), (" << x1 << ", " << a - x2 << ") (" << y1 << ", " << b - y2 << ") = " << ans << "\n";
	return ans;
}

int main()
{
	std::cin >> n >> a >> b;
	for(int i = 0; i < n; i++)
		std::cin >> x[i] >> y[i];
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
				continue;
			ans = std::max(ans, solve(x[i], y[i], x[j], y[j]));
			ans = std::max(ans, solve(x[i], y[i], y[j], x[j]));
			ans = std::max(ans, solve(y[i], x[i], x[j], y[j]));
			ans = std::max(ans, solve(y[i], x[i], y[j], x[j]));
		}
	}
	std::cout << ans << "\n";
}