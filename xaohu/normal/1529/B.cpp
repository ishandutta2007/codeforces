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

int t, n, x;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> g;
		int mi = 1e9 + 1;
		rep(i, 1, n) {
			int x;
			cin >> x;
			if (x <= 0)
				g.pb(x);
			else
				mi = min(mi, x);
		}
		sort(g.begin(), g.end());
		int diff = 1e9;
		rep(i, 0, sz(g) - 2)
			diff = min(diff, g[i + 1] - g[i]);
		if (mi <= 1e9 && mi <= diff)
			cout << sz(g) + 1 << "\n";
		else
			cout << max(1, sz(g)) << "\n";
	}		
	return 0;
}