#include <iostream>

using namespace std;

const int INF = 3001;

int main() {
	string s;
	cin >> s;
	int n = s.size(), cnt, minimum, lst;
	char last;
	pair <int, int> dp[n + 1];
	dp[0] = make_pair(0, 0);
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		last = '[';
		minimum = INF;
		for (int j = i - 1; j >= 0; j--) {
			if (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u') {
				cnt++;
			} else {
				cnt = 0;
			}
			if (cnt >= 3 && !(s[j] == s[j + 1] && s[j + 1] == s[j + 2])) {
				break;
			}
			if (dp[j].first < minimum) {
				minimum = dp[j].first;
				lst = j - 1;
			}
		}
		dp[i] = make_pair(minimum + 1, lst);
		//cout << dp[i].first << ' ' << dp[i].second << endl;
	}
	string ans = "";
	int now = n;
	while (now != 0) {
		for (int i = now - 1; i > dp[now].second; i--) {
			ans += s[i];
			//cout << ans << endl;
		}
		ans += ' ';
		now = dp[now].second + 1;
	}
	for (int i = ans.length() - 2; i >= 0; i--) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}