#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> PII;

const int MaxN = 300000;

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	static PII ap[MaxN];
	for (int i = 1; i <= n; i++)
		ap[i - 1] = PII(a[i], i);

	sort(ap, ap + n);

	static int prev[1 + MaxN + 1];
	static int next[1 + MaxN + 1];
	for (int i = 0; i <= n + 1; i++)
		prev[i] = i - 1;
	for (int i = 0; i <= n + 1; i++)
		next[i] = i + 1;

	const int L = 40;
	static double pre[L + 1];
	pre[0] = 1;
	for (int i = 1; i <= L; i++)
		pre[i] = pre[i - 1] / 2;

	double res = 0.0;
	for (int i = 0; i < n; i++)
	{
		int idx = ap[i].second;
		double val = ap[i].first;

		double orzL = 0.0;
		double orzR = 0.0;
		for (int v = idx, j = 1; v != 0 && j <= L; v = prev[v], j++)
			orzL += (double)(v - prev[v]) / n * pre[j];
		for (int u = idx, k = 1; u != n + 1 && k <= L; u = next[u], k++)
			orzR += (double)(next[u] - u) / n * pre[k - 1];

		res += val * orzL * orzR;

		next[prev[idx]] = next[idx];
		prev[next[idx]] = prev[idx];
	}

	cout << fixed << setprecision(10) << res << endl;

	return 0;
}