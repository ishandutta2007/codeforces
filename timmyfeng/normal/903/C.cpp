#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	map<int, int> mp;
	while (n--) {
		int a;
		cin >> a;
		++mp[a];
	}

	int ans = 0;
	for (auto& i : mp) {
		ans = max(ans, i.second);
	}
	cout << ans << '\n';
}