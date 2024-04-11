#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	for(char i = 'a'; i <= 'z'; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			std::cout << i;
			n -= j;
		}
	}
	std::cout << '\n';
}