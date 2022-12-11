#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int n;
int sqrtn;

struct query
{
	int idx;
	int s, e;
	bool operator<(const query &rhs) const
	{
		if (s / sqrtn != rhs.s / sqrtn)
			return s / sqrtn < rhs.s / sqrtn;
		return e < rhs.e;
	}
};

int dat[1000005];
int didx[1000005];
query qry[1000005];
int ans[1000005];
int cnt[1000005];
map<int, int> midx;

int main()
{
	scanf("%d",&n);
	sqrtn = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
		didx[i] = midx.emplace(dat[i], midx.size()).first->second;
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &qry[i].s, &qry[i].e);
		qry[i].idx = i;
	}

	sort(qry, qry + q);
	int now;
	int first;
	int last = 999999999;

	for (int i = 0; i < q; i++)
	{
		if (last > qry[i].e)
		{
			first = qry[i].s;
			last = qry[i].e;
			now = 0;
			memset(cnt, 0, sizeof(int)*midx.size());
			for (int j = first; j <= last; j++)
			{
				int c = ++cnt[didx[j]];
				if (c >= 2) now ^= dat[j];
			}
		}
		else
		{
			for (int j = first; j < qry[i].s; j++)
			{
				int c = --cnt[didx[j]];
				if (c >= 1) now ^= dat[j];
			}

			for (int j = qry[i].s; j < first; j++)
			{
				int c = ++cnt[didx[j]];
				if (c >= 2) now ^= dat[j];
			}

			for (int j = last + 1; j <= qry[i].e; j++)
			{
				int c = ++cnt[didx[j]];
				if (c >= 2) now ^= dat[j];
			}

			for (int j = qry[i].e + 1; j <= last; j++)
			{
				int c = --cnt[didx[j]];
				if (c >= 1) now ^= dat[j];
			}

			first = qry[i].s;
			last = qry[i].e;
		}
		ans[qry[i].idx] = now;
	}

	for (int i = 0; i < q; i++)
	{
		printf("%d\n", ans[i]);
	}
}