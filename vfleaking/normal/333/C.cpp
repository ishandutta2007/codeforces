#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int L = 8;

int main()
{
	int n, m;
	cin >> n >> m;

	static int pow10[L + 1];
	pow10[0] = 1;
	for (int i = 1; i <= L; i++)
		pow10[i] = pow10[i - 1] * 10;

	vector< pair<int, int> > a[L + 1];

	for (int d = 0; d <= 9; d++)
	{
		a[1].push_back(make_pair(d, d));
		if (d > 0)
			a[1].push_back(make_pair(d, -d));
	}
	for (int i = 2; i <= 4; i++)
	{
		for (int j = 1; j < i; j++)
			for (int ka = 0; ka < (int)a[j].size(); ka++)
				for (int kb = 0; kb < (int)a[i - j].size(); kb++)
				{
					a[i].push_back(make_pair(a[j][ka].first * pow10[i - j] + a[i - j][kb].first, a[j][ka].second + a[i - j][kb].second));
					a[i].push_back(make_pair(a[j][ka].first * pow10[i - j] + a[i - j][kb].first, a[j][ka].second - a[i - j][kb].second));
					a[i].push_back(make_pair(a[j][ka].first * pow10[i - j] + a[i - j][kb].first, a[j][ka].second * a[i - j][kb].second));
				}
		sort(a[i].begin(), a[i].end()), a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
	}

	for (int i = 0; m > 0 && i < (int)a[4].size(); i++)
	{
		int cur = n + a[4][i].second;
		if (0 <= cur && cur < 10000)
			printf("%04d%04d\n", a[4][i].first, cur), m--;
	}
	if (m > 0)
		cerr << "oh....no!" << endl;

	return 0;
}