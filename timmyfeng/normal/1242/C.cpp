#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MX = 15;

vector<ll> cyc[1 << MX];
pair<ll, ll> ans[MX];
ll dp[1 << MX];
ll sum[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll k;
	cin >> k;
	ll tot = 0;
	map<ll, ll> box;
	for (ll i = 0; i < k; ++i) {
		ll n;
		cin >> n;
		while (n--) {
			ll a;
			cin >> a;
			box[a] = i;
			sum[i] += a;
		}
		tot += sum[i];
	}

	if (tot % k) {
		cout << "No\n";
		return 0;
	}
	ll tgt = tot / k;

	for (auto [a, b] : box) {
		ll mask = 0;
		ll cur = a;

		vector<ll> path;
		while (box.count(cur) && !(mask & (1 << box[cur]))) {
			path.push_back(cur);
			mask |= 1 << box[cur];
			cur += tgt - sum[box[cur]];
		}

		if (cur == a) {
			cyc[mask] = path;
		}
	}

	dp[0] = -1;
	for (ll mask = 1; mask < (1 << k); ++mask) {
		for (ll add = mask; add; add = mask & (add - 1)) {
			if (!cyc[add].empty() && dp[mask ^ add]) {
				dp[mask] = add;
				break;
			}
		}
	}

	if (!dp[(1 << k) - 1]) {
		cout << "No\n";
		return 0;
	}

	ll cur = (1 << k) - 1;
	while (cur) {
		vector<ll> path = cyc[dp[cur]];
		ll len = path.size();
		for (ll i = 0; i < len; ++i) {
			ans[box[path[(i + 1) % len]]] = {path[(i + 1) % len], box[path[i]]};
		}
		cur ^= dp[cur];
	}

	cout << "Yes\n";
	for (ll i = 0; i < k; ++i) {
		cout << ans[i].first << " " << ans[i].second + 1 << "\n";
	}
}