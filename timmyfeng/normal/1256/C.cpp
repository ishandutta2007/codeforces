#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> c(m);
	int sum = 0;
	for (auto& i : c) {
		cin >> i;
		sum += i;
	}

	vector<int> ans(n);
	int prev = 0;
	for (int i = 0; i < m; ++i) {
		int cur = prev + 1;
		while (prev + d >= cur + 1 && cur + sum <= n) {
			++cur;
		}
		for (int j = cur; j < cur + c[i]; ++j) {
			ans[j - 1] = i + 1;
		}
		prev = cur + c[i] - 1;
		sum -= c[i];
	}
	
	if (n + 1 - prev > d) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}