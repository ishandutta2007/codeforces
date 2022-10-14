#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 5;
int T, n, q, a[maxn], ans[maxn], cnt[maxn];
vector<int> g[maxn];
int sum[4 * maxn];

struct query { int l, k, id; };

vector<query> qq[maxn];

void update(int node, int l, int r, int x, int y)
{
	sum[node] += y;
	if (l == r) return;
	int mid = l + r >> 1;
	if (x <= mid) update(node * 2, l, mid, x, y);
	else update(node * 2 + 1, mid + 1, r, x, y);
}

int ff;

void walk(int node, int l, int r, int ll, int rr, int trg)
{
	assert(trg > 0);
	if (l > r || l > rr || r < ll || trg > sum[node]) return;
	if (l == r) 
	{
		ff = l;
		return;
	}
	int mid = l + r >> 1;
	if (trg <= sum[node * 2 + 1] && sum[node * 2 + 1] > 0)
		walk(node * 2 + 1, mid + 1, r, ll, rr, trg);
	else
		walk(node * 2, l, mid, ll, rr, trg - sum[node * 2 + 1]);
}

int get(int node, int l, int r, int ll, int rr)
{
	if (l > r || l > rr || r < ll) return 0;
	if (ll <= l && r <= rr) return sum[node];
	int mid = l + r >> 1;
	return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
}

set<int> dq[maxn];

void dfs(int u, int par)
{
	if (cnt[a[u]] > 0) 
	{
		update(1, 0, n, cnt[a[u]], -1);
		dq[cnt[a[u]]].erase(dq[cnt[a[u]]].find(a[u]));
	}
	cnt[a[u]]++;
	update(1, 0, n, cnt[a[u]], 1);
	dq[cnt[a[u]]].insert(a[u]);
	for (auto pp : qq[u])
	{
		ff = -1;
		int tot_seg = get(1, 0, n, pp.l, n);
		if (tot_seg < pp.k)
			ans[pp.id] = -1;
		else {
			ff = -1;
			walk(1, 0, n, pp.l, n, tot_seg - pp.k + 1);
			/*int low = pp.l, high = n;
			while (low <= high) 
			{
				int mid = low + high >> 1;
				if (get(1, 0, n, mid, n) >= tot_seg - pp.k + 1) 
					ff = mid, low = mid + 1;
				else
					high = mid - 1;
			}*/
			assert(ff != -1 && dq[ff].size() > 0);
			assert(get(1, 0, n, ff + 1, n) < tot_seg - pp.k + 1);
			assert(get(1, 0, n, ff, n) >= tot_seg - pp.k + 1);
			ans[pp.id] = *prev(dq[ff].end());
		}
	}
	for (int v : g[u])
	{
		if (v == par) continue;
		dfs(v, u);
	}
	dq[cnt[a[u]]].erase(dq[cnt[a[u]]].find(a[u]));
	update(1, 0, n, cnt[a[u]], -1);
	cnt[a[u]]--;
	if (cnt[a[u]] > 0) 
	{
		update(1, 0, n, cnt[a[u]], 1);
		dq[cnt[a[u]]].insert(a[u]);
	}
}

void solve()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		qq[i].clear();
		g[i].clear();
	}
	assert(sum[1] == 0);
	for (int i = 0; i <= n; i++) 
	{
		assert(dq[i].empty());
		cnt[i] = 0;
	}
	for (int i = 1; i < n; i++) 
	{
		int p;
		scanf("%d", &p);
		--p;
		g[i].push_back(p);
		g[p].push_back(i);
	}
	for (int i = 0; i < q; i++)
	{
		int v, l, k;
		scanf("%d %d %d", &v, &l, &k);
		--v;
		qq[v].push_back({l, k, i});
		ans[i] = 0;
	}
	dfs(0, 0);
	for (int i = 0; i < q; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		solve();
	}
}