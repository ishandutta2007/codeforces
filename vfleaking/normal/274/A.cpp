#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

int main()
{
	int n, k;
	static int a[MaxN];

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);
	n = unique(a, a + n) - a;

	if (k == 1)
	{
		cout << n << endl;
		return 0;
	}

	int res = 0;
	static bool visited[MaxN + 1];
	for (int i = 0; i < n; i++)
		if (!visited[i])
		{
			int l = 1;
			s64 j = a[i];
			int pos = i;
			while (true)
			{
				j *= k;
				pos = lower_bound(a, a + n, j) - a;
				if (pos < n && a[pos] == j)
				{
					visited[pos] = true;
					l++;
				}
				else
					break;
			}
			res += (l + 1) / 2;
		}

	cout << res << endl;

	return 0;
}