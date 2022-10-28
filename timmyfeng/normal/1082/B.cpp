#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> segg, segs;
	int cur = 0;
	while (cur < n) {
		int len = 0;
		while (cur < n && s[cur] == 'S') {
			++len;
			++cur;
		}
		segs.push_back(len);
		len = 0;
		while (cur < n && s[cur] == 'G') {
			++len;
			++cur;
		}
		segg.push_back(len);
	}

	int ans = *max_element(segg.begin(), segg.end());
	int cnt = count(s.begin(), s.end(), 'G');
	int m = segg.size();
	for (int i = 0; i < m; ++i) {
		int l = (i ? segg[i - 1] : 0);
		int r = segg[i];
		if (segs[i] == 1) {
			if (l + r == cnt) {
				ans = max(ans, l + r);
			} else {
				ans = max(ans, l + r + 1);
			}
		} else if (segs[i]) {
			if (max(l, r) != cnt) {
				ans = max(ans, max(l, r) + 1);
			}
		}
	}
	cout << ans << '\n';
}