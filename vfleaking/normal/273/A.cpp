#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int lowbit(int t)
{
	return t & (-t);
}

int main()
{
	int n;
	static s64 a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int m;
	cin >> m;

	for (int i = 1; i <= m; i++)
	{
		int w, h;
		scanf("%d %d", &w, &h);

		s64 res = 0;
		for (int j = w; j >= 1; j -= lowbit(j))
			relax(res, a[j]);
		for (int j = 1; j <= n; j += lowbit(j))
			relax(a[j], res + h);

		cout << res << endl;
	}

	return 0;
}