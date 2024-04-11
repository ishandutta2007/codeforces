#include <bits/stdc++.h> 
using namespace std;

const int MX = 3e5;
const int INF = 1e9;

int dsu[MX], path[MX], val[MX][2];
vector<int> cnt[MX];

array<int, 2> find(int a) {
	if (dsu[a] < 0)
		return {a, 0};
	auto tmp = find(dsu[a]);
	dsu[a] = tmp[0];
	path[a] ^= tmp[1];
	return {dsu[a], path[a]};
}

int get_cnt(int a) {
	return min(val[a][0], val[a][1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i < k; ++i) {
		int c;
		cin >> c;
		while (c--) {
			int a;
			cin >> a;
			cnt[a - 1].push_back(i);
		}

		dsu[i] = -1;
		val[i][0] = 1;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int type = (s[i] == '0');

		if (cnt[i].size() == 1u) {
			auto a = find(cnt[i][0]);
			ans -= get_cnt(a[0]);
			val[a[0]][a[1] ^ type] = INF;
			ans += get_cnt(a[0]);
		} else if (cnt[i].size() == 2u) {
			auto a = find(cnt[i][0]);
			auto b = find(cnt[i][1]);

			if (a[0] != b[0]) {
				ans -= get_cnt(a[0]);
				ans -= get_cnt(b[0]);

				if (dsu[a[0]] < dsu[b[0]]) {
					swap(a, b);
				}

				if (a[1] ^ b[1] ^ type) {
					swap(val[a[0]][0], val[a[0]][1]);
					path[a[0]] = 1;
				}

				dsu[b[0]] += dsu[a[0]];
				dsu[a[0]] = b[0];
				for (int i = 0; i < 2; ++i) {
					val[b[0]][i] = min(INF, val[a[0]][i] + val[b[0]][i]);
				}

				ans += get_cnt(b[0]);
			}
		}
		cout << ans << '\n';
	}
}