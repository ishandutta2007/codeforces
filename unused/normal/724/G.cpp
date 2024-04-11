#include "bits/stdc++.h"
using namespace std;

using ll = long long;

constexpr int MAXN = 100005;
constexpr int MOD = 1000000007;

vector<pair<int, ll>> graph[100005];
vector<int> vertices;
int par[MAXN], cyclecnt;
bool visit[MAXN];
ll path[MAXN], cycles[60], used;
int bitcnt[MAXN][60][2];
int p2mod[61];
int ans;

void dfs(int nod) {
	visit[nod] = true;
	for (auto &next : graph[nod]) {
		if (visit[next.first]) continue;
		par[next.first] = nod;
		path[next.first] = path[nod] ^ next.second;
		vertices.push_back(next.first);
		dfs(next.first);
	}
}

void dfs2(int nod)
{
	for (auto &next : graph[nod])
	{
		if (par[next.first] != nod) continue;
		dfs2(next.first);
		for (int flag = 0; flag < 60; flag++)
		{
			if (used & (1ll << flag)) continue;
			bool flip = next.second & (1ll << flag);
			bitcnt[nod][flag][0] += bitcnt[next.first][flag][flip];
			bitcnt[nod][flag][1] += bitcnt[next.first][flag][!flip];
		}
	}

	int mul = p2mod[cyclecnt];

	int adde = 0;
	
	for (auto &next : graph[nod])
	{
		if (par[next.first] != nod) continue;

		for (int flag = 0; flag < 60; flag++)
		{
			if (used & (1ll << flag)) continue;

			bool flip = next.second & (1ll << flag);

			int a0 = bitcnt[nod][flag][0], a1 = bitcnt[nod][flag][1];
			int b0 = bitcnt[next.first][flag][flip], b1 = bitcnt[next.first][flag][!flip];
			int bmod = p2mod[flag];

			adde = (adde + bmod * ((ll)(a0 - b0) * b1 % MOD)) % MOD;
			adde = (adde + bmod * ((ll)(a1 - b1) * b0 % MOD)) % MOD;
		}
	}

	ans = (ans + (ll)adde * 500000004 % MOD * mul) % MOD;

	for (int flag = 0; flag < 60; flag++)
	{
		if (used & (1ll << flag)) continue;
		bitcnt[nod][flag][0]++;
		ans = (ans + (ll)p2mod[flag] * bitcnt[nod][flag][1] % MOD * mul) % MOD;
	}
}

void process(int root)
{
	vertices.clear();

	cyclecnt = 0;
	memset(cycles, 0, sizeof(cycles));
	used = 0;
	path[root] = 0;
	vertices.push_back(root);
	dfs(root);

	for (int idx = 0; idx < vertices.size() && cyclecnt < 60; idx++)
	{
		int i = vertices[idx];
		for (auto &&edge : graph[i])
		{
			if (par[i] == edge.first || par[edge.first] == i) continue;
			ll cycle = path[i] ^ path[edge.first] ^ edge.second;

			int flag = 0;

			while (cycle && flag < 60)
			{
				if (cycle & (1LL << flag))
				{
					if (cycles[flag])
					{
						cycle ^= cycles[flag];
					}
					else
					{
						cycles[flag] = cycle;
						used |= cycle;
						cyclecnt++;
						break;
					}
				}

				flag++;
			}

			if (cyclecnt == 60) break;
		}
	}

	if (used) ans = (ans + (ll)vertices.size() * (vertices.size() - 1) / 2 % MOD * (used % MOD) % MOD * p2mod[cyclecnt - 1]) % MOD;

	dfs2(root);
}

int main()
{
	memset(par, -1, sizeof(par));

	p2mod[0] = 1;
	for (int i = 1; i <= 60; i++) p2mod[i] = p2mod[i - 1] * 2 % MOD;

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b; ll c;
		scanf("%d%d%lld", &a, &b, &c);
		a--;b--;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	for (int i = 0; i < n; i++)
	{
		if (visit[i] == false)
		{
			process(i);
		}
	}

	printf("%d", ans);
}