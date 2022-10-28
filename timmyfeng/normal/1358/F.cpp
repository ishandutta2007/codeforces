#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

bool unequal(vector<ll>& a, vector<ll>& b) {
	if (a == b)
		return false;
	bool res = false;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		res |= (a[i] != b[n - 1 - i]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : b) {
		cin >> i;
	}

	if (n == 1) {
		if (a[0] == b[0]) {
			cout << "SMALL" << '\n';
			cout << 0 << '\n';
			cout << '\n';
		} else {
			cout << "IMPOSSIBLE" << '\n';
		}
	} else if (n == 2) {
		vector<ll> ans;
		ll cnt_a = 0, cnt_b = 0;
		while (unequal(a, b)) {
			if (b[0] > b[1]) {
				swap(b[0], b[1]);
				ans.push_back(-1);
				++cnt_a;
			}
			
			if (b[0] == b[1] || !b[0]) {
				cout << "IMPOSSIBLE" << '\n';
				return 0;
			}

			if (b[0] == min(a[0], a[1])) {
				ll diff = b[1] - max(a[0], a[1]);
				if (diff < 0 || diff % b[0]) {
					cout << "IMPOSSIBLE" << '\n';
					return 0;
				}
				ans.push_back(diff / b[0]);
				cnt_b += diff / b[0];
				b[1] = max(a[0], a[1]);
			} else {
				ans.push_back(b[1] / b[0]);
				cnt_b += b[1] / b[0];
				b[1] %= b[0];
			}
		}

		if (b[1] != a[1]) {
			ans.push_back(-1);
			++cnt_a;
		}
		reverse(ans.begin(), ans.end());

		if (cnt_b <= 2e5) {
			cout << "SMALL" << '\n';
			cout << cnt_a + cnt_b << '\n';
			for (auto i : ans) {
				if (i == -1) {
					cout << "R";
				} else {
					cout << string(i, 'P');
				}
			}
			cout << '\n';
		} else {
			cout << "BIG" << '\n';
			cout << cnt_b << '\n';
		}
	} else {
		string ans = "";
		ll cnt_a = 0, cnt_b = 0;
		while (unequal(a, b)) {
			bool orient = (b[0] < b[1]);
			for (int i = 2; i < n; ++i) {
				if ((b[i - 1] < b[i]) != orient) {
					cout << "IMPOSSIBLE" << '\n';
					return 0;
				}
			}

			if (!orient) {
				reverse(b.begin(), b.end());
				ans += "R";
				++cnt_a;
			}

			for (int i = n - 1; i; --i) {
				b[i] -= b[i - 1];
			}
			ans += "P";
			++cnt_b;
		}

		if (a != b) {
			ans += "R";
			++cnt_a;
		}
		reverse(ans.begin(), ans.end());

		if (cnt_b > 2e5) {
			cout << "BIG" << '\n';
			cout << cnt_b << '\n';
		} else {
			cout << "SMALL" << '\n';
			cout << ans.size() << '\n';
			cout << ans << '\n';
		}
	}
}