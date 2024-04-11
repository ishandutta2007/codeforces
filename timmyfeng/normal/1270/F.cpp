#include <bits/stdc++.h> 
using namespace std;

const int MAG = 500;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();

	long long ans = 0;
	vector<int> cnt((MAG + 2) * n);
	for (int i = 0; i < MAG; ++i) {
		int sum = n;
		for (int j = 0; j < n; ++j) {
			++cnt[sum];
			sum += s[j] == '1' ? i : -1;
			ans += cnt[sum];
		}

		for (int j = n - 1; j >= 0; --j) {
			sum -= s[j] == '1' ? i : -1;
			--cnt[sum];
		}
	}

	vector<int> pos;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			pos.push_back(i);
		}
	}
	pos.push_back(n);

	for (int i = 1; i * MAG < n && i < int(pos.size()); ++i) {
		for (int j = 0, k = 0; pos[k + i - 1] < n; ++j) {
			ans += max(MAG, (pos[k + i] - j) / i) - 
					max(MAG, (pos[k + i - 1] - j) / i);
			k += j == pos[k];
		}
	}
	cout << ans << "\n";
}