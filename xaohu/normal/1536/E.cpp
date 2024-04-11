#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " = " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

const int P = 1e9 + 7;

int t, n, m;
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int cnt = 0, cnt0 = 0;
		rep(i, 1, n) {
			cin >> s;
			cnt0 += count(s.begin(), s.end(), '0');
			cnt += count(s.begin(), s.end(), '#');
		}
		int res = 1;
		while (cnt--) res = 2 * res % P;
		if (!cnt0) res = (res - 1 + P) % P;
		cout << res << "\n";
	}	
	return 0;
}