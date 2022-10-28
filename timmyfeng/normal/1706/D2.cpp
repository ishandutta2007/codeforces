#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int n, k; cin >> n >> k;

		vector<int> a(n);
		for (auto &i : a) cin >> i;

		vector pos(1e5 + 1, vector<int>());

		int max_ap = 0, min_a = INT_MAX;
		for (auto i : a) {
			pos[i / k].push_back(i);
			max_ap = max(max_ap, i / k);
			min_a = min(min_a, i);
		}

		int answer = INT_MAX;
		for (int i = 0; i < min_a; ++i) {
			answer = min(answer, max_ap - i);
			for (auto j : pos[i]) {
				int j_nxt = j / (j / (i + 1));
				pos[j_nxt].push_back(j);
				max_ap = max(max_ap, j_nxt);
			}
			vector<int>().swap(pos[i]);
		}
		answer = min(answer, max_ap - min_a);

		vector<vector<int>>().swap(pos);
		vector<int>().swap(a);

		cout << answer << "\n";
	}
}