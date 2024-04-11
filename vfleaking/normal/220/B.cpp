#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int MaxN = 100000;
const int MaxNNum = 500;

int main()
{
	int n, m;
	static int a[MaxN + 1];

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	static pair<int, int> b[MaxN + 1];
	for (int i = 1; i <= n; i++)
		b[i] = make_pair(a[i], i);
	sort(b + 1, b + n + 1);

	static vector<int> num;
	static int sum[MaxNNum][MaxN + 1];

	for (int i = 1, j = 1; i <= n; i = j)
	{
		while (j <= n && b[i].first == b[j].first)
			j++;
		if (j - i >= b[i].first)
		{
			int index = num.size();
			num.push_back(b[i].first);

			sum[index][0] = 0;
			for (int k = 1; k <= n; k++)
			{
				sum[index][k] = sum[index][k - 1];
				if (a[k] == b[i].first)
					sum[index][k]++;
			}
		}
	}

	while (m--)
	{
		int l, r;
		scanf("%d %d", &l, &r);

		int res = 0;
		for (int i = 0; i < num.size(); i++)
		{
			int times = sum[i][r] - sum[i][l - 1];
			if (num[i] == times)
				res++;
		}
		printf("%d\n", res);
	}

	return 0;
}