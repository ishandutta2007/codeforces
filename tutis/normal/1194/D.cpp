/*input
1
999999999 9
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int mex(int a, int b, int c)
{
	if (a == 0 || b == 0 || c == 0)
	{
		if (a == 1 || b == 1 || c == 1)
		{
			if (a == 2 || b == 2 || c == 2)
				return 3;
			else
				return 2;
		}
		else
			return 1;
	}
	else
		return 0;
}
map<int, int>M;
int k;
int x(int n)
{
	if (M.count(n))
		return M[n];
	if (k % 3 != 0)
		return n % 3;
	if (n < k)
		return n % 3;
	if (n >= k + 1)
		return x(n % (k + 1));
	if (n % (k + 1) > 10)
	{
		int b = n % (k + 1);
		int a = n / (k + 1);
		b = 6 + b % 3;
		return x(a * (k + 1) + b);
	}
	return M[n] = mex(x(n - 1), x(n - 2), x(n - k));
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		M.clear();
		int n;
		cin >> n >> k;
		M.clear();
		if (x(n) != 0)
			cout << "Alice\n";
		else
			cout << "Bob\n";
	}
}