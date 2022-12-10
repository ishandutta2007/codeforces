#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;

const int N = 100500;

struct FenTree
{
	ll a[N];
	FenTree(): a() {}
	void add(int v, ll x)
	{
		for (int i = v; i < N; i |= i + 1)
			a[i] += x;
	}
	ll get(int v)
	{
		ll s = 0;
		for (int i = v; i >= 0; i = (i & (i + 1)) - 1)
			s += a[i];
		return s;
	}
};

int n, m;
int income[N], cool[N], kill[N];
int last[N];
FenTree fen;
set<int> occupied;

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &income[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &cool[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &kill[i]);

	vector<pair<int, int>> stack;
	for (int i = n - 1; i >= 0; i--)
		if (stack.empty() || stack.back().first < income[i])
			stack.emplace_back(income[i], i);

	for (int i = 0; i < m; i++)
	{
		auto it = lower_bound(stack.begin(), stack.end(), make_pair(cool[i], -1));
		last[i] = it == stack.end() ? -1 : it->second;
	}

	for (int i = 0; i < n; i++)
	{
		occupied.insert(i);
		fen.add(i, income[i]);
	}

	vector<int> order(m);
	for (int i = 0; i < m; i++)
		order[i] = i;
	sort(order.begin(), order.end(), [] (int a, int b)
	{
		return kill[a] < kill[b];
	});

	int ans = 0;

	for (int i : order)
	{
		int p = last[i];
		if (p == -1 || fen.get(p) < kill[i])
			continue;

		ans++;
		ll sum = kill[i];

		auto it = prev(occupied.upper_bound(p));
		while (true)
		{
			ll delta = min(sum, (ll)income[*it]);
			sum -= delta;
			income[*it] -= delta;
			fen.add(*it, -delta);
			if (sum == 0)
				break;
			auto prv = prev(it);
			occupied.erase(it);
			it = prv;
		}
	}

	printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif

	solve();

	eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}