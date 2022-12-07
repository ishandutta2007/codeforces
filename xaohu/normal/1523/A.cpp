#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

int n, m;
string s;

void solve() {
	cin >> n >> m >> s;
	rep(i, 0, n - 1) {
		if (s[i] == '1') {
			cout << 1;
			continue;
		}
		int l = m + 5, r = m + 5;
		rep(j, i + 1, n - 1)
			if (s[j] == '1') {
				r = j - i;
				break;
			}
		per(j, 0, i - 1) {
			if (s[j] == '1') {
				l = i - j;
				break;
			}
		}
		if (l != r && min(l, r) <= m)
			cout << 1;
		else
			cout << 0;
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}