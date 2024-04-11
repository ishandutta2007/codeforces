#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y)
{
	return y ? gcd(y, x % y) : x;
}
int S(long long x)
{
	return x < 10 ? x : S(x / 10) + x % 10;
}
int main()
{
	int t;
	long long n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		while (gcd(n, S(n)) == 1)
		{
			n++;
		}
		cout << n << endl;		
	}
	return 0;
}