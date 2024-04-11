#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	if (n * (n - 1) / 2 <= k)
	{
		cout << "no solution" << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
		printf("%d %d\n", 1, i);

	return 0;
}