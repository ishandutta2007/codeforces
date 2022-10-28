#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1e6;

int pref[MX], suf[MX + 2], last[MX + 1], first[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	fill(first + 1, first + 1 + x, n + 1);
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		first[a] = min(first[a], i);
		last[a] = max(last[a], i);
	}

	memset(pref, -1, sizeof pref);
	memset(suf, -1, sizeof suf);
	pref[0] = 0;
	for (int i = 1; i < x; ++i) {
		if (first[i] <= pref[i - 1]) break;
		pref[i] = max(pref[i - 1], last[i]);
	}
	suf[x + 1] = n + 1;
	for (int i = x; i; --i) {
		if (last[i] >= suf[i + 1]) break;
		suf[i] = min(suf[i + 1], first[i]);
	}

	ll ans = 0;
	for (int i = 1; i <= x; ++i) {
		if (pref[i - 1] == -1) break;
		int lo = i + 1, hi = x + 1;
		while (lo < hi) {
			int mi = (lo + hi) / 2;
			if (suf[mi] != -1 && suf[mi] > pref[i - 1]) {
				hi = mi;
			} else {
				lo = mi + 1;
			}
		}
		ans += x + 2 - lo;
	}
	cout << ans << '\n';
}