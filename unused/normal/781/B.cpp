#include <bits/stdc++.h>
using namespace std;

map<string, int> sid;
pair<string, string> dat[1005];
pair<int, int> did[1005];

int idx(const string &str)
{
	return sid.emplace(str, sid.size()).first->second;
}

constexpr int MAXN = 2005;
vector<int> graph[MAXN];
int up[MAXN], visit[MAXN], vtime;
vector<int> stk;
int scc_idx[MAXN], scc_cnt;
void dfs(int nod) {
	up[nod] = visit[nod] = ++vtime;
	stk.push_back(nod);
	for (int next : graph[nod]) {
		if (visit[next] == 0) {
			dfs(next);
			up[nod] = min(up[nod], up[next]);
		}
		else if (scc_idx[next] == 0)
			up[nod] = min(up[nod], visit[next]);
	}
	if (up[nod] == visit[nod]) {
		++scc_cnt;
		int t;
		do {
			t = stk.back();
			stk.pop_back();
			scc_idx[t] = scc_cnt;
		} while (!stk.empty() && t != nod);
	}
}
// find SCCs in given directed graph
// O(V+E)
int nn;
void get_scc() {
	vtime = 0;
	memset(visit, 0, sizeof(visit));
	scc_cnt = 0;
	memset(scc_idx, 0, sizeof(scc_idx));
	for (int i = 0; i < nn; ++i)
		if (visit[i] == 0) dfs(i);
}

int main()
{
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> dat[i].first >> dat[i].second;
		string z1{ dat[i].first[0], dat[i].first[1], dat[i].first[2] };
		string z2{ dat[i].first[0], dat[i].first[1], dat[i].second[0] };

		did[i].first = idx(z1);
		did[i].second = idx(z2);
	}

	nn = n * 2;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (did[i].first == did[j].first)
			{
				graph[i].push_back(j + n);
				graph[j].push_back(i + n);
				graph[i + n].push_back(j + n);
				graph[j + n].push_back(i + n);
			}

			if (did[i].first == did[j].second)
			{
				graph[i].push_back(j);
				graph[j + n].push_back(i + n);
			}

			if (did[i].second == did[j].first)
			{
				graph[j].push_back(i);
				graph[i + n].push_back(j + n);
			}

			if (did[i].second == did[j].second)
			{
				graph[i + n].push_back(j);
				graph[j + n].push_back(i);
			}
		}
	}

	get_scc();

	for (int i = 0; i < n; i++)
	{
		if (scc_idx[i] == scc_idx[i + n])
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");

	for (int i = 0; i < n; i++)
	{
		string z1{ dat[i].first[0], dat[i].first[1], dat[i].first[2] };
		string z2{ dat[i].first[0], dat[i].first[1], dat[i].second[0] };

		if (scc_idx[i] < scc_idx[i + n])
		{
			printf("%s\n", z1.c_str());
		}
		else
		{
			printf("%s\n", z2.c_str());
		}
	}
}