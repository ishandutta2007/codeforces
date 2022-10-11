#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<vector<ll>> matrix;

const ll MOD = 998244353;

ll modpow(ll b, ll e, ll m) {
	ll r = 1;
	while(e) {
		if(e%2) {
			r*=b;
			r%=m;
		}
		b*=b;
		b%=m;
		e/=2;
	}
	return r;
}

ll inv(ll b) {
	return modpow(b, MOD-2, MOD);
}

/*
1 1 gives 1/3 (2/3)
2 1 gives 8/15 aka 931694730
3 1 gives 23/35 (12/35)

2 2 gives 2/15
3 2 gives 2/7
4 2 gives

3 3 gives 2/35
*/

void solve() {
	int n, k, l;
	cin >> n >> k >> l;
	vector<ll> dp;
	ll divdiv = inv(2*n+1);
	// number of open segments!
	dp.resize(n+1);
	dp[0] = 1;
	ll ret = 0;
	for(int e = 2*n; e > 0; e--) {
		vector<ll> ndp;
		ndp.resize(n+1);
		ll denom = inv(e);
		for(int i = 0; i < dp.size(); i++) {
			if(dp[i] == 0) continue;
			if(i >= k) {
				ret += dp[i];
				ret %= MOD;
			}
			int canOpen = e-i;
			int canClose = i;
			if(i+1 < ndp.size()) {
				ll inc = canOpen;
				inc *= denom;
				inc %= MOD;
				inc *= dp[i];
				inc %= MOD;
				ndp[i+1] += inc;
				ndp[i+1] %= MOD;
			}
			if(i-1 >= 0) {
				ll inc = canClose;
				inc *= denom;
				inc %= MOD;
				inc *= dp[i];
				inc %= MOD;
				ndp[i-1] += inc;
				ndp[i-1] %= MOD;
			}
		}
		dp = ndp;
	}
	ret *= l;
	ret %= MOD;
	ret *= divdiv;
	ret %= MOD;
	cout << ret << endl;
}

/*
void solve() {
	std::uniform_real_distribution<double> distribution(0.0,1.0);
	mt19937 g1;
	double ret = 0;
	for(int t = 1; true; t++) {
		vector<pair<double,int>> v;
		for(int k = 0; k < AMT; k++) {
			double a = distribution(g1);
			double b = distribution(g1);
			if(a>b) swap(a, b);
			v.emplace_back(a, 1);
			v.emplace_back(b, -1);
		}
		sort(v.begin(), v.end());
		double last = 0;
		int amt = 0;
		for(auto x: v) {
			if(amt >= THRESH) ret += x.first - last;
			last = x.first;
			amt += x.second;
		}
		if(t % 10000 == 0) {
			cout << fixed << setprecision(15) << ret/t << endl;
		}
	}
}
*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
	/*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
	*/
	solve();
}