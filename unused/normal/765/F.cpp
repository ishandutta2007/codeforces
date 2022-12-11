#include "bits/stdc++.h"
using namespace std;

int dat[100005];
int order[100005];
vector<int> qidx[100005];
int query[300005];
int ans[300005];
vector<int> values;

constexpr int TSIZE = 131072;

struct stree
{
	vector<int> dat = vector<int>( TSIZE * 2 + 1, INT_MAX );

	void update_r(int l, int r, int val)
	{
		l += TSIZE; r += TSIZE;
		while (l <= r)
		{
			if (l & 1) dat[l] = min(dat[l], val), ++l;
			if (!(r & 1)) dat[r] = min(dat[r], val), --r;
			l >>= 1; r >>= 1;
		}
	}

	void update(int pos, int val)
	{
		for (pos += TSIZE; pos; dat[pos] = min(dat[pos], val), pos >>= 1)
			;
	}

	int query(int pos)
	{
		int ret = INT_MAX;
		for (pos += TSIZE; pos; ret = min(ret, dat[pos]), pos >>= 1)
			;
		return ret;
	}

	int query_r(int l, int r)
	{
		int ret = INT_MAX;
		l += TSIZE; r += TSIZE;
		while (l <= r)
		{
			if (l & 1) ret = min(dat[l], ret), ++l;
			if (!(r & 1)) ret = min(dat[r], ret), --r;
			l >>= 1; r >>= 1;
		}
		return ret;
	}
};

stree lastpos, atree;

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&dat[i]);
		values.push_back(dat[i]);
	}

	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());
	for (int i = 1; i <= n; i++)
		order[i] = lower_bound(values.begin(), values.end(), dat[i])
			- values.begin();

	int m;
	scanf("%d",&m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		query[i] = a;
		qidx[b].push_back(i);
	}

	for (int i = 1; i <= n; i++)
	{
//		printf("process %d\n", i);
		int y = lastpos.query_r(0, order[i]);
		while (y != INT_MAX)
		{
			y = -y;
			atree.update_r(1, y, dat[i] - dat[y]);
//			printf("updating %d to %d\n", dat[i] - dat[y], y);
			// dat[i] - dat[z] < dat[z] - dat[y]
			// dat[z] > (dat[y] + dat[i]) / 2
			int idx = lower_bound(values.begin(), values.end(),
				(dat[y] + dat[i]) / 2) - values.begin();
			while (idx < values.size() && values[idx] * 2 <= dat[y] + dat[i]) ++idx;
			y = lastpos.query_r(idx, order[i]);
		}

		y = lastpos.query_r(order[i], TSIZE - 1);
		while (y != INT_MAX)
		{
			y = -y;
			atree.update_r(1, y, dat[y] - dat[i]);
//			printf("updating %d to %d\n", dat[y] - dat[i], y);
			// dat[z] - dat[i] < dat[y] - dat[z]
			// dat[z] < (dat[y] + dat[i]) / 2
			int idx = lower_bound(values.begin(), values.end(),
				(dat[y] + dat[i]) / 2) - values.begin();
			while (idx >= 0 && values[idx] * 2 >= dat[y] + dat[i]) --idx;
			y = lastpos.query_r(order[i], idx);
		}

		for (int t : qidx[i])
		{
			ans[t] = atree.query(query[t]);
//			printf("query %d is %d\n", query[t], ans[t]);
		}

		lastpos.update(order[i], -i);
	}

	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
}