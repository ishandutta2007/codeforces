#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 1000;

int main()
{
	int n;
	static int a[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	int res = 0;
	for (int i = 0, j = 0; i < n; i = j)
	{
		while (j < n && a[i] == a[j])
			j++;
		if (a[i] == 0)
			continue;
		if (j - i == 2)
			res++;
		else if (j - i > 2)
		{
			res = -1;
			break;
		}
	}

	cout << res << endl;

	return 0;
}