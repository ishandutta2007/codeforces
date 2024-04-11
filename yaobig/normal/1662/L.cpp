#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

class RangeMin {
	private:
		vector<ll> seg;
		int n;
	public:	
		RangeMin(const vector<ll>& v) : n(v.size()), seg(2*v.size()) {
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}
		ll get(int a, int b) const {
			ll res = INF; // Change to INF to allow a > b
			for (a += n, b += n+1; a < b; a=(a+1)/2, b /= 2) {
				if (a & 1) res = min(res, seg[a]);
				if (b & 1) res = min(res, seg[b-1]);
			}
			return res;
		}
		void offer(int i, ll v) {
			seg[i + n] = min(seg[i + n], v);
			for (i += n; i > 1; i /= 2) seg[i/2] = min(seg[i], seg[i^1]);
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll v;
	cin >> n >> v;

	vector<ll> ts(n), xs(n), lps(n + 1);
	vector<pair<ll, ll>> itvs(n);
	for (ll& t : ts) cin >> t;
	for (ll& x : xs) cin >> x;
	for (int i = 0; i < n; ++i) {
		ll le = xs[i] - ts[i] * v;
		ll ri = xs[i] + ts[i] * v;
		itvs[i] = {ri, -le};
		lps[i] = le;
	}
	lps[n] = 0;
	sort(itvs.begin(), itvs.end());
	sort(lps.begin(), lps.end());
	lps.erase(unique(lps.begin(), lps.end()), lps.end());

	ll res = 0;
	RangeMin dp(vector<ll>(lps.size(), INF));
	dp.offer(bins(lps, 0ll), 0);

	for (auto pr : itvs) {
		if (pr.first < 0) continue;

		int i = bins(lps, -pr.second);
		ll off = 1 - dp.get(i, (int)lps.size() - 1);
		res = max(res, off);
		dp.offer(i, -off);
	}
	cout << res << '\n';
}