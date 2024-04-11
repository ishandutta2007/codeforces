#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5;
const int INF = 1e9;
const int MXA = 30;

int res[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	for (int i = 1; i <= MXA; ++i) {
		ll mn = 0, sum = 0;
		for (int j = 1; j <= n; ++j) {
			sum += (a[j - 1] > i ? -INF : a[j - 1]);
			mn = min(mn, sum);
			if (a[j - 1] == i) {
				res[j - 1] += sum - mn - i;
			}
		}
		mn = 0;
		sum = 0;
		for (int j = n - 1; j >= 0; --j) {
			sum += (a[j] > i ? -INF : a[j]);
			mn = min(mn, sum);
			if (a[j] == i) {
				res[j] += sum - mn - i;
			}
		}
	}
	cout << *max_element(res, res + n) << '\n';
}