#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> graph[100005];

struct dsu
{
	int n = 0, comp = 0;
	vector<int> p, r;
	dsu() {}
	void resize(int n)
	{
		comp = n;
		this->n = n;
		p.resize(n); r.resize(n); memset(&r[0], 0, sizeof(r[0])*n);
		for (int i = 0; i < n; i++) p[i] = i;
	}
	virtual int find(int t)
	{
		return t == p[t] ? t : (p[t] = find(p[t]));
	}
	bool merge(int a, int b)
	{
		int pa = find(a), pb = find(b);
		if (pa == pb) return false;
		if (r[pa] < r[pb]) swap(pa, pb);
		else if (r[pa] == r[pb]) r[pa]++;
		p[pb] = pa;
		--comp;
		return true;
	}
};

dsu tree[262145];
vector<tuple<int,int,int>> vt;
int ql, qr, qidx;

void build(int n, int l, int r)
{
	tree[n].resize(r - l + 1);
	if (l == r) return;

	for (int i = l; i < r; i++)
	{
		for (int t : graph[i])
		{
			if (t > r) break;
			tree[n].merge(i - l, t - l);
		}
	}

	int m = (l + r) / 2;
	build(2 * n, l, m);
	build(2 * n + 1, m + 1, r);
}

void query(int n, int l, int r)
{
	if (ql > r || qr < l) return;

	if (ql <= l && r <= qr)
	{
		vt.emplace_back(l, r, n);
		return;
	}

	if (l >= r) return;

	int m = (l + r) / 2;
	query(2 * n, l, m);
	query(2 * n + 1, m + 1, r);
}

int visit[100005];

struct dsu2 : dsu
{
	virtual int find(int t)
	{
		if (visit[t] != qidx)
		{
			visit[t] = qidx; p[t] = t; r[t] = 0;
		}
		return dsu::find(t);
	}
} ds2;

int main()
{
	int m;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		graph[a - 1].push_back(b - 1);
	}

	for (int i = 0; i < n; i++) sort(graph[i].begin(), graph[i].end());
	build(1, 0, n - 1);

	int q;
	scanf("%d", &q);
	ds2.resize(n);

	for (qidx = 1; qidx <= q; qidx++)
	{
		scanf("%d%d", &ql, &qr);
		ql--; qr--;
		vt.clear();
		query(1, 0, n - 1);
		sort(vt.begin(), vt.end());
		int ans = 0;

		for (int j = 0; j < vt.size(); j++)
		{
			int l, r, idx;
			tie(l, r, idx) = vt[j];
			ans += tree[idx].comp;

			for (int p = j - 1; p >= 0; p--)
			{
				int l2 = get<0>(vt[p]), r2 = get<1>(vt[p]);
				if (r2 < l - k) break;
				for (int x = max(l2, l - k); x <= r2; x++)
				{
					for (int y : graph[x])
					{
						if (l <= y && y <= r && ds2.merge(tree[idx].find(y - l) + l, tree[get<2>(vt[p])].find(x - l2) + l2)) --ans;
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}