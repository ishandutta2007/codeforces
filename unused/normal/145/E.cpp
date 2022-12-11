#include <bits/stdc++.h>
using namespace std;

// example implementation of sum tree
const int TSIZE = 1048576; // always 2^k form && n <= TSIZE

array<int, 4> segtree[TSIZE * 2 + 1];
int prop[TSIZE * 2 + 1];
char dat[1000005];

array<int, 4> merge(const array<int, 4> &left, const array<int, 4> &right)
{
	return{
		left[0] + right[0],
		left[1] + right[1],
		max({
			left[0] + right[1],
			left[0] + right[2],
			left[2] + right[1]
			}),

		max({
			left[1] + right[3],
			left[3] + right[0],
			left[1] + right[0]
		}),
	};
	//4 ~ 4, 7 ~ 7, 4 ~ 7, 7 ~ 4
}

void flip(array<int, 4> &node)
{
	swap(node[0], node[1]);
	swap(node[2], node[3]);
}

void seg_init(int nod, int l, int r) {
	if (l == r)
	{
		if (dat[l] == '4')
		{
			segtree[nod][0] = 1;
		}
		else
		{
			segtree[nod][1] = 1;
		}
	}
	else {
		int m = (l + r) >> 1;
		seg_init(nod << 1, l, m);
		seg_init(nod << 1 | 1, m + 1, r);
		segtree[nod] = merge(segtree[nod << 1], segtree[nod << 1 | 1]);
	}
}
void seg_relax(int nod, int l, int r) {
	if (prop[nod] == 0) return;
	if (l < r) {
		int m = (l + r) >> 1;
		flip(segtree[nod << 1]);
		prop[nod << 1] ^= 1;
		flip(segtree[nod << 1 | 1]);
		prop[nod << 1 | 1] ^= 1;
	}
	prop[nod] = 0;
}
array<int, 4> seg_query(int nod, int l, int r, int s, int e) {
	if (r < s || e < l) return{};
	if (s <= l && r <= e) return segtree[nod];
	seg_relax(nod, l, r);
	int m = (l + r) >> 1;
	return merge(seg_query(nod << 1, l, m, s, e), seg_query(nod << 1 | 1, m + 1, r, s, e));
}
void seg_update(int nod, int l, int r, int s, int e) {
	if (r < s || e < l) return;
	if (s <= l && r <= e) {
		flip(segtree[nod]);
		prop[nod] ^= 1;
		return;
	}
	seg_relax(nod, l, r);
	int m = (l + r) >> 1;
	seg_update(nod << 1, l, m, s, e);
	seg_update(nod << 1 | 1, m + 1, r, s, e);
	segtree[nod] = merge(segtree[nod << 1], segtree[nod << 1 | 1]);
}
// usage:
// seg_update(1, 0, n - 1, qs, qe, val);
// seg_query(1, 0, n - 1, qs, qe);

int main()
{
	int n, m;
	scanf("%d%d%s", &n, &m, dat);
	seg_init(1, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		char t;
		scanf(" %c%*s", &t);
		if (t == 'c')
		{
			auto ret = seg_query(1, 0, n - 1, 0, n - 1);
			printf("%d\n", max({ ret[0], ret[1], ret[2] }));
		}
		else
		{
			int a, b;
			scanf("%d%d", &a, &b);
			seg_update(1, 0, n - 1, a - 1, b - 1);
		}
	}
}