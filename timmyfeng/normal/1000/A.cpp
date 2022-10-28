#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	map<string, int> mp;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		++mp[s];
	}
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		--mp[s];
	}

	int ans = 0;
	for (auto i : mp) {
		if (i.second > 0) {
			ans += i.second;
		}
	}
	cout << ans << '\n';
}