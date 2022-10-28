#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5;
int freq[MX / 2][26];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		for (int i = 0; i < (k + 1) / 2; ++i) {
			for (auto& j : freq[i]) {
				j = 0;
			}
			for (int j = 0; j < n; j += k) {
				++freq[i][s[j + i] - 'a'];
				++freq[i][s[j + k - 1 - i] - 'a'];
			}
		}
		if (k % 2) {
			for (auto& i : freq[k / 2]) {
				i /= 2;
			}
		}
		int ans = 0;
		for (int i = 0; i < (k + 1) / 2; ++i) {
			int mx = *max_element(freq[i], freq[i] + 26);
			ans += n / k * 2 - mx;
		}
		if (k % 2) {
			ans -= n / k;
		}
		cout << ans << '\n';
	}
}