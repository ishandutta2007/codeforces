#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 1000000;
const int MaxM = 1000000;

int main()
{
	int n, m;
	static int d[MaxN + 1];

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		d[v]++;
		d[u]++;
	}

	s64 res = 0ll;
	for (int i = 1; i <= n; i++)
		res += (s64)d[i] * (n - d[i] - 1ll);
	res = (s64)n * (n - 1ll) * (n - 2ll) / 6ll - res / 2ll;
	cout << res << endl;

	return 0;
}