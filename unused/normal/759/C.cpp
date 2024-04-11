#include <bits/stdc++.h>
using namespace std;

// example implementation of sum tree
const int TSIZE = 131072; // always 2^k form && n <= TSIZE
pair<int, int> segtree[TSIZE * 2];
int prop[TSIZE * 2];
void seg_relax(int nod, int l, int r) {
	if (prop[nod] == 0) return;
	if (l < r) {
		int m = (l + r) >> 1;
		segtree[nod << 1].first += prop[nod];
		segtree[nod << 1].second += (m - l + 1) * prop[nod];
		prop[nod << 1] += prop[nod];
		segtree[nod << 1 | 1].first += prop[nod];
		segtree[nod << 1 | 1].second += (r - m) * prop[nod];
		prop[nod << 1 | 1] += prop[nod];
	}
	prop[nod] = 0;
}
pair<int, int> seg_query(int nod, int l, int r, int s, int e) {
	if (r < s || e < l) return{ -(int)2e9, 0 };
	if (s <= l && r <= e) return segtree[nod];
	seg_relax(nod, l, r);
	int m = (l + r) >> 1;
	auto left = seg_query(nod << 1, l, m, s, e);
	auto right = seg_query(nod << 1 | 1, m + 1, r, s, e);
	return{ max(left.first, right.first), left.second + right.second };
}

void seg_update(int nod, int l, int r, int s, int e, int val) {
	if (r < s || e < l) return;
	if (s <= l && r <= e) {
		segtree[nod].first += val;
		segtree[nod].second += (r - l + 1) * val;
		prop[nod] += val;
		return;
	}
	seg_relax(nod, l, r);
	int m = (l + r) >> 1;
	seg_update(nod << 1, l, m, s, e, val);
	seg_update(nod << 1 | 1, m + 1, r, s, e, val);
	segtree[nod].first = max(segtree[nod << 1].first, segtree[nod << 1 | 1].first);
	segtree[nod].second = segtree[nod << 1].second + segtree[nod << 1 | 1].first;
}
// usage:
// seg_update(1, 0, n - 1, qs, qe, val);
// seg_query(1, 0, n - 1, qs, qe);

int dat[100005];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b, c = 0;
		scanf("%d%d", &a, &b);
		a--;
		if (b == 1)
		{
			scanf("%d", &c);
			dat[a] = c;
			seg_update(1, 0, n - 1, 0, a, 1);
		}
		else
		{
			seg_update(1, 0, n - 1, 0, a, -1);
		}

		int lo = 0, hi = n - 1, ans = -1;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (seg_query(1, 0, n - 1, mid, n - 1).first <= 0)
			{
				hi = mid - 1;
			}
			else
			{
				ans = mid;
				lo = mid + 1;
			}
		}

		if (ans == -1) printf("-1\n");
		else printf("%d\n", dat[ans]);
	}

}