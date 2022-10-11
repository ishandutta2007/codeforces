#include <iostream>

int main()
{
	int x, t, a, b, da, db;
	std::cin >> x >> t >> a >> b >> da >> db;
	for(int i = 0; i < t; i++)
	{
		int cur = a - da * i;
		for(int j = 0; j < t; j++)
		{
			int ccur = b - db * j;
			if(ccur + cur == x || cur == x || ccur == x || 0 == x)
			{
				std::cout << "YES\n";
				return 0;
			}
		}
	}
	std::cout << "NO\n";
}