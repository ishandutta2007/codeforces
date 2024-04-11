#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 300;

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)
	{
		if (i != 1)
			printf("R");
		for (int j = 0; j < a[i]; j++)
		{
			printf("P");
			if (i != 1)
				printf("LR");
			else
				printf("RL");
		}
	}
	cout << endl;

	return 0;
}