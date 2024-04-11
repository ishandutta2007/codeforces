#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 5000;

// adjust variable
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

int main()
{
	int n, m;
	static int a[MaxN + 1];

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		double t;
		scanf("%d %lf", &a[i], &t);
	}

	static int t1[MaxN + 1], t2[MaxN + 1];
	int *f = t1, *g = t2;
	fill(f, f + n + 1, 0);
	for (int i = 1; i <= m; i++, swap(f, g))
	{
		static int cnt[MaxN + 1];
		cnt[0] = 0;
		for (int j = 1; j <= n; j++)
			cnt[j] = cnt[j - 1] + (a[j] == i);
		for (int j = 0; j <= n; j++)
		{
			g[j] += cnt[j];
			if (j > 0)
				tension(g[j], g[j - 1]);
			f[j] = g[j] + cnt[n] - cnt[j];
		}
	}

	cout << *min_element(g, g + n + 1) << endl;

	return 0;
}