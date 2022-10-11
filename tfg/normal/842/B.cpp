#include <iostream>

int main()
{
	int r, d;
	std::cin >> r >> d;
	int n;
	std::cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int x, y, rad;
		std::cin >> x >> y >> rad;
		int dist = x * x + y * y;
		//std::cout << "dist is " << dist << "\n";
		//std::cout << "(" << (d + rad) * (d + rad) << ", " << (d - rad) * (d - rad) << ")\n";
		if(dist >= (r - d + rad) * (r - d + rad) && dist <= (r - rad) * (r - rad) && 2 * rad <= d)
			ans++;
	}
	std::cout << ans << '\n';
}