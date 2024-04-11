#include <iostream>

using namespace std;

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	int right[n];
	for (int i = 0; i < n; i++) {
		right[i] = n;
		for (int len = 1; len < 100; len++) {
			if (i + 2 * len >= n) continue;
			if (s[i] == s[i + len] && s[i + len] == s[i + 2 * len]) {
				right[i] = i + 2 * len;
				break;
			}
		}
	}
	int cur = right[n - 1];
	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		cur = min(cur, right[i]);
		ans += n - cur;
	}
	cout << ans << endl;
	return 0;
}