#include <bits/stdc++.h>
using namespace std;

pair<int, int> dat[200005];
vector<int> idx[200005];
vector<int> query[200005];
vector<int> qidx[200005];
int qptr[200005];
int ans[200005];
bool used[200005];
map<int, int> last;
vector<pair<int, int>> order;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &dat[i].first, &dat[i].second);
		idx[dat[i].first].push_back(i);
		last[dat[i].first] = i;
		used[dat[i].first] = true;
	}

	for (auto &&e : last) order.emplace_back(e.second, e.first);
	sort(order.begin(), order.end());
	for (auto &&e : order) e = make_pair( e.second, e.first );

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		query[i].resize(k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &query[i][j]);
			if (used[query[i][j]] == false)
			{
				query[i].pop_back();
				--j; --k;
			}
		}

		for (int j = 0; j < k; j++) qidx[query[i][j]].push_back(i);

		qptr[i] = order.size() - 1;
	}

	for (int i = order.size() - 1; i >= 0; i--)
	{
		for (int q : qidx[order[i].first])
		{
			if (qptr[q] == i) --qptr[q];
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (qptr[i] == -1) {
			printf("0 0\n"); continue;
		}
		int z = order[qptr[i]].first;

		int lo = 0, hi = (int)idx[z].size() - 2, ans = hi + 1;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			int total = n - idx[z][mid] - (idx[z].size() - mid - 1);
			// mid    
			for (int x : query[i])
			{
				if (x == z) continue;
				total -= idx[x].end() - lower_bound(idx[x].begin(), idx[x].end(), idx[z][mid]);
			}

			if (total == 0)
			{
				ans = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}

		printf("%d %d\n", z, dat[idx[z][ans]].second);
	}
}