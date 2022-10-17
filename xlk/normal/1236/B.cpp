#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long n, m;
long long pw(long long x, long long y)
{
	long long re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % mod;
		}
		x = x * x % mod;
	}
	return re;
}
int main()
{
	cin >> n >> m;
	cout << pw(pw(2, m) - 1, n) << endl;
	return 0;
}