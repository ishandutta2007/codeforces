#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 5000;
const int MaxM = 5000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n, m;

	cin >> n >> m;

	static int sum[1 + MaxN + 1][1 + MaxM + 1];
	for (int i = 1; i <= n; i++)
	{
		static char a[1 + MaxM + 1];
		scanf("%s", a + 1);

		for (int i = 1, j = 1; i <= m; i = j)
		{
			while (j <= m && a[j] == a[i])
				j++;
			if (a[i] == '1')
				sum[i][j - 1]++;
		}
	}

	for (int i = 1; i <= m; i++)
		for (int j = m; j >= 1; j--)
			sum[i][j] += sum[i - 1][j] + sum[i][j + 1] - sum[i - 1][j + 1];

	int res = 0;
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j++)
		{
			int cur = (j - i + 1) * sum[i][j];
			relax(res, cur);
		}
	cout << res << endl;

	return 0;
}