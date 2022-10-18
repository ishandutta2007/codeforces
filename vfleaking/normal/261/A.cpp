#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;

const int MaxM = 100000;
const int MaxN = 100000;

int main()
{
	int m;
	static int q[MaxM + 1];
	int n;
	static int v[MaxN + 1];

	cin >> m;
	for (int i = 1; i <= m; i++)
		scanf("%d", &q[i]);
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	sort(v + 1, v + n + 1);

	int minQ = *min_element(q + 1, q + m + 1);
	int res = 0;
	while (n > 0)
	{
		if (n >= minQ + 2)
		{
			for (int i = 0; i < minQ; i++)
				res += v[n - i];
			n -= minQ + 2;
		}
		else if (n >= minQ + 1)
		{
			for (int i = 0; i < minQ; i++)
				res += v[n - i];
			n -= minQ + 1;
		}
		else
		{
			for (int i = 1; i <= n; i++)
				res += v[i];
			n = 0;
		}
	}
	cout << res << endl;

	return 0;
}