#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int total = 0;
	vector<int> vt;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp < 0)
		{
			vt.push_back(i);
		}
	}

	if (vt.size() > k)
	{
		printf("-1");
		return 0;
	}

	if (vt.size() == 0)
	{
		printf("0");
		return 0;
	}

	int remain = k - vt.size();
	int ans = vt.size() * 2;

	vector<int> diffs;

	for (int i = 1; i < vt.size(); i++)
	{
		diffs.emplace_back(vt[i] - vt[i - 1] - 1);
	}

	sort(diffs.begin(), diffs.end());

	for (int i = 0; i < diffs.size(); i++)
	{
		if (remain < diffs[i]) break;
		remain -= diffs[i];
		ans -= 2;
	}

	if (k - vt.size() >= n - vt.back())
	{
		int remain2 = k - vt.size();
		int ans2 = vt.size() * 2 - 1;
		remain2 -= n - vt.back();

		for (int i = 0; i < diffs.size(); i++)
		{
			if (remain2 < diffs[i]) break;
			remain2 -= diffs[i];
			ans2 -= 2;
		}

		ans = min(ans, ans2);
	}

	printf("%d", ans);
}