#include <bits/stdc++.h>
using namespace std;

long double dp[100005];
bool vis[100005];

int dat[100005];
constexpr int TSIZE = 100003;
long long fw1[100005], fw2[100005];

void update(int pos, long long val, long long *tr)
{
	for (; pos <= TSIZE; pos += pos & -pos)
		tr[pos] += val;
}

long long query(int pos, long long *tr)
{
	long long ret = 0;
	for (; pos; pos -= pos & -pos) ret += tr[pos];
	return ret;
}

long double D(int t)
{
	if (t <= 1) return 0;
	if (vis[t] == false)
	{
		vis[t] = true;

		dp[t] = (t - 1) * 0.5L + D(t - 1);
	}

	return dp[t];
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
	}

	long double ans2 = 0;

	for (int i = 1; i <= n; i++)
	{
		long long cnt = query(n - dat[i], fw1);
		long long sum = query(n - dat[i], fw2);

		ans2 += cnt - (n - i + 1) * 2.0L / n / (n + 1) * sum;

		update(n - dat[i] + 1, 1, fw1);
		update(n - dat[i] + 1, i, fw2);
	}

	long double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += (n - i + 1) * D(i);
	}

	printf("%.15Lf\n", ans / n / (n + 1) * 2 + ans2);
	/*
	double total = 0;
	int iter1 = 0;
	int buf[10];

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++, ++iter1)
		{
			for (int k = i; k <= j; k++) buf[k] = dat[k];
			sort(dat + i, dat + j + 1);
			long long tot = 0;
			int iter = 0;
			do
			{
				++iter;

				for (int x = 1; x <= n; x++) for (int y = x + 1; y <= n; y++)
				{
					if (dat[x] > dat[y]) tot++;
				}
			} while (next_permutation(dat + i, dat + j + 1));

			total += tot / (long double)iter;
			for (int k = i; k <= j; k++) dat[k] = buf[k];
		}
	}

	printf("%.15Lf\n", total / (long double)iter1);
}*/
}