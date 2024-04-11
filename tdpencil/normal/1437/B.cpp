#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

const int INF = int(1e9);

int n;
string s;

inline bool read() {
	if(!(cin >> n >> s))
		return false;
	return true;
}

int cntSame(const string &s) {
	int ans = 0;
	fore (i, 1, sz(s))
		ans += (s[i - 1] == s[i]);
	assert(ans % 2 == 0);
	return ans / 2;
}

inline void solve() {
	int ans = INF;
	fore (k, 0, 2) {
		ans = min(ans, cntSame(string(1, '0' + k) + s + string(1, '1' - k)));
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	while(tc--) {
		assert(read());
		solve();
	}
	return 0;
}