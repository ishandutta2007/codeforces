#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

vector<int> have[26];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < SZ(s); i++) {
		have[s[i] - 'a'].pb(i);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (l == r) {
			cout << "Yes\n";
			continue;
		}
		char c = s[r];
		int sum = 0;
		for (char cur = 'a'; cur <= 'z'; cur++) {
			if (cur == c) {
				continue;
			}
			sum += (upper_bound(all(have[cur - 'a']), r) - lower_bound(all(have[cur - 'a']), l) > 0);
		}
		if (sum > 1) {
			cout << "Yes\n";
		}
		else {
			cout << (s[l] != s[r] ? "Yes\n" : "No\n");
		}
	}	
}