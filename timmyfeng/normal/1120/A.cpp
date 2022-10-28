#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, k, n, s;
	cin >> m >> k >> n >> s;
	int len = m - k * (n - 1);

	vector<int> a(m);
	for (auto& i : a) {
		cin >> i;
	}

	int bad = 0;
	vector<int> cnt(5e5 + 1);
	for (int i = 0; i < s; ++i) {
		int b;
		cin >> b;
		bad += !cnt[b];
		++cnt[b];
	}

	bool ok = false;
	vector<int> ans;
	for (int i = 0; i < m; ++i) {
		--cnt[a[i]];
		bad -= !cnt[a[i]];

		int j = i - len + 1;
		if (j >= 0) {
			if (!bad && j % k == 0) {
				for (int l = j; len - int(ans.size()) > k; ++l) {
					if (cnt[a[l]] < 0) {
						ans.push_back(l);
						++cnt[a[l]];
					}
				}
				ok = true;
				break;
			}

			bad += !cnt[a[j]];
			++cnt[a[j]];
		}
	}

	if (!ok) {
		cout << -1 << "\n";
	} else {
		cout << ans.size() << "\n";
		for (auto i : ans) {
			cout << i + 1 << " ";
		}
	}
}