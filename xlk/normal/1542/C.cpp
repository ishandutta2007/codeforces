#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
long long gcd(long long x, long long y)
{
	return y ? gcd(y, x % y) : x;
}
long long lcm(long long x, long long y)
{
	return x / gcd(x, y) * y;
}
int main()
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		long long n;
		long long l = 1, m = 1;
		long long z = 0;
		cin >> n;
		for (int i = 2; i < 42; i++)
		{
			m = l;
			l = lcm(l, i);
			z = (z + (n / m - n / l) * i) % p;
		}
		cout << z << endl;
	}
	return 0;
}