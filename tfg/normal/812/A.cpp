#include <iostream>

int a[4][4];
int sum[4];

int main()
{
	bool valid = true;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			std::cin >> a[i][j];
			sum[i] += a[i][j];
		}
	}
	for(int i = 0; i < 4; i++)
	{
		if(sum[i] > a[i][3] && a[i][3] > 0)
			valid = false;
		if(a[i][3] > 0 && a[i ^ 2][1] > 0)
			valid = false;
		if(a[i][3] > 0 && a[(i + 1) % 4][0] > 0)
			valid = false;
		if(a[i][3] > 0 && a[(i + 3) % 4][2] > 0)
			valid = false;
	}
	if(!valid)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}