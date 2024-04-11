#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MXT = 1e5;
const int LOGN = 61;
const ll INF = 1e18;

ll ans[MXT], mu[LOGN], cur[LOGN];
pair<ll, int> n[MXT];
bool sieve[LOGN];

ll mul(ll a, ll b) {
	return a <= INF / b ? a * b : INF + 1;
}

void init() {
	vector<int> prime;
	mu[1] = 1;
	for (int i = 2; i < LOGN; ++i) {
		if (!sieve[i]) {
			prime.push_back(i);
			mu[i] = -1;
		}
		for (int j = 0; j < (int)prime.size() && i * prime[j] < LOGN; ++j) {
			sieve[i * prime[j]] = true;
			if (i % prime[j]) {
				mu[i * prime[j]] = -mu[i];
			} else {
				mu[i * prime[j]] = 0;
				break;
			}
		}

	}
}

ll calc(ll n) {
	ll lb = 1, rb = 1e9;
	while (lb < rb) {
		ll mb = (lb + rb + 1) / 2;
		if (mb * mb > n) {
			rb = mb - 1;
		} else {
			lb = mb;
		}
	}
	return lb;
}

ll binpow(ll b, int e) {
	if (!e)
		return 1;
	if (e % 2)
		return mul(b, binpow(b, e - 1));
	ll tmp = binpow(b, e / 2);
	return mul(tmp, tmp);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n[i].first;
		n[i].second = i;
	}
	sort(n, n + t);

	for (int i = 0; i < t; ++i) {
		ll u = n[i].first;
		ll res = (u - 1) * mu[1] + (calc(u) - 1) * mu[2];
		for (int j = 3; j < LOGN; ++j) {
			while (binpow(cur[j] + 1, j) <= u) {
				++cur[j];
			}
			res += (cur[j] - 1) * mu[j];
		}
		ans[n[i].second] = res;
	}

	for (int i = 0; i < t; ++i) {
		cout << ans[i] << '\n';
	}
}