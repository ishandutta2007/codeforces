#include <iostream>
#include <iomanip>

int main()
{
	double l;
	double v[2];
	std::cin >> l >> v[0] >> v[1];
	std::cout << std::fixed << std::setprecision(15);
	std::cout << v[0] * (l / (v[0] + v[1])) << '\n';
}