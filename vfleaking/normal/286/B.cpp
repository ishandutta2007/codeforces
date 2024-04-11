#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 1000000;

int main()
{
	int n;
	static int a[MaxN * 2 + 1];

	cin >> n;

	for (int i = 1; i <= n; i++)
		a[i] = i;
	for (int i = 1; i <= n; i++)
	{
		a[n + i] = a[(n - 1) / i * i + i];
		for (int j = (n - 1) / i * i + 1; j >= 1; j -= i)
			a[j + i - 1] = a[j - 1];
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", a[n + i]);
	cout << endl;

	return 0;
}