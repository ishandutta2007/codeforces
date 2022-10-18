#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 150000;
const int MaxTN = 262144;
const int MaxM = 150000;

int tn;
int seg[MaxTN << 1 | 1];
int seg_d[MaxTN << 1 | 1];

void seg_add(int l, int r, int d)
{
	if (l > r)
		return;
	for (l += tn - 1, r += tn + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if (~l & 1)
			seg_d[l ^ 1] += d, seg[l ^ 1] += d;
		if (r & 1)
			seg_d[r ^ 1] += d, seg[r ^ 1] += d;
		seg[l >> 1] = min(seg[l], seg[l ^ 1]) + seg_d[l >> 1];
		seg[r >> 1] = min(seg[r], seg[r ^ 1]) + seg_d[r >> 1];
	}
	while (l > 1)
	{
		seg[l >> 1] = min(seg[l], seg[l ^ 1]) + seg_d[l >> 1];
		l >>= 1;
	}
}

int main()
{
	int n, m, h;
	static int a[MaxN + 1];
	static int b[MaxM + 1];

	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	sort(b + 1, b + m + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] = b + m + 1 - lower_bound(b + 1, b + m + 1, h - a[i]);
	}

	tn = 1;
	while (tn < m + 2)
		tn <<= 1;

	int res = 0;
	for (int i = 1; i <= m; i++)
		seg_add(i, i, -(m - i + 1));
	for (int i = 1; i < m; i++)
		seg_add(1, a[i], 1);
	for (int i = m; i <= n; i++)
	{
		seg_add(1, a[i - m], -1);
		seg_add(1, a[i], 1);
		if (seg[1] >= 0)
			res++;
	}

	cout << res << endl;

	return 0;
}