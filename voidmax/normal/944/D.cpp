#include <bits/stdc++.h>
#define x fisrt
#define y second
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
using namespace std;

typedef pair<int, int> point;

const string FILENAME = "input";

const int MAXN = 5e3;

set<char> used;
string s;
long double ans = 0;
int alp[26];
long double win[MAXN];

int main() {
	ios::sync_with_stdio(false);
	//read(FILENAME);
	cin >> s;
	for (auto c : s) {
		if (used.count(c)) continue;
		used.insert(c);
		vector<int> p;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == c) {
				p.pb(i);
			}
		}
		memset(win, 0, sizeof(win));
		for (int i = 0; i < s.size(); ++i) {
			memset(alp, 0, sizeof(alp));
			for (auto j : p) {
				alp[s[(i + j) % s.size()] - 'a']++;
			}
			for (int j = 0; j < 26; ++j) {
				if (alp[j] == 1) {
					win[i] += 1. / s.size();
				}
			}
		}
		long double best = 0;
		for (int i = 0; i < s.size(); ++i) {
			best = max(best, win[i]);
		}
		ans += best;
		//cout << c << ' ' << fixed << best << endl;
	}
	cout << fixed << ans << endl;
}