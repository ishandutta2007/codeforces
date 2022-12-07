#include <bits/stdc++.h>

using namespace std;

int t, n, k;
string s;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		vector<int> v;
		for (int i = 0; i < n; i++)
			if (s[i] == '*')
				v.push_back(i);
		if (v.size() == 1) {
			cout << 1 << "\n";
			continue;
		}
		int ans = 1, i = 0;
		while (i + 1 < v.size()) {
			int j = i;
			while (j + 1 < v.size() && v[j + 1] - v[i] <= k)
				j++;
			ans++;
			i = j;
		}
		cout << ans << "\n";
	}
}