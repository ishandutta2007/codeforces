#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++mp[a];
	}

	int m = mp.size();
	vector<pair<int, int>> freq;
	for (auto i : mp) {
		freq.emplace_back(i.second, i.first);
	}
	sort(freq.rbegin(), freq.rend());

	int cur = m;
	int sum = 0;
	int rows = 0;
	int cols = 0;
	for (int i = 1; i <= m; ++i) {
		while (cur && freq[cur - 1].first < i) {
			sum += freq[cur - 1].first;
			--cur;
		}

		int res = sum / i + cur;
		if (res >= i && res * i > rows * cols) {
			cols = res;
			rows = i;
		}
	}

	int r = 0;
	int c = 0;
	vector<vector<int>> grid(rows, vector<int>(cols));
	for (auto [cnt, a] : freq) {
		for (int i = 0; i < min(rows, cnt); ++i) {
			grid[r][(r + c) % cols] = a;
			if (++r == rows) {
				r = 0;
				if (++c == cols) {
					goto done;
				}
			}
		}
	} done:

	cout << rows * cols << "\n";
	cout << rows << " " << cols << "\n";
	for (auto& i : grid) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
}