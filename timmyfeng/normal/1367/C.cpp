#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;

		vector<int> nxt(n + 1);
		nxt[n] = n + k;
		for (int i = n - 1; i >= 0; --i) {
			nxt[i] = s[i] == '1' ? i : nxt[i + 1];
		}

		int pre = -k - 1;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (i - pre > k && nxt[i] - i > k) {
				++ans;
				pre = i;
			} else if (s[i] == '1') {
				pre = i;
			}
		}
		cout << ans << "\n";
	}
}