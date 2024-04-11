#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		for (int i = 0; i < m; i++) {
			a[i] = max(a[i], a[i + n - m]);
		}
		a.resize(m);
		int sz = max(m - k, 1);
		int sol = 0;
		deque<int> md;
		for (int i = 0, j = 0; i + sz - 1 < m; i++) {
			while (md.size() && md.front() < i) {
				md.pop_front();
			}
			while (j < i + sz) {
				while (md.size() && a[md.back()] >= a[j]) {
					md.pop_back();
				}
				md.push_back(j++);
			}
			sol = max(sol, a[md.front()]);
		}
		cout << sol << "\n";
	}
}