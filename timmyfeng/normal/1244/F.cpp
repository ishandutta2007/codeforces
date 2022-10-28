#include <bits/stdc++.h>
using namespace std;
#define inc(x) (((x) + 1) % n)
#define dec(x) (((x) - 1 + n) % n)

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int rt = 0;
	for ( ; (s[rt] == s[dec(rt)] || s[rt] != s[inc(rt)]) && rt < n; ++rt);
	if (rt == n) {
		if (k % 2 && s.front() != s.back()) {
			for (auto& i : s) {
				i = 'W' + 'B' - i;
			}
		}
		cout << s << '\n';
		return 0;
	}

	int lo = 0, hi = 0, i = rt;
	do {
		i = inc(i);
		for ( ; s[i] == s[inc(i)]; i = inc(i));
		lo = i;
		for ( ; s[i] != s[inc(i)]; i = inc(i));
		hi = i;
		int l = inc(lo), r = dec(hi);
		for (int j = 0; inc(r) != l && inc(inc(r)) != l; ++j) {
			if (j < k) {
				s[l] = s[lo];
				s[r] = s[hi];
			} else if (r == l && k % 2) {
				s[l] = 'W' + 'B' - s[l];
			} else if (k % 2) {
				s[l] = 'W' + 'B' - s[l];
				s[r] = 'W' + 'B' - s[r];
			}
			l = inc(l);
			r = dec(r);
		}
	} while (i != rt);
	cout << s << '\n';
}