#include <bits/stdc++.h>
using namespace std;

int n, K;
int v[400001], f[400001];

bool check(int x)
{
	for (int i = 0; i <= n; ++ i) f[i] = 0;
	if (v[K] - v[1] > x) return 0;
	f[K] = f[0] = 1;
	int t = 0; int sum = 1;
	for (int i = K + 1; i <= n; ++ i)
	{
		// [t, i - K]
		sum += f[i - K];
		while (t <= i - K && v[i] - v[t + 1] > x) sum -= f[t], ++t;
		if (sum > 0) f[i] = 1;
	}
	return f[n];
}

int main()
{
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; ++ i) scanf("%d", &v[i]);
	sort(v + 1, v + 1 + n);
	int L = 0, R = 1000000000;
	while (R - L + 1 > 0)
	{
		int mid = (L + R) >> 1;
		if (check(mid)) R = mid - 1;
		else L = mid + 1;
	}
	printf("%d\n", L);
	return 0;
}