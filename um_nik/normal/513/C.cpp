#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 6;
const int M = (int)1e4 + 4;
int n;
int l[N], r[N];
double ans;

double solve2(int val, int mask, int p)
{
	double res = 1.;
	for (int i = 0; i < n; i++)
	{
		if (i == p)
		{
			int len = r[i] - l[i] + 1;
			int q = r[i] - val;
			if (q < 0) q = 0;
			if (q > len) q = len;
			res *= (double)q / len;
		}
		else if (mask & (1 << i))
		{
			if (l[i] <= val && val <= r[i])
				res /= (double)(r[i] - l[i] + 1);
			else
				res = 0;
		}
		else
		{
			int len = r[i] - l[i] + 1;
			int q = val - l[i];
			if (q > len) q = len;
			if (q < 0) q = 0;
			res *= (double)q / len;
		}
	}
	return res;
}

double solve(int val)
{
	double res = 0.;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
				cnt++;
		if (cnt < 2) continue;
		res += solve2(val, mask, -1);
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
				res += solve2(val, mask, i);
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	for (int val = 1; val < M; val++)
		ans += solve(val) * val;
	printf("%.11lf\n", ans);

	return 0;
}