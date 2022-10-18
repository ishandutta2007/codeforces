#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 2000;

int main()
{
	int n, m;
	static int f[MaxN];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &f[i]);
	sort(f, f + n);

	int res = 0;
	for (int i = 2; ; i++)
	{
		int cnt = 0;
		for (int k = 0; k < n; k++)
			if (f[k] >= i)
				cnt++;
		if (cnt == 0)
			break;
		res += (cnt + m - 1) / m * 2;
	}
	cout << res << endl;

	return 0;
}