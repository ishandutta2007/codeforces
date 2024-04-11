#include <iostream>

int a[55][55];

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			std::cin >> a[i][j];
		}
	}
	bool valid = true;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] == 1)
				continue;
			bool got = false;
			for(int ii = 0; ii < n; ii++)
			{
				for(int jj = 0; jj < n; jj++)
				{
					if(a[i][ii] + a[jj][j] == a[i][j])
						got = true;
				}
			}
			valid = valid && got;
		}
	}
	if(valid)
		std::cout << "Yes\n";
	else
		std::cout << "No\n";
}