#include <iostream>
#include <string>

std::string flag[101];

int step[256];
int cur_step = 0;

int main()
{
	int n, m;
	std::cin >> n >> m;
	bool valid = false;
	for(int i = 0; i < n; i++)
		std::cin >> flag[i];
	if(n % 3 == 0)
	{
		int match = 0;
		cur_step++;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				match += flag[i][j] == flag[(n / 3) * (i / (n / 3))][0] ? 1 : 0;
				if(step[flag[i][j]] != cur_step)
				{
					match++;
					step[flag[i][j]] = cur_step;
				}
			}
		}
		//std::cout << "got " << match;
		valid = valid || match == n * m + 3;
	}
	if(m % 3 == 0)
	{
		int match = 0;
		cur_step++;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				match += flag[i][j] == flag[0][(m / 3) * (j / (m / 3))] ? 1 : 0;
				if(step[flag[i][j]] != cur_step)
				{
					match++;
					step[flag[i][j]] = cur_step;
				}
			}
		}
		//std::cout << "got " << match;
		valid = valid || match == n * m + 3;
	}
	if(valid)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}