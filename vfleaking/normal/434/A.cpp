#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 100000;
const int MaxM = 100000;

int main()
{
	int n, m;
	static int a[MaxM + 1];

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);

	s64 inh;
	s64 res = 0;
	for (int i = 2; i <= m; i++)
		res += abs(a[i] - a[i - 1]);
	inh = res;

	static vector<int> b[MaxN + 1];
	for (int i = 2; i <= m; i++)
		if (a[i] != a[i - 1])
			b[a[i]].push_back(a[i - 1]), b[a[i - 1]].push_back(a[i]);

	for (int y = 1; y <= n; y++)
		if (!b[y].empty())
		{
			s64 cur = inh;

			sort(b[y].begin(), b[y].end());
			int orz = b[y][b[y].size() / 2];
			for (vector<int>::iterator it = b[y].begin(); it != b[y].end(); it++)
				cur += -abs(y - *it) + abs(orz - *it);
			if (cur < res)
				res = cur;
		}
	cout << res << endl;

	return 0;
}