#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MaxM = 100000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n, m;
	static int d[MaxM + 1], h[MaxM + 1];

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &d[i], &h[i]);

	int res = 0;
	relax(res, h[1] + d[1] - 1);
	relax(res, h[m] + n - d[m]);
	for (int i = 1; i < m; i++)
	{
		if (abs(h[i] - h[i + 1]) > abs(d[i] - d[i + 1]))
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		relax(res, ((d[i + 1] - d[i]) + h[i] + h[i + 1]) / 2);
	}

	cout << res << endl;

	return 0;
}