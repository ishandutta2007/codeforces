#include <iostream>
#include <cmath>

using namespace std;


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	int len[n];
	int last = -1, maxi = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'G') {
			cnt++;
			if (last == -1) last = i;
		} else {
			len[i] = 0;
			if (last != -1) {
				maxi = max(maxi, i - last);
				for (int j = last; j < i; j++) len[j] = i - last;
			}
			last = -1;
		}
	}
	if (last != -1) {
		maxi = max(maxi, n - last);
		for (int j = last; j < n; j++) len[j] = n - last;
	}
	int ans = maxi;
	if (cnt > maxi) ans++;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'S' && i > 0 && i < n - 1) {
			ans = max(ans, len[i - 1] + len[i + 1] + 1);
		}
	}
	ans = min(cnt, ans);
	cout << ans << endl;
	return 0;
}