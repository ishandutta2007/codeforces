#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll k;
	cin >> n >> k;
	map<int, int> seq;
	while (n--) {
		int a;
		cin >> a;
		++seq[a];
	}

	while (seq.size() > 1) {
		if (seq.begin()->second <= prev(seq.end())->second) {
			auto u = seq.begin(), v = next(u);
			int ct = u->second;
			if (k >= ((ll)v->first - u->first) * ct) {
				k -= ((ll)v->first - u->first) * ct;
				seq.erase(u);
				v->second += ct;
			} else {
				cout << prev(seq.end())->first - u->first - k / ct << '\n';
				return 0;
			}
		} else {
			auto u = prev(seq.end()), v = prev(u);
			int ct = u->second; 
			if (k >= ((ll)u->first - v->first) * ct) {
				k -= ((ll)u->first - v->first) * ct;
				seq.erase(u);
				v->second += ct;
			} else {
				cout << u->first - seq.begin()->first - k / ct << '\n';
				return 0;
			}
		}
	}
	cout << 0 << '\n';
}