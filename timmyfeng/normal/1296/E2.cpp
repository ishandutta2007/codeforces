#include <bits/stdc++.h>
using namespace std;

int color[26];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		int mx = 0;
		for (int j = s[i] - 'a' + 1; j < 26; ++j) {
			mx = max(mx, color[j]);
		}
		ans[i] = mx + 1;
		color[s[i] - 'a'] = ans[i];
	}
	cout << *max_element(color, color + 26) << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}