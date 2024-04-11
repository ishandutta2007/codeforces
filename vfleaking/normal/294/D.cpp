#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
	int n, m;
	int sx, sy;
	string sd;

	cin >> n >> m >> sx >> sy >> sd;

	if (sx == 1)
		sd[0] = 'D';
	else if (sx == n)
		sd[0] = 'U';

	if (sy == 1)
		sd[1] = 'R';
	else if (sy == m)
		sd[1] = 'L';

	long long res = 1;
	set< pair<int, int> > pS;
	pS.insert(make_pair(sx, sy));

	int x = sx, y = sy;
	string d = sd;
	do
	{
		int s = min(d[0] == 'U' ? x - 1 : n - x, d[1] == 'L' ? y - 1 : m - y);
		res += s;
		x += d[0] == 'U' ? -s : s;
		y += d[1] == 'L' ? -s : s;

		if (x == 1)
			d[0] = 'D';
		else if (x == n)
			d[0] = 'U';

		if (y == 1)
			d[1] = 'R';
		else if (y == m)
			d[1] = 'L';

		pS.insert(make_pair(x, y));

		if ((int)pS.size() == n + m - 2)
		{
			cout << res << endl;
			return 0;
		}
	}
	while (x != sx || y != sy || d != sd);

	cout << -1 << endl;
	return 0;
}