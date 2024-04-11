#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <complex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>

#define ft first
#define sc second
#define pb push_back
#define len(v) (int)v.size()
#define int ll
 
using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 rnd(998244);
int gcd(int a, int b) {
	if(a == 0 || b == 0) 
		return a + b;
	return gcd(b, a % b);
}

signed main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		int maxn = 15;
		int n, m;
		cin >> n >> m;
		vector<int> c(n);
		vector<vector<int> > g(n);
		for (int i = 0; i < n; i++) 
			cin >> c[i];
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			g[a].pb(b);
		}

		vector<pair<int, int>> have;
		for (int i = 0; i < n; i++) {
			if(len(g[i]) == 0) 
				continue;
			have.pb({len(g[i]), i});
		}

		vector<int> was(n + 1, 0);
		int ans = 0;
		sort(have.begin(), have.end());
		int sum = 0;
		for (int i = 0; i < len(have); i++) {
			int now = have[i].sc;
			for (auto x : g[now]) {
				if(was[x]) 
					continue;
				was[x] = 1;
				sum += c[x];
			}
			ans = gcd(ans, sum);
		}

		reverse(have.begin(), have.end());
		was = vector<int> (n + 1, 0);
		sum = 0;
		for (int i = 0; i < len(have); i++) {
			int now = have[i].sc;
			for (auto x : g[now]) {
				if(was[x]) 
					continue;
				was[x] = 1;
				sum += c[x];
			}
			ans = gcd(ans, sum);
		}
		vector<int> neww;
		for (auto x : have)
			neww.pb(x.sc);
		for (int i = 0; i < maxn; i++) {
			shuffle(neww.begin(), neww.end(), rnd);
			int sum = 0;
			was = vector<int> (n + 1, 0);
			for (auto now : neww) {
				for (auto x : g[now]) {
					if(was[x]) 
						continue;
					was[x] = 1;
					sum += c[x];
				}
				ans = gcd(ans, sum);
			}
		}
		cout << ans << '\n';

	}
}