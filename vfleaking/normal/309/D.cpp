#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long s64;

int main()
{
	int n, m;
	cin >> n >> m;

	int l = n + 1;

	s64 res = 0;
	for (int k = m + 1; k <= (n + 1) / 2; k++)
	{
		s64 cur = 0;
		int s = 2 * (l * l + k * k - k * l);
		int r = n - m - m;
		int t2 = k + n - m + 1 - l * 2;
		int t3 = (m + 1) * (l + k - n + m) - (n - m) * (k - l * 2) - s;
		for (int i = n - m; i >= m + 1; i--)
		{
			while (r > 0 && t3 <= 0)
			{
				t3 += l + k - i;
				r--;
			}
			if (r == 0)
				break;
			cur += r;
			t3 += t2 - r;
		}
		if (k != n + 1 - k)
			cur *= 2;
		res += cur;
	}
	res *= 3;

	cout << res << endl;
	return 0;
}