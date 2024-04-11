#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <climits>
using namespace std;

const int MaxN = 1000;

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
	int n;
	static int aw[MaxN];
	static int ah[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &aw[i], &ah[i]);

	int res = INT_MAX;
	for (int t = 0; t < n * 2; t++)
	{
		int hm = t < n ? aw[t] : ah[t - n];

		bool ok = true;
		int cntL = 0;
		int li_n = 0;
		static int li[MaxN];
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			if (aw[i] > hm && ah[i] > hm)
			{
				ok = false;
				break;
			}
			else if (aw[i] <= hm && ah[i] <= hm)
			{
				if (aw[i] < ah[i])
					cur += aw[i];
				else
				{
					cur += ah[i];
					li[li_n++] = aw[i] - ah[i];
				}
			}
			else if (aw[i] > hm)
				cur += aw[i];
			else
				cur += ah[i], cntL++;
		}
		if (!ok)
			continue;
		if (cntL > n / 2)
			continue;
		if (li_n + cntL > n / 2)
		{
			sort(li, li + li_n);
			for (int i = 0; i < li_n + cntL - n / 2; i++)
				cur += li[i];
		}

		tension(res, cur * hm);
	}

	cout << res << endl;

	return 0;
}