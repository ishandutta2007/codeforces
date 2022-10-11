#include <iostream>

int n, k;
int m[101][101];

int main()
{
	std::cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			int use = 1;
			if(j != i)
				use++;
			if(k >= use)
			{
				m[i][j] = 1;
				m[j][i] = 1;
				k -= use;
			}
		}
	}
	if(k)
		std::cout << "-1\n";
	else
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(j)
					std::cout << ' ';
				std::cout << m[i][j];
			}
			std::cout << '\n';
		}
	}
}