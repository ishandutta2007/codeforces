#include <bits/stdc++.h>
using namespace std;

vector<int> dat[1000005];

constexpr int P1 = 1000003, P2 = 1000000007;
constexpr int P3 = 1000033, P4 = 1000000009;

map<vector<int>, int> cnt;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int idx = 1;
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		unordered_map<int, int> mp;
		for (int j = 0; j < k; j++)
		{
			int t;
			scanf("%d", &t);
			mp[t]++;
		}
		unordered_map<int, vector<int>> mp2;
		for (auto &&e : mp)
		{
			mp2[e.second].push_back(e.first);
		}

		for (auto &&e : mp2)
		{
			for (int j : e.second)
			{
				dat[j].push_back(idx);
			}
			idx++;
		}
	}

	for (int i = 1; i <= m; i++) cnt[dat[i]]++;

	int ans = 1;

	for (auto &&e : cnt)
	{
		for (int j = 2; j <= e.second; j++) ans = ans * 1ll * j % P2;
	}

	printf("%d\n", ans);

	fflush(stdout);
	_Exit(0);
}