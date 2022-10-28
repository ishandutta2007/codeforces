#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

vector<pair<ll, int>> pf;
vector<ll> pf_phi;
ll cur = 1, ans, x;

ll mul(ll a, ll b, ll m) {
	ll base = 1;
	while (base * 10 <= b) {
		base *= 10;
	}

	ll res = 0;
	while (base) {
		res = (res * 10 + (a * (b / base))) % m;
		b %= base;
		base /= 10;
	}
	return res;
}

ll mod_pow(ll b, ll e, ll m) {
	if (!e)
		return 1;
	if (e % 2) 
		return mul(b, mod_pow(b, e - 1, m), m);
	ll tmp = mod_pow(b, e / 2, m);
	return mul(tmp, tmp, m);
}

void dfs(int i) {
	if (i == (int)pf.size()) {
		ll phi = 1;
		for (auto j : pf_phi) {
			phi *= j;
		}

		ll ord = phi;
		for (auto j : pf_phi) {
			if (mod_pow(x, ord / j, cur) == 1) {
				ord /= j;
			}
		}

		ans += phi / ord;
	} else {
		dfs(i + 1);

		int pre_phi = pf_phi.size();
		ll k = pf[i].first - 1;
		for (ll j = 2; j * j <= k; ++j) {
			while (k % j == 0) {
				k /= j;
				pf_phi.push_back(j);
			}
		}
		if (k > 1) {
			pf_phi.push_back(k);
		}

		ll pre_factor = cur;
		for (int j = 1; j <= pf[i].second; ++j) {
			cur *= pf[i].first;
			dfs(i + 1);
			pf_phi.push_back(pf[i].first);
		}

		cur = pre_factor;
		while ((int)pf_phi.size() > pre_phi) {
			pf_phi.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll m;
	cin >> m >> x;

	for (ll i = 2; i * i <= m; ++i) {
		if (m % i)
			continue;
		int cnt = 0;
		while (m % i == 0) {
			m /= i;
			++cnt;
		}
		pf.emplace_back(i, cnt);
	}
	if (m > 1) {
		pf.emplace_back(m, 1);
	}

	dfs(0);

	cout << ans << '\n';
}