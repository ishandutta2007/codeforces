#include <bits/stdc++.h>
using namespace std;

struct barrier
{
	int u, l, r, s;
	bool operator<(const barrier &z) const
	{
		return u > z.u;
	}
};

barrier dat[100005];
pair<int, int> lim[100005];
pair<int, int> nxt[100005];
int cnt[100005];
constexpr int MOD = 1000000007;
constexpr int TSIZE = 131072;

struct stree
{
	vector<set<int>> dat = vector<set<int>>(TSIZE * 2 + 1);

	void update(int l, int r, int val)
	{
		l += TSIZE; r += TSIZE;
		while (l <= r)
		{
			if (l & 1) dat[l].insert(val), ++l;
			if (!(r & 1)) dat[r].insert(val), --r;
			l >>= 1; r >>= 1;
		}
	}

	void erase(int l, int r, int val)
	{
		l += TSIZE; r += TSIZE;
		while (l <= r)
		{
			if (l & 1) dat[l].erase(val), ++l;
			if (!(r & 1)) dat[r].erase(val), --r;
			l >>= 1; r >>= 1;
		}
	}

	int query(int pos)
	{
		int ret = INT_MAX;
		for (pos += TSIZE; pos; pos >>= 1)
			if (dat[pos].empty() == false) ret = min(ret, *dat[pos].begin());
		return ret;
	}
};

stree mintree;

int main()
{
	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &dat[i].u, &dat[i].l, &dat[i].r, &dat[i].s);
	}
	sort(dat, dat + n);

	priority_queue<pair<int, int>> pq;

	for (int i = n - 1; i >= 0; i--)
	{
		while (pq.empty() == false && -pq.top().first <= dat[i].u)
		{
			int t = pq.top().second;
			pq.pop();
			mintree.erase(dat[t].l, dat[t].r, t);
		}
		if (dat[i].l == 1)
		{
			nxt[i].first = nxt[i].second = mintree.query(dat[i].r + 1);
		}
		else if (dat[i].r == w)
		{
			nxt[i].first = nxt[i].second = mintree.query(dat[i].l - 1);
		}
		else
		{
			nxt[i].first = mintree.query(dat[i].l - 1); 
			nxt[i].second = mintree.query(dat[i].r + 1);
		}
		mintree.update(dat[i].l, dat[i].r, i);
		pq.emplace(-(dat[i].u + dat[i].s + 1), i);
	}

	while (pq.empty() == false && -pq.top().first <= h + 1)
	{
		int t = pq.top().second;
		pq.pop();
		mintree.erase(dat[t].l, dat[t].r, t);
	}

	int ans = 0;

	for (int i = 1; i <= w; i++)
	{
		int z = mintree.query(i);
		if (z == INT_MAX) ++ans;
		else cnt[z]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (nxt[i].first == INT_MAX) ans = (ans + cnt[i]) % MOD;
		else cnt[nxt[i].first] = (cnt[nxt[i].first] + cnt[i]) % MOD;

		if (nxt[i].second == INT_MAX) ans = (ans + cnt[i]) % MOD;
		else cnt[nxt[i].second] = (cnt[nxt[i].second] + cnt[i]) % MOD;
	}

	printf("%d\n", ans);
}