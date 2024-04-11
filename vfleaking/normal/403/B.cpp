#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 5000;
const int MaxM = 5000;

int gcd(int a, int b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int n, m;
int a[MaxN + 1], b[MaxM + 1];

int getPVal(int p)
{
	int *pos = lower_bound(b + 1, b + m + 1, p);
	if (pos == b + m + 1 || *pos != p)
		return 1;
	return -1;
}

int getVal(int num)
{
	int val = 0;
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
		{
			int pVal = getPVal(i);
			while (num % i == 0)
				val += pVal, num /= i;
		}
	if (num > 1)
		val += getPVal(num);
	return val;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	sort(b + 1, b + m + 1);

	int res = 0;
	for (int i = 1; i <= n; i++)
		res += getVal(a[i]);

	static int g[MaxN + 1];
	g[0] = 0;
	for (int i = 1; i <= n; i++)
		g[i] = gcd(g[i - 1], a[i]);

	int r = 1;
	for (int i = n; i >= 1; i--)
	{
		g[i] /= r;
		int val = getVal(g[i]);
		if (val < 0)
			r *= g[i], res -= i * val;
	}

	cout << res << endl;

	return 0;
}