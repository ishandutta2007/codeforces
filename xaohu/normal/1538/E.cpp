#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;
 
int T, n;
string z, a, b;
map<string, tuple<string, string, long long>> m;

int cnt(string s) {
	int res = 0;
	rep(i, 0, (int)s.size() - 4) 
		res += (s.substr(i, 4) == "haha");
	return res;
}

void solve() {
	m.clear();
	cin >> n;
	while (n--) {
		cin >> a >> z >> b;
		if (z == ":=") {
			int d = min(3, (int)b.size());
			m[a] = {b.substr(0, d), b.substr(b.size() - d, d), cnt(b)};
		}
		else {
			string c, d;
			cin >> c >> d;
			auto [l1, r1, c1] = m[b];
			auto [l2, r2, c2] = m[d];
			m[a] = {l1 + l2, r1 + r2, c1 + c2 + cnt(r1 + l2)};
			if (l1.size() + l2.size() > 3)
				get<0>(m[a]).resize(3);
			get<1>(m[a]).erase(0, max(0, (int)r1.size() + (int)r2.size() - 3));
		}
		if (!n) cout << get<2>(m[a]) << endl;
	}
}	
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}