#include "bits/stdc++.h"
using namespace std;

struct gas
{
	int pos;
	int price;
	bool operator<(const gas &r) const
	{
		return pos < r.pos;
	}
};

gas dat[200005];
constexpr int TSIZE = 262144;
pair<int,int> mintree[TSIZE * 2 + 1];

void update(int pos, int val)
{
	mintree[pos + TSIZE] = {val, pos};
	for (pos += TSIZE; pos >>= 1;)
	{
		mintree[pos] = min(mintree[pos<<1], mintree[pos<<1|1]);
	}
}

pair<int,int> get(int s, int e)
{
	s += TSIZE; e += TSIZE;
	pair<int,int> ret = {(int)2e9, (int)2e9};
	while (s <= e)
	{
		if (s&1) ret=min(ret, mintree[s++]);
		if (!(e&1)) ret=min(ret, mintree[e--]);
		s >>= 1; e >>= 1;
	}
	return ret;
}

int main()
{
	int n, d, m;
	scanf("%d%d%d",&n,&d,&m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d",&dat[i].pos,&dat[i].price);
	}
	dat[m] = {n, 0};
	sort(dat,dat+m+1);
	for (int i = 0; i <= m; i++)
	{
		update(i, dat[i].price);
	}

	int now = 0;
	int oil = d;
	long long ans = 0;
	int lastprice = 0;

	while (now + oil < n)
	{
		int l = lower_bound(dat, dat + m + 1, gas{now + 1, 0}) - dat;
		int r = upper_bound(dat, dat + m + 1, gas{now + d, 0}) - dat - 1;
		if (l > r)
		{
			printf("-1");
			return 0;
		}

		int ll = l;

		int target = -1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (get(ll, m).first <= lastprice)
			{
				target = m; r = m - 1;
			}
			else l = m + 1;
		}

		if (target == -1)
		{
			int inc = min(d - oil, n - now - oil);
			if (inc > 0)
			{
				oil += inc;
				ans += inc * 1ll * lastprice;
			}

			oil -= dat[ll].pos - now;
			now = dat[ll].pos;
			lastprice = dat[ll].price;
		}
		else
		{
			gas g = dat[target];
			int dist = g.pos - now;
			if (oil < dist)
			{
				int inc = dist - oil;
				ans += 1ll * inc * lastprice;
				oil += inc;
			}
			oil -= dist;
			now = g.pos;
			lastprice = g.price;
		}
	}

	printf("%lld", ans);
}