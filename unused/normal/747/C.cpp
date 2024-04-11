#include <bits/stdc++.h>
using namespace std;

int last[105];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++)
	{
		int t, k, d;
		scanf("%d%d%d", &t, &k, &d);

		vector<int> vt;

		for (int i = 0; i < n; i++)
		{
			if (last[i] <= t) vt.push_back(i);
		}

		if (vt.size() < k)
		{
			printf("-1\n");
			continue;
		}

		int ans = 0;

		for (int i = 0; i < k; i++)
		{
			last[vt[i]] = t + d;
			ans += vt[i] + 1;
		}

		printf("%d\n", ans);
	}
}