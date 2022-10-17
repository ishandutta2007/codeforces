#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n, k;
long long pw(long long x, long long y)
{
	long long re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		if (n & 1)
		{
			cout << pw(pw(2, n - 1) + 1, k) << endl;
		}
		else
		{
			long long re = pw(pw(2, n - 1) - 1, k);
			for (int i = 0; i < k; i++)
			{
				re = (re + pw(pw(2, n - 1) - 1, k - 1 - i) * pw(pw(2, n), i)) % p;
			}
			cout << re << endl;
		}
	}
	return 0;
}