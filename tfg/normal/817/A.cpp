#include <iostream>

int main()
{
	int x1, y1, x2, y2;
	int x, y;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
	if(x1 < x2)
		std::swap(x1, x2);
	if(y1 < y2)
		std::swap(y1, y2);
	bool valid = true;
	if((x1 - x2) % x != 0)
		valid = false;
	if((y1 - y2) % y != 0)
		valid = false;
	if((x1 - x2) / x % 2 != (y1 - y2) / y % 2)
		valid = false;
	if(valid)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}