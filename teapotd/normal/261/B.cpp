#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

int n, p;
Vi elems;
vector<ll> counts;

struct DP {
	ll arr[51][51];

	DP() {
		memset(arr, 0, sizeof(arr));
		arr[0][0] = 1;
	}

	ll& operator()(int s, int k) { return arr[s][k]; }

	void add(int x) {
		for (int k = n; k > 0; k--) {
			for (int s = p; s >= x; s--) {
				arr[s][k] += arr[s-x][k-1];
			}
		}
	}
};

void compute(DP& dp, int e) {
	rep(s, max(p-e+1, 0), p+1) {
		rep(k, 0, n+1) counts[k] += dp(s, k);
	}
}

void solve(DP& dp, int b, int e) {
	if (b >= e) return;

	if (b+1 == e) {
		compute(dp, elems[b]);
		return;
	}

	int m = (b+e) / 2;

	DP cp = dp;
	rep(i, m, e) cp.add(elems[i]);
	solve(cp, b, m);

	rep(i, b, m) dp.add(elems[i]);
	solve(dp, m, e);
}

int main() {
	cin.sync_with_stdio(0);
	cout << fixed << setprecision(10);

	cin >> n;
	elems.resize(n);
	each(e, elems) cin >> e;
	cin >> p;

	if (accumulate(all(elems), 0) <= p) {
		cout << n << '\n';
		return 0;
	}

	DP dp;
	counts.resize(n+1);
	solve(dp, 0, n);

	double ans = 0;

	rep(k, 0, n) {
		double cur = double(counts[k]) * k / n;
		rep(i, 1, n-k) cur *= double(i) / (k+i);
		ans += cur;
	}

	cout << ans << '\n';
	return 0;
}