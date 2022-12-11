#include <iostream>
#include <vector>

using namespace std;

int main() {
	int k, n;
	string s;
	cin >> n >> k;
	cin >> s;
	vector <int> has[256];
	int now_ch = s[0], now_cnt = 1;
	for (int i = 1; i < n; i++) {
		if (now_ch == s[i]) {
			now_cnt++;
			continue;
		} else {
			has[now_ch].push_back(now_cnt);
			now_cnt = 1;
			now_ch = s[i];
		}
	}
	has[now_ch].push_back(now_cnt);
	int ans = 0;
	for (int i = 'a'; i <= 'z'; i++) {
		int summ = 0;
		for (int elem : has[i]) {
			summ += elem / k;
		}
		ans = max(ans, summ);
	}
	cout << ans << endl;
	return 0;
}