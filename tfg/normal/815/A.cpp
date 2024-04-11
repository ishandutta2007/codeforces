#include <iostream>

const int ms = 110;

int board[ms][ms];
int sumrow[ms], sumcol[ms];

int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			std::cin >> board[i][j];
		}
	}
	int ans = 0;
	if(n <= m)
	{
		for(int i = 0; i < n; i++)
		{
			int cur_min = 127893;
			for(int j = 0; j < m; j++)
			{
				cur_min = std::min(cur_min, board[i][j] - sumrow[i] - sumcol[j]);
			}
			sumrow[i] += cur_min;
			ans += cur_min;
		}
	}
	for(int j = 0; j < m; j++)
	{
		int cur_min = 127893;
		for(int i = 0; i < n; i++)
		{
			cur_min = std::min(cur_min, board[i][j] - sumrow[i] - sumcol[j]);
		}
		sumcol[j] += cur_min;
		ans += cur_min;
	}
	for(int i = 0; i < n; i++)
	{
		int cur_min = 127893;
		for(int j = 0; j < m; j++)
		{
			cur_min = std::min(cur_min, board[i][j] - sumrow[i] - sumcol[j]);
		}
		sumrow[i] += cur_min;
		ans += cur_min;
	}
	bool valid = true;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			valid = valid && sumrow[i] + sumcol[j] == board[i][j];
		}
	}
	if(valid)
	{
		std::cout << ans << '\n';
		for(int i = 0; i < n; i++)
		{
			while(sumrow[i]--)
				std::cout << "row " << i + 1 << '\n';
		}
		for(int i = 0; i < m; i++)
		{
			while(sumcol[i]--)
				std::cout << "col " << i + 1 << '\n';
		}
	}
	else
	{
		std::cout << "-1\n";
	}
}