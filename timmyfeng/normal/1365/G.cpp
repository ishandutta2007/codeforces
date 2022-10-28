#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

const int MX = 1000;
const int MXQ = 13;

vector<int> qry[MXQ];
int qry_mask[MX];
ll res[MXQ];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cur = 0;
	for (int mask = 0; mask < (1 << MXQ) && cur < n; ++mask) {
		if (__builtin_popcount(mask) != 6)
			continue;
		qry_mask[cur++] = mask;
		for (int i = 0; i < MXQ; ++i) {
			if (mask & (1 << i)) {
				qry[i].push_back(cur);
			}
		}
	}

	for (int i = 0; i < MXQ; ++i) {
		if (qry[i].empty())
			continue;
		cout << "? " << qry[i].size();
		for (auto j : qry[i]) {
			cout << ' ' << j;
		}
		cout << endl;
		cin >> res[i];
	}

	cout << '!';
	for (int i = 0; i < n; ++i) {
		ll ans = 0;
		for (int j = 0; j < MXQ; ++j) {
			if (!(qry_mask[i] & (1 << j))) {
				ans |= res[j];
			}
		}
		cout << ' ' << ans;
	}
	cout << endl;
}