#include <bits/stdc++.h>
using namespace std;

vector<int> graph[300005];
int dat[300005];

constexpr int NUM = 2;

struct hashfunc
{
	size_t operator()(const array<uint32_t, NUM> &arr) const
	{
		return arr[0];
	}
};

unordered_set<array<uint32_t, NUM>, hashfunc> cnt;
unordered_set<array<uint32_t, NUM>, hashfunc> cnt2;
int total[300005];
int depth[300005];
int childcnt[300005];
array<uint32_t, NUM> hval[300005];

constexpr uint32_t Q[] =
{
	1000000007,
	1000000007,
	1000000009,
	1000000009,
};

constexpr uint32_t P[] =
{
	1000003,
	1000033,
	70001,
	4000037,
};

uint32_t power[NUM][300005];

void pdfs(int t)
{
	total[depth[t]]++;
	childcnt[t] = 1;
	for (int nxt : graph[t])
	{
		depth[nxt] = depth[t] + 1;
		for (int i = 0; i < NUM; i++)
		{
			hval[nxt][i] = (hval[t][i] + power[i][depth[nxt]] * 1ull * dat[nxt]) % Q[i];
		}
		pdfs(nxt);
		childcnt[t] += childcnt[nxt];
	}
}

void calc(int base, int t, int h, int z)
{
	if (depth[t] >= depth[base] + 2)
	{
		auto hv = hval[t];
		for (int i = 0; i < NUM; i++)
		{
			hv[i] = (hv[i] + 1ull * power[i][depth[base] + 1] * (Q[i] + h - z)) % Q[i];
		}

		if (cnt.count(hv) == 1 || cnt2.insert(hv).second == false) total[depth[base] + 1]++;
	}
	for (int nxt : graph[t])
	{
		calc(base, nxt, h, z);
	}
}

void add(int t)
{
	cnt.insert(hval[t]);
	for (int nxt : graph[t]) add(nxt);
}

void dfs(int t, bool clear)
{
	int maxchild = 0, maxidx = 0;

	if (graph[t].empty())
	{
		if (clear == false) cnt.insert(hval[t]);
		return;
	}

	vector<pair<int, int>> childs;

	for (int e : graph[t])
	{
		childs.emplace_back(childcnt[e], e);
	}

	sort(childs.begin(), childs.end(), greater<>());

	for (int i = 1; i < childs.size(); i++)
	{
		dfs(childs[i].second, true);
	}

	dfs(childs[0].second, false);

	for (int i = 1; i < childs.size(); i++)
	{
		calc(t, childs[i].second, dat[childs[0].second], dat[childs[i].second]);
	}

	cnt2.clear();

	if (clear) cnt.clear();
	else
	{
		cnt.insert(hval[t]);
		for (int i = 1; i < childs.size(); i++)
		{
			add(childs[i].second);
		}
	}
}

using ll = long long;

// find a pair (c, d) s.t. ac + bd = gcd(a, b)
pair<ll, ll> extended_gcd(ll a, ll b) {
	if (b == 0) return{ 1, 0 };
	auto t = extended_gcd(b, a % b);
	return{ t.second, t.first - t.second * (a / b) };
}

// find x in [0,m) s.t. ax === gcd(a, m) (mod m)
ll modinverse(ll a, ll m) {
	return (extended_gcd(a, m).first % m + m) % m;
}

int main()
{
	for (int i = 0; i < NUM; i++)
	{
		power[i][0] = 1;
		for (int j = 1; j <= 300000; j++) power[i][j] = power[i][j - 1] * 1ull * P[i] % Q[i];
	}

	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b; char c;
		scanf("%d%d %c", &a, &b, &c);
		graph[a].push_back(b);
		dat[b] = c - 'a' + 1;
	}

	pdfs(1);
	dfs(1, true);

	int a1 = -1, a2 = 0;
	for (int i = 1; i <= 300000; i++) if (a1 < total[i]) a1 = total[i], a2 = i;
	printf("%d\n%d\n", n - a1, a2);
	fflush(stdout);
	_Exit(0);
}