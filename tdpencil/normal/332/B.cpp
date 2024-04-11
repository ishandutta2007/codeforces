
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;
typedef long long ll; 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define ar array


template<class T> struct rangeSum {
	vector<T> prefixSums;
	void init(vector<T> &a) {
		prefixSums = a;
		partial_sum(prefixSums.begin(), prefixSums.end(), prefixSums.begin());
	}
	T query(int l, int r) {
		assert(l >= 0 && r < int(prefixSums.size()));
		return l == 0 ? prefixSums[r] : prefixSums[r] - prefixSums[l-1];
	}
	void add(int l, int r, T val) {
		prefixSums[r] += val;
		prefixSums[l] -= val;
	}
};

struct segtree {
	pair<ll, ll> mx;
	int leftmost, rightmost;
	struct segtree *lChild;
	struct segtree *rChild;
	segtree(int l, int r, vector<pair<ll, ll>> &a) {
		leftmost = l;
		rightmost = r;

		if(l == r)
			mx = a[l];
		else {
			int mid = (l + r) / 2;
			lChild = new segtree(l, mid, a);
			rChild = new segtree(mid+1, r, a);
			pair<ll, ll> f = lChild->mx;
			pair<ll, ll> s = rChild->mx; 
			if(f.second >= s.second) {
				mx = f;
			} else {
				mx = s;
			}
		}
	}
	pair<ll, ll> query(int l, int r) {
		if(l > rightmost || r < leftmost)
			return make_pair(-1LL, -1LL);
		else if(l <= leftmost && r >= rightmost)
			return mx;
		pair<ll, ll> f = lChild->query(l, r);
		pair<ll, ll> s = rChild->query(l, r);
		if(f.second >= s.second) {
			return f;
		} else {
			return s;
		}
	}
};
void solve() {
    int N, K;
    cin >> N >> K;

    vector<int64_t> A(N);

    for(auto &a: A)
    	cin >> a;

    rangeSum<int64_t> qu;
    qu.init(A);

    vector<pair<ll, ll>> Q;
    ll mx = 0;

    pair<ll, ll> ans(0LL, 0LL);
    for(ll i = 0; i < N-K+1; i++) {
    	ll range = qu.query(i, i+K-1);
    	Q.push_back({i, range});
    }
    sort(Q.begin(), Q.end());
    int S = Q.size();
    segtree st(0, S - 1, Q);
    // iterate through the list and find the noe that is just out of the range

    for(auto &e: Q) {
    	ll x = e.first;
    	ll y = e.second;
    	ll cur = y;
    	int64_t toGetTo = x + K;
    	const pair<ll, ll> c(toGetTo, 0LL);
    	int p = lower_bound(Q.begin(), Q.end(), c) - Q.begin();
    	if(p >= S) continue;
    	pair<ll, ll> mt = st.query(p, S-1);
    	if(mt.second + cur > mx) {
    		mx = mt.second + cur;
    		ans = {x, mt.first};
    	}
    }

    cout << ans.first + 1 << " " << ans.second + 1<< "\n";



}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; //cin >> T;
   
    while(T--)
        solve();
}