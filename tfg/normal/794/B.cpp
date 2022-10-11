#include <iostream>
#include <iomanip>
#include <cmath>

typedef long double ld;

ld pos[2020];

int main()
{
	int n, hi;
	std::cout << std::fixed << std::setprecision(20);
	while(std::cin >> n >> hi)
	{
		ld base = 1.0, height = hi;
		ld area = base * height / 2.0;
		ld wanted = area / n;
		ld cur = area;
		pos[0] = 0.0;
		for(int i = 0; i < n - 1; i++)
		{
			cur -= wanted;
			//ld b = (hi - pos[i]) / hi;
			// area = b * h / 2
			// h = (2 * area) / b
			// b = h / H
			// h = (2 * area * H) / h
			// h^2 = 2 * area * H
			pos[i + 1] = sqrt(2.0 * cur * height);
		}
		pos[n] = height;
		for(int i = n - 1; i > 0; i--)
		{
			if(i != n - 1)
				std::cout << ' ';
			std::cout << (double)(pos[i]);
		}
		std::cout << '\n';
	}
}