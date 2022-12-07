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

int t, n;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		set<int> s;
		cin >> n;
		int x; cin >> x; s.insert(x);
		int lst = x, ans = 1;
		rep(i, 1, n - 1) {
			cin >> x;
			if (x > lst) {
				auto it = s.upper_bound(lst);
				if (it != s.end() && *it < x)
					ans = 0;
			}
			if (x < lst) {
				auto it = s.lower_bound(lst);
				if (it != s.begin()) {
					it--;
					if (*it > x)
						ans = 0;
				}
			}
			s.insert(x);
			lst = x;
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
	return 0;
}