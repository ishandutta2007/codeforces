#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int K = 10;
const int pow2 = (1 << 18);

struct SegmentTree
{
	int tree[pow2 * 2];
	int d[pow2 * 2];
	SegmentTree ()
	{
		for (int i = 0; i < pow2 * 2; i++)
		{
			d[i] = -1;
			tree[i] = 0;
		}
	}
	inline void push(int v, int len)
	{
		if (d[v] == -1)
			return;
		tree[2 * v] = d[v] * len;
		d[2 * v] = d[v];

		tree[2 * v + 1] = d[v] * len;
		d[2 * v + 1] = d[v];

		d[v] = -1;
	}
	void setZero(int a, int b, int v, int l, int r)
	{
		if (l >= a && r <= b)
		{
			tree[v] = d[v] = 0;
			return;
		}
		if (l > b || r < a)
			return;
		push(v, (r - l + 1) / 2);
		int m = (l + r) / 2;
		setZero(a, b, 2 * v, l, m);
		setZero(a, b, 2 * v + 1, m + 1, r);
		tree[v] = tree[2 * v] + tree[2 * v + 1];
	}
	void setValue(int a, int b, int value, int v, int l, int r)
	{
		if (l >= a && r <= b)
		{
			tree[v] = value * (r - l + 1);
			d[v] = value;
			return;
		}
		if (l > b || r < a)
			return;
		push(v, (r - l + 1) / 2);
		int m = (l + r) / 2;
		setValue(a, b, value, 2 * v, l, m);
		setValue(a, b, value, 2 * v + 1, m + 1, r);
		tree[v] = tree[2 * v + 1] + tree[2 * v];
	}
	void setValue(int a, int b, int value)
	{
		if (a > b)
			return;
		if (value == 0)
			setZero(a, b, 1, 0, pow2 - 1);
		else
			setValue(a, b, value, 1, 0, pow2 - 1);
	}
	int getSum(int a, int b, int v, int l, int r)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return 0;
		push(v, (r - l + 1) / 2);
		int m = (l + r) / 2;
		return getSum(a, b, 2 * v, l, m) + getSum(a, b, 2 * v + 1, m + 1, r);
	}
	int getSum(int a, int b)
	{
		if (a > b)
			return 0;
		return getSum(a, b, 1, 0, pow2 - 1);
	}
};

char str[pow2];
SegmentTree pairs[K][K];
SegmentTree treeStr;
int n, k;

set <pii> segments;
int used[K][K];
int tme = 1;

void setQuery(int l, int r, char c)
{
	int code = c - 'a';

	tme++;
	int leftleft = -1;
	auto lIt = prev(segments.upper_bound(mp(l, k)));
	segments.insert(mp(l, lIt -> Y));

	while (1)
	{
		auto it = segments.lower_bound(mp(l, -1));
		if (it == segments.end() || it -> X > r)
			break;

		pii value = *it;
		if (leftleft == -1)
			leftleft = value.Y;

		int a = value.Y;
		auto nxt = next(it);
		if (nxt != segments.end())
		{
			int b = nxt -> Y;
			if (nxt -> X > r + 1)
				segments.insert(mp(r + 1, value.Y));
			if (used[a][b] != tme)
			{
				used[a][b] = tme;
				pairs[a][b].setValue(l, r - 1, 0);
			}
		}
		else
		{
			if (r != n - 1)
				segments.insert(mp(r + 1, value.Y));
		}
		segments.erase(value);
	}
	segments.insert(mp(l, code));
	for (int i = 0; i < k; i++)
		if (used[i][i] != tme)
			pairs[i][i].setValue(l, r - 1, 0);

	if (l > 0)
	{
		int lCode = treeStr.getSum(l - 1, l - 1);
		int old = treeStr.getSum(l, l);
//		eprintf("%d %d\n", lCode, old);
		if (used[lCode][leftleft] != tme)
		{
			used[lCode][leftleft] = tme;
			pairs[lCode][leftleft].setValue(l, r - 1, 0);
		}

		pairs[lCode][old].setValue(l - 1, l - 1, 0);
		pairs[lCode][code].setValue(l - 1, l - 1, 1);
	}
	if (r < n - 1)
	{
		int rCode = treeStr.getSum(r + 1, r + 1);
		int old = treeStr.getSum(r, r);

		pairs[old][rCode].setValue(r, r, 0);
		pairs[code][rCode].setValue(r, r, 1);
	}
//	for (int i = 0; i < k; i++)
//	{
//		for (int s = 0; s < k; s++)
//		{
//			if (used[i][s] == tme)
//				eprintf("%c%c\n", i + 'a', s + 'a');
//		}
//	}
	pairs[code][code].setValue(l, r - 1, 1);
	treeStr.setValue(l, r, code);
}

void askQuery()
{
	int ans = 1;
	for (int i = 0; i < k; i++)
	{
		for (int s = i; s < k; s++)
		{
			ans += pairs[str[s] - 'a'][str[i] - 'a'].getSum(0, pow2 - 1);
		}
	}
	printf("%d\n", ans);
}

int main()
{
	int m;
	scanf("%d%d%d", &n, &m, &k);
	scanf(" %s", str);
	int len = 1;
	for (int i = 1; i < n; i++)
	{
		if (str[i] == str[i - 1])
			len++;
		else
		{
			segments.insert(mp(i - len, str[i - 1] - 'a'));
			len = 1;
		}
	}
	segments.insert(mp(n - len, str[n - 1] - 'a'));

	for (int i = 0; i < n; i++)
	{
		treeStr.setValue(i, i, str[i] - 'a');
		if (i < n - 1)
			pairs[str[i] - 'a'][str[i + 1] - 'a'].setValue(i, i, 1);
	}
	for (int i = 0; i < m; i++)
	{
		int tp;
		scanf("%d", &tp);
		if (tp == 1)
		{
			int l, r;
			char c;
			scanf("%d%d %c", &l, &r, &c);
			l--, r--;
			setQuery(l, r, c);
		}
		else
		{
			scanf(" %s", str);
			askQuery();
		}
	}
	return 0;
}