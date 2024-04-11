#include <iostream>
#include <cstdio>
#include <numeric>
using namespace std;

typedef long long s64;
const s64 S64_MAX = 9223372036854775807ll;

const int MaxN = 100000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int main()
{
	int n, cL, cR, qL, qR;
	static int a[MaxN + 1];

	cin >> n >> cL >> cR >> qL >> qR;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int allW = accumulate(a + 1, a + n + 1, 0);

	s64 res = S64_MAX;
	for (int i = 0, sumW = 0; i <= n; i++)
	{
		sumW += a[i];
		s64 cur = (s64)sumW * cL + (s64)(allW - sumW) * cR;
		if (i < n - i)
			cur += (s64)max((n - i) - i - 1, 0) * qR;
		else
			cur += (s64)max(i - (n - i) - 1, 0) * qL;
		tension(res, cur);
	}

	cout << res << endl;

	return 0;
}