#include <bits/stdc++.h>
using namespace std;

int dat[200005];
constexpr int TSIZE = 200001;

double d1[200005], d2[200005];
double S[200005], R[200005], P[200005];
double *d = d1, *e = d2;

double getexp(int l, int r)
{
	return P[r] - P[l - 1] - S[l - 1] * (R[r] - R[l - 1]);
}

void divide_and_conquer(int l, int r, int lo, int hi)
{
	if (l > r) return;

	int m = (l + r) / 2;

	int minidx = -1;
	e[m] = 1e100;

	for (int i = lo; i <= min(m, hi); i++)
	{
		double res = getexp(i, m) + d[i - 1];
		if (res < e[m])
		{
			e[m] = res;
			minidx = i;
		}
	}

	divide_and_conquer(l, m - 1, lo, minidx);
	divide_and_conquer(m + 1, r, minidx, hi);
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
		S[i] = S[i - 1] + dat[i];
		R[i] = R[i - 1] + 1.0 / dat[i];
		P[i] = P[i - 1] + S[i] / dat[i];
	}

	for (int i = 1; i <= n; i++)
	{
		d[i] = getexp(1, i);
	}

	for (int t = 2; t <= k; t++)
	{
		divide_and_conquer(1, n, 1, n);

		swap(d, e);
	}

	printf("%.9f\n", d[n]);
}