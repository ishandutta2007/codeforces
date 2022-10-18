#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 500000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int res = 0;
	for (int i = 1, j; i <= n; i = j)
	{
		j = i + 1;
		while (j <= n && a[j] != a[j - 1])
			j++;

		int l = j - i;
		if (l >= 3)
		{
			relax(res, (l - 1) / 2);

			if (l % 2 == 1)
			{
				for (int k = i; k < j; k++)
					a[k] = a[i];
			}
			else
			{
				for (int k = 0; k < l / 2; k++)
					a[i + k] = a[i];
				for (int k = l / 2; k < l; k++)
					a[i + k] = a[j - 1];
			}
		}
	}

	cout << res << endl;
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	cout << endl;

	return 0;
}