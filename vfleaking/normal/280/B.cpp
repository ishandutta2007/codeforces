#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

inline int handle(const int *a, const int &n)
{
	static int q[MaxN];
	int top, bot;

	top = bot = 0;

	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		while (top != bot && q[bot - 1] < a[i])
		{
			relax(res, a[i] ^ q[bot - 1]);
			bot--;
		}
		q[bot++] = a[i];
	}
	return res;
}

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int res1 = handle(a, n);
	reverse(a + 1, a + n + 1);
	int res2 = handle(a, n);

	cout << max(res1, res2) << endl;

	return 0;
}