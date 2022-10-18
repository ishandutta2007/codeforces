#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 300000;

int main()
{
	int n;
	static int a[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);
	s64 res = 0;
	if (n == 1)
		res = a[0];
	else
	{
		for (int i = 0; i < n - 1; i++)
			res += (s64)a[i] * (i + 2);
		res += (s64)a[n - 1] * n;
	}

	cout << res << endl;

	return 0;
}