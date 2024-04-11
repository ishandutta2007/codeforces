#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	sort(a + 1, a + n + 1);

	static s64 sum[MaxN + 1];
	sum[0] = 0ll;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];

	s64 oneRes = 0ll;
	for (int i = 1; i <= n; i++)
		oneRes += (s64)a[i] * (n - i);

	int q;
	cin >> q;
	while (q--)
	{
		int k;
		scanf("%d", &k);

		s64 res;
		if (k == 1)
			res = oneRes;
		else
		{
			res = 0ll;
			for (s64 i = n, j = 0ll, l = 1ll; i > 0; i -= l, j++, l *= k)
				res += (i >= l ? sum[i] - sum[i - l] : sum[i]) * j;
		}
		cout << res << endl;
	}

	return 0;
}