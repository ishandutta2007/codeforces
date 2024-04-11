#include <iostream>
#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n;
	static int a[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int res = (accumulate(a, a + n, 0ll) + n - 1 - 1) / (n - 1);
	relax(res, *max_element(a, a + n));

	cout << res << endl;

	return 0;
}