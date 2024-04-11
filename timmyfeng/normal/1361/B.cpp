#include <bits/stdc++.h> 
using namespace std;

const int M = 1e9 + 7;

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + M : a;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int mod_pow(int b, int e) {
	int res = 1;
	while (e) {
		if (e % 2) {
			res = mul(res, b);
		}
		b = mul(b, b);
		e /= 2;
	}
	return res;
}

void solve() {
	int n, p;
	cin >> n >> p;
	vector<int> k(n);
	for (auto& i : k) {
		cin >> i;
	}
	sort(k.begin(), k.end(), greater<int>());

	if (p == 1) {
		cout << n % 2 << '\n';
		return;
	}

	vector<map<int, int>> cnt(2);
	cnt[0][-1] = 1;
	cnt[1][-1] = 2;
	int l = 0;
	int pre = -1;
	for (auto i : k) {
		++cnt[l][i];
		while (cnt[l][i] == p) {
			cnt[l].erase(i);
			++cnt[l][++i];
		}

		if (i >= pre) {
			pre = i;
			auto it1 = cnt[l].lower_bound(pre);
			auto it2 = cnt[l ^ 1].lower_bound(pre);
			while (pre >= 0 && it1 != cnt[l].end() && it2 != cnt[l ^ 1].end() && *it1 == *it2) {
				--it1;
				--it2;
				pre = max(it1->first, it2->first);
			}
			if (cnt[l].count(pre) && (!cnt[l ^ 1].count(pre) || cnt[l][pre] > cnt[l ^ 1][pre])) {
				l ^= 1;
			}
		}
	}

	int ans = 0;
	for (auto i : cnt[l]) {
		if (i.first == -1)
			continue;
		ans = sub(ans, mul(i.second, mod_pow(p, i.first)));
	}
	for (auto i : cnt[l ^ 1]) {
		if (i.first == -1)
			continue;
		ans = add(ans, mul(i.second, mod_pow(p, i.first)));
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}