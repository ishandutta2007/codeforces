#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 500;
const int MaxM = 1000;

int main()
{
	int n, m;
	static int a[MaxN + 1];
	static int b[MaxM + 1];

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);

	int li_n = n;
	static int li[MaxN + 1];
	static bool used[MaxN + 1];

	int res = 0;
	for (int i = 1; i <= m; i++)
	{
		if (!used[b[i]])
		{
			li[li_n--] = b[i];
			used[b[i]] = true;
		}

		int p = n;
		while (li[p] != b[i])
		{
			res += a[li[p]];
			p--;
		}
		for (int k = p + 1; k <= n; k++)
			li[k - 1] = li[k];
		li[n] = b[i];
	}

	cout << res << endl;

	return 0;
}