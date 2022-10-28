#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5;
const int AL = 17;

bitset<1 << AL> ok, dp, tmp;
int cnt[AL], p;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> p >> s;
	ok.flip();
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j < p; ++j) {
			int a;
			cin >> a;
			if (a)
				continue;
			tmp.reset();
			tmp.flip();
			int ma = 0;
			bool prev = false;
			for (int k = 0; k < n; ++k) {
				int c = s[k] - 'a';
				if (c == j && prev) {
					tmp[((1 << p) - 1) ^ ma] = false;
					prev = false;
				}
				if (c == i) {
					ma = 0;
					prev = true;
				}
				if (c != j && c != i) {
					ma |= 1 << c;
				}
			}
			for (ma = (1 << p) - 1; ma >= 0; --ma) {
				if (tmp[ma])
					continue;
				for (int k = 0; k < p; ++k) {
					if (k != i && k != j && (ma & (1 << k))) {
						tmp[ma ^ (1 << k)] = false;
					}
				}
			}
			ok &= tmp;
		}
	}
	for (auto c : s) {
		++cnt[c - 'a'];
	}
	
	int ans = n;
	dp[(1 << p) - 1] = true;
	for (int ma = (1 << p) - 2; ma >= 0; --ma) {
		if (!ok[ma])
			continue;
		int res = 0;
		for (int i = 0; i < p; ++i) {
			if (ma & (1 << i)) {
				res += cnt[i];
			} else if (dp[ma ^ (1 << i)]) {
				dp[ma] = true;
			}
		}
		if (dp[ma]) {
			ans = min(ans, res);
		}
	}
	cout << ans << '\n';
}