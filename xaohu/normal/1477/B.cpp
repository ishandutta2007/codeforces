#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

const int N = 222000;

int T, n, q, l[N], r[N];
char s[N], t[N];

void solve() {
	cin >> n >> q >> s + 1 >> t + 1;
	map<int, int> m;
	rep(i, 1, n) m[i] = t[i] - '0';
	rep(i, 1, q) cin >> l[i] >> r[i];
	int ans = 1;
	per(i, 1, q) {
		for (auto x : {l[i], r[i] + 1})
			m[x] = prev(m.upper_bound(x))->se;
		int cnt[2]{};
		for (auto it = m.find(l[i]); it->first <= r[i]; it = m.erase(it)) 
			cnt[it->second] += next(it)->first - it->first;
		if (cnt[0] == cnt[1]) ans = 0;
		m[l[i]] = cnt[0] < cnt[1];
	}
	rep(i, 1, n)
		if (s[i] - '0' != prev(m.upper_bound(i))->second)
			ans = 0;
	cout << (ans ? "YES\n" : "NO\n");
}		 
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}