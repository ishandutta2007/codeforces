#include "bits/stdc++.h"
using namespace std;

using ll = long long;

struct team
{
	int idx;
	ll b, w;
	bool operator<(const team &rhs) const
	{
		if (b != rhs.b) return b > rhs.b;
		return idx < rhs.idx;
	}
};

team dat[300005];
vector<pair<ll,int>> diffs;
constexpr int TSIZE = 524288;
pair<ll, int> stree[TSIZE * 2 + 1];

void update(int pos, ll val)
{
	pos += TSIZE;
	stree[pos] = { val, 1 };
	while (pos >>= 1)
	{
		stree[pos].first = min((ll)2e18, stree[pos << 1].first + stree[pos << 1 | 1].first);
		stree[pos].second = stree[pos << 1].second + stree[pos << 1 | 1].second;
	}
}

int query(int node, ll remain)
{
	if (remain <= 0) return 0;
	if (stree[node].second == 0) return 0;

	if (stree[node].first <= remain) return stree[node].second;

    if ((node << 1) >= TSIZE * 2) return 0;

	if (stree[node << 1].first <= remain) return stree[node << 1].second + query(node << 1 | 1, remain - stree[node << 1].first);
	else return query(node << 1, remain);
}

int tpos[300005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &dat[i].b, &dat[i].w);
		dat[i].idx = i;
		diffs.emplace_back(dat[i].w - dat[i].b + 1, i);
	}

	sort(diffs.begin(), diffs.end());
	for (int i = 0; i < n; i++) tpos[diffs[i].second] = i;

	sort(dat, dat + n);

	int s = 0;
	while (dat[s].idx)
	{
		update(tpos[dat[s].idx], dat[s].w - dat[s].b + 1);
		s++;
	}
	// s:  

	int ans = s + 1;
	ll last = dat[s].b;

	for (int i = s + 1; i <= n; update(tpos[dat[i].idx], dat[i].w - dat[i].b + 1), i++)
	{
		if (dat[i].b == last) continue;
		last = dat[i].b;
		ans = min(ans, i - query(1, dat[s].b - last));
	}

	printf("%d", ans);
}