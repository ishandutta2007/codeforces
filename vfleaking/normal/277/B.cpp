#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	if (m == 3)
	{
		if (n == 3)
		{
			printf("0 0\n");
			printf("2 0\n");
			printf("1 3\n");
		}
		else if (n == 4)
		{
			printf("0 0\n");
			printf("2 0\n");
			printf("1 3\n");
			printf("1 1\n");
		}
		else
			cout << "-1" << endl;
	}
	else
	{
		for (int i = 1; i <= m; i++)
		{
			int x = i;
			int y = 10000000 + i * i;
			printf("%d %d\n", x, y);
		}
		for (int i = 1; i <= n - m; i++)
		{
			int x = i;
			int y = -10000000 - i * i;
			printf("%d %d\n", x, y);
		}
	}

	return 0;
}