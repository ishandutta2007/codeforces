#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 5000;
const int MaxK = 20;

// adjust
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
	int n, k;
	static int a[MaxN];

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int b_n = 0;
	static pair<int, int> b[MaxN * MaxK];
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= k; j++)
			b[b_n++] = make_pair(a[i] * j, j);
	sort(b, b + b_n);
	int nb_n = 0;
	for (int i = 0; i < b_n; i++)
		if (i == 0 || b[i - 1].first != b[i].first)
			b[nb_n++] = b[i];
	b_n = nb_n;

	int nQ;
	cin >> nQ;
	while (nQ--)
	{
		int val;
		cin >> val;

		int res = k + 1;
		for (int i = 0; i < n; i++)
		{
			if (val % a[i] == 0)
				tension(res, val / a[i]);

			for (int j = 1; j <= k; j++)
			{
				int r = val - a[i] * j;
				int p = lower_bound(b, b + b_n, make_pair(r, 0)) - b;
				if (p != b_n && b[p].first == r)
					tension(res, j + b[p].second);
			}
		}

		printf("%d\n", res == k + 1 ? -1 : res);
	}

	return 0;
}