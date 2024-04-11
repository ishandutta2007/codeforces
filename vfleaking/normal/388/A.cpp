#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100;

int main()
{
	int n;
	static int a[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);

	static int c[MaxN + 10];
	for (int i = 0; i < n; i++)
	{
		int p = 0;
		while (c[p] > a[i])
			p++;
		c[p]++;
	}

	int res = 0;
	while (c[res] > 0)
		res++;
	cout << res << endl;

	return 0;
}