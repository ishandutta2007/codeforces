#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n, s;
	cin >> n >> s;

	if (n == 1)
	{
		if (s == 0)
			cout << "1" << endl;
		else
			cout << "-1" << endl;
		return 0;
	}

	static int a[MaxN + 1];
	for (int i = 3; i <= n; i++)
		a[i] = 500000000 + i;
	s -= n / 2 - 1;

	if (s <= 0)
		cout << -1 << endl;
	else
	{
		a[1] = s, a[2] = s * 2;

		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
		cout << endl;
	}

    return 0;
}