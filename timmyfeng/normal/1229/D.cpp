#include <bits/stdc++.h> 
using namespace std;

const int MXF = 120;
const int MX = 2e5;

vector<int> perm[MXF];
int mul[MXF][MXF];
bool vstd[MXF];
int p[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int fact = 0;
	vector<int> cur(k);
	map<vector<int>, int> mp;
	iota(cur.begin(), cur.end(), 0);
	do {
		perm[fact] = cur;
		mp[cur] = fact++;
	} while (next_permutation(cur.begin(), cur.end()));

	for (int i = 0; i < fact; ++i) {
		for (int j = 0; j < fact; ++j) {
			vector<int> a = perm[i];
			vector<int> b = perm[j];
			vector<int> c;
			for (int l = 0; l < k; ++l) {
				c.push_back(a[b[l]]);
			}
			mul[i][j] = mp[c];
		}
	}

	for (int i = 0; i < n; ++i) {
		vector<int> a(k);
		for (auto& j : a) {
			cin >> j;
			--j;
		}
		p[i] = mp[a];
	}

	long long ans = 0;
	vector<pair<int, int>> chain;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < int(chain.size()); ++j) {
			if (chain[j].first == p[i]) {
				chain.erase(chain.begin() + j);
				break;
			}
		}
		chain.emplace_back(p[i], i);

		memset(vstd, false, sizeof vstd);
		vstd[0] = true;

		vector<int> cnt = {1};
		vector<int> pre = {i};
		vector<int> trans;
		for (int j = int(chain.size()) - 1; j >= 0; --j) {
			auto [x, t] = chain[j];
			if (vstd[x])
				continue;

			cnt.push_back(cnt.empty() ? 1 : cnt.back());
			trans.push_back(x);
			pre.push_back(t);

			queue<int> que;
			for (int l = 0; l < fact; ++l) {
				if (vstd[l]) {
					que.push(l);
				}
			}

			while (!que.empty()) {
				int u = que.front();
				que.pop();
				for (auto e : trans) {
					int v = mul[u][e];
					if (!vstd[v]) {
						vstd[v] = true;
						++cnt.back();
						que.push(v);
					}
				}
			}
		}

		pre.push_back(-1);
		for (int j = 0; j < int(cnt.size()); ++j) {
			ans += 1LL * cnt[j] * (pre[j] - pre[j + 1]);
		}
	}
	cout << ans << "\n";
}