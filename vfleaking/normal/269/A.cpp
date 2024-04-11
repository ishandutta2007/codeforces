#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

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
	int n;
	static pair<int, int> a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].first, &a[i].second);

	sort(a + 1, a + n + 1);

	int t = 0;
	int last = 0;
	for (int i = 1; i <= n; i++)
	{
		int delta = a[i].first - last;
		last = a[i].first;
		for (int j = 0; j < delta && t > 1; j++)
			t = (t + 3) >> 2;
		relax(t, a[i].second);
	}
	int res = a[n].first;
	if (t == 1)
		res++;
	else
	{
		while (t > 1)
			t = (t + 3) >> 2, res++;
	}
	cout << res << endl;

	return 0;
}