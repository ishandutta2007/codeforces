#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

typedef long long s64;

const s64 S64_MIN = LONG_LONG_MIN;

const int MaxN = 100000;

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

int main()
{
	int n, q;
	static int v[MaxN + 1];
	static int c[MaxN + 1];

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);

	while (q--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		s64 res = 0ll;
		static s64 f[MaxN + 1];
		fill(f + 1, f + n + 1, S64_MIN);

		int first = 1, second = 2;
		for (int i = 1; i <= n; i++)
		{
			s64 val = (s64)v[i] * b;
			if (f[c[i]] != S64_MIN)
				relax(val, f[c[i]] + (s64)v[i] * a);

			int t = c[i] == first ? second : first;
			if (f[t] != S64_MIN)
				relax(val, f[t] + (s64)v[i] * b);

			if (relax(f[c[i]], val))
			{
				if (first == c[i])
					;
				else if (second == c[i])
				{
					if (f[second] > f[first])
						swap(first, second);
				}
				else
				{
					if (f[c[i]] > f[first])
					{
						second = first;
						first = c[i];
					}
					else if (f[c[i]] > f[second])
						second = c[i];
				}
			}
			relax(res, val);
		}
		cout << res << endl;
	}

	return 0;
}