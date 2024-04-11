#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long s64;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	static vector<int> a;
	for (int i = 1; i <= n; i = n / (n / i) + 1)
	{
		a.push_back(i - 1);
		a.push_back(i);
	}
	for (int i = 1; i <= m; i = m / (m / i) + 1)
	{
		a.push_back(k + 2 - i);
		a.push_back(k + 2 - i + 1);
	}
	a.push_back(1);
	a.push_back(n);
	a.push_back(k + 2 - m);
	a.push_back(k + 1);

	s64 res = -1;
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		int i = *it;
		if (1 <= i && i <= n && 1 <= k + 2 - i && k + 2 - i <= m)
			res = max(res, (s64)(n / i) * (m / (k + 2 - i)));
	}

	cout << res << endl;

	return 0;
}