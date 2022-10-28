#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5;
const int LOGN = 20;

pair<pair<int, int>, int> suf[MX];
int key[LOGN][MX], n, logn = 1;
vector<pair<int, int>> req;

int lcp(int a, int b) {
	int res = 0;
	if (a == b)
		return n - a;
	for (int i = logn - 1; i >= 0 && a < n && b < n; --i) {
		if (key[i][a] == key[i][b]) {
			res += 1 << i;
			a += 1 << i;
			b += 1 << i;
		}
	}
	return res;
}

ll calc() {
	map<int, int> mp;
	ll cur = 0, res = 0;
	int pre = -1;
	for (auto [i, tp] : req) {
		if (pre != -1) {
			int len = lcp(i, pre);
			int cnt = 0;
			while (!mp.empty() && mp.rbegin()->first > len) {
				auto [l, c] = *mp.rbegin();
				mp.erase(--mp.end());
				cur -= (ll)l * c;
				cnt += c;
			}
			if (len) {
				cur += (ll)len * cnt;
				mp[len] += cnt;
			}
		}

		if (tp) {
			res += cur;
		} else {
			++mp[n - i];
			cur += n - i;
		}
		pre = i;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	string s;
	cin >> n >> q >> s;
	
	for (int i = 0; i < n; ++i) {
		key[0][i] = s[i] - 'a';
	}
	for (int len = 1; len / 2 < n; ++logn, len *= 2) {
		for (int i = 0; i < n; ++i) {
			suf[i].first.first = key[logn - 1][i];
			suf[i].first.second = i + len < n ? key[logn - 1][i + len] : -1;
			suf[i].second = i;
		}
		sort(suf, suf + n, [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
			return a.first < b.first;
		});

		for (int i = 0; i < n; ++i) {
			if (i && suf[i].first == suf[i - 1].first) {
				key[logn][suf[i].second] = key[logn][suf[i - 1].second];
			} else {
				key[logn][suf[i].second] = i;
			}
		}
	}

	while (q--) {
		int k, l;
		cin >> k >> l;
		req.clear();
		for (int i = 0; i < k; ++i) {
			int a;
			cin >> a;
			req.emplace_back(a - 1, 0);
		}
		for (int i = 0; i < l; ++i) {
			int b;
			cin >> b;
			req.emplace_back(b - 1, 1);
		}

		sort(req.begin(), req.end(), [&](pair<int, int> a, pair<int, int> b) {
			return a.first == b.first ? a.second < b.second : key[logn - 1][a.first] < key[logn - 1][b.first];
		});
		ll ans = calc();
		reverse(req.begin(), req.end());
		ans += calc();
		cout << ans << '\n';
	}
}