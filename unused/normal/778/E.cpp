#include <bits/stdc++.h>
using namespace std;

char a[1005];
int n;
string str[1005];
int cost[11];
int cnt1[1005][1005][11];
int cnt2[1005][1005][11];
int dp[1005][1005];
bool v[1005][1005];
int alen;

int D(int idx, int k)
{
	if (idx == 1000) return k * cost[1];

	if (v[idx][k] == false)
	{
		v[idx][k] = true;

		int lo = 0, hi = 9;
		if (a[idx] != '?') lo = hi = a[idx] - '0';
		else if (idx == alen - 1) lo = 1;
		while (lo <= hi)
		{
			int val = 0;

			int total[11] = {};
			for (int i = (idx <= alen - 1) ? 0 : 1; i <= 10; i++)
			{
				total[(i + lo + 9) % 10 + 1] += cnt2[idx][k][i] + cnt1[idx][n][i] - cnt1[idx][k][i];
			}

			int upper = cnt2[idx][k][10];
			for (int i = 10 - lo; i <= 9; i++) upper += cnt2[idx][k][i] + cnt1[idx][n][i] - cnt1[idx][k][i];

			for (int i = 1; i <= 10; i++) val += total[i] * cost[i];

			dp[idx][k] = max(dp[idx][k], val + D(idx + 1, upper));

			++lo;
		}
	}

	return dp[idx][k];
}

int order[2][1001];

int main()
{
	scanf("%s%d", a, &n);
	alen = strlen(a);
	reverse(a, a + alen);
	for (int i = alen; i < 1000; i++) a[i] = '0';
	for (int i = 1; i <= n; i++)
	{
		char buf[1005];
		scanf("%s", buf);
		str[i] = buf;
		reverse(str[i].begin(), str[i].end());
	}

	for (int i = 0; i < 10; i++) scanf("%d", &cost[i]);
	cost[10] = cost[0];

	int *o1 = order[0], *o2 = order[1];
	for (int i = 1; i <= n; i++) o1[i] = i;

	for (int i = 0; i < 1000; i++)
	{
		int cnt[10] = {}, idx[10] = {};

		for (int j = 1; j <= n; j++)
		{
			int dg = str[o1[j]].size() <= i ? 0 : (str[o1[j]][i] - '0' + 9) % 10 + 1;
			cnt[dg % 10]++;

			for (int k = 0; k <= 10; k++) cnt1[i][j][k] = cnt1[i][j - 1][k];
			cnt1[i][j][dg]++;

			for (int k = 0; k <= 10; k++) cnt2[i][j][k] = cnt2[i][j - 1][k];
			cnt2[i][j][dg % 10 + 1]++;
		}

		idx[9] = 1;
		for (int i = 8; i >= 0; i--) idx[i] = idx[i + 1] + cnt[i + 1];

		for (int j = 1; j <= n; j++)
		{
			int dg = str[o1[j]].size() <= i ? 0 : (str[o1[j]][i] - '0') % 10;
			o2[idx[dg]++] = o1[j];
		}

		swap(o1, o2);
	}

	printf("%d\n", D(0, 0));
}