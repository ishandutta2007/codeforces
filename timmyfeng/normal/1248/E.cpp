#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1e5;

ll ans[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll p;
	cin >> n >> p;
	set<tuple<ll, int, int>> eve;
	for (int i = 0; i < n; ++i ){
		ll t;
		cin >> t;
		eve.emplace(t, 0, i);
	}

	set<int> out, wq;
	queue<int> qq;
	int cur = -1;
	while (!eve.empty()) {
		ll t;
		int k, e;
		tie(t, k, e) = *eve.begin();
		eve.erase(eve.begin());
		if (k) {
			ans[cur] = t;
			out.erase(cur);
			if (!wq.empty() && (out.empty() || *out.begin() > *wq.begin())) {
				out.insert(*wq.begin());
				qq.push(*wq.begin());
				wq.erase(wq.begin());
			}
			if (qq.empty()) {
				cur = -1;
			} else {
				cur = qq.front();
				qq.pop();
				eve.emplace(t + p, 1, cur);
			}
		} else {
			if (out.empty() || *out.begin() > e) {
				if (~cur) {
					qq.push(e);
				} else {
					cur = e;
					eve.emplace(t + p, 1, cur);
				}
				out.insert(e);
			} else {
				wq.insert(e);
			}
		}
	}

	for (int i = 0; i < n; ++i ){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}