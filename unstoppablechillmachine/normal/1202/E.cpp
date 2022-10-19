#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
 
const int B = (int)sqrt(2e5);
const int MX = 2e5 + 10;
int mp[MX][26], term[MX], cnt = 1;
void add(string &s) {
	int v = 1;
	for (int i = 0; i < SZ(s); i++) {
		if (!mp[v][s[i] - 'a']) {
			mp[v][s[i] - 'a'] = ++cnt;
		}
		v = mp[v][s[i] - 'a'];
	}
	term[v]++;
}
 
const int N = 4e5 + 10;
int z[N], pref[N], suf[N];
 
signed main() {
	ios_base::sync_with_stdio(0);
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector<string> big, small;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (SZ(s) > B) {
			big.pb(s);
		}
		else {
			small.pb(s);
		}
	}
	for (auto it : small) {
		add(it);
	}
	for (int i = 0; i < SZ(t); i++) {
		int lim = min(B, SZ(t) - i);
		int v = 1;
		for (int j = 0; j < lim; j++) {
			v = mp[v][t[i + j] - 'a'];
			if (!v) {
				break;
			} 
			pref[i] += term[v];
			suf[i + j] += term[v];
		}
	}
	for (auto it : big) {
		int sz1 = SZ(it), sz2 = SZ(t);
		int n = sz1 + sz2, l = 0, r = 1;
		for (int i = 1; i < n; i++) {
			z[i] = min(z[i - l], max(r - i, 0));
			while (i + z[i] < n) {
				char c = (z[i] < sz1 ? it[z[i]] : t[z[i] - sz1]), 
				c2 = (i + z[i] < sz1 ? it[i + z[i]] : t[i + z[i] - sz1]);
				if (c == c2) {
					z[i]++;
				} 
				else {
					break;
				}
			}
			if (i + z[i] > r) {
				l = i;
				r = i + z[i];
			}
		}
		for (int i = SZ(it); i < n; i++) {
			if (z[i] >= SZ(it)) {
				pref[i - SZ(it)]++;
				suf[i - 1]++;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i + 1 < SZ(t); i++) {
		ans += suf[i] * 1ll * pref[i + 1];
	}
	cout << ans << '\n';
}