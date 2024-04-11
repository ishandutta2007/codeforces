#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace std;

typedef long long s64;

const int MaxD = 18;
const int B = 10;

pair<s64, int> f[MaxD + 1][B][B][B];
pair<s64, int> dfs(s64 n, int preM)
{
	if (n == 0)
		return make_pair(0ll, 0);
	if (n < 10)
		return make_pair(1ll, max(0, preM - (int)n));

	int l = 0;
	s64 m = 1;
	while (m <= n / 10)
		m *= 10, l++;

	pair<s64, int> res = dfs(n % m, max(preM, (int)(n / m)));
	if (res.second == 0)
	{
		res.first++;
		res.second = max(preM, (int)(n / m));
	}
	pair<s64, int> &curF = f[l][n / m][preM][res.second];
	if (!curF.first)
		curF = dfs(n / m * m - res.second, preM);

	res.first += curF.first;
	res.second = curF.second;
	return res;
}

int main()
{
	s64 n;
	cin >> n;
	cout << dfs(n, 0).first << endl;
	return 0;
}