// gonna try some vodooo magic
#include <bits/stdc++.h>
using namespace std;


#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
typedef long long ll;


// #define test_case 0

template<class T>
struct segment_tree {
	// prevent pointer overflow
	struct segment_tree *lChild = NULL, *rChild = NULL;
	T sum = 0, lazy = 0;
	int leftmost, rightmost;
	using ll = long long;

	segment_tree(int left, int right, vector<T> &v) {
		// N log N
		leftmost = left;
		rightmost = right;
		if(leftmost == rightmost) {
			sum = v[leftmost];
		} else {
			int mid = (leftmost + rightmost) >> 1;
			lChild = new segment_tree(leftmost, mid, v);
			rChild = new segment_tree(mid + 1, rightmost, v);
			update();
		}
	}
	void push() {
		// O(1)
		lChild->lazy += lazy;
		rChild -> lazy += lazy;
		lChild->sum += lazy;
		rChild -> sum += lazy;
		lazy = 0;
	}
	void update() {
		sum = lChild->sum + rChild->sum;
	}

	void pointUpdate(int pos, long long val) {
		// log N
		if (leftmost == rightmost) {
			sum += val;
		} else {
			int r = lChild -> rightmost;
			if (pos <= r) {
				lChild->pointUpdate(pos, val);
			} else {
				rChild->pointUpdate(pos, val);
			}
			update();
			push();
		}
	}
	void updateRange(int left, int right, long long val) {
		// log N
		if(left > rightmost || right < leftmost)
			return;
		else if(left <= leftmost && right >= rightmost) {
			sum += val;
			lazy += val;
		} else {
			

			lChild -> updateRange(left, right, val);
			rChild -> updateRange(left, right, val);
			update();
			push();
		}
	}

	ll get(int pos) {
		// log N
		if(leftmost == rightmost) {
			return sum;
		} else {
			int r = lChild -> rightmost;
			if(pos <= r) {
				return lChild->get(pos);
			} else {
				return rChild->get(pos);
			}
		}
	}
	ll rangeQuery(int left, int right) {
		// log N
		if(left > rightmost || right < leftmost)
			return 0;
		else if(left <= leftmost && right >= rightmost)
			return sum;
		push();
		return (lChild -> rangeQuery(left, right)) + (rChild -> rangeQuery(left, right));
	}
};

void solve() 
{
	int n; cin >> n;
	vector<int> a(n);
	for(auto &i : a) {
		cin >> i;
	}

	int q; cin >> q;
	while(q--) {
		int t; cin >> t;
		if(t == 1) {
			int l, r;
			cin >> l >> r;
			--l, --r;
			long long x = 0;
			for(int i = l; i <= r; i++)
				x += a[i];
			cout << x << "\n";
		} else {
			int l, r, x;
			cin >> l >> r >> x;
			--l, --r;
			for(int i = l; i <= r; i++)
				a[i] ^= x;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t = 1;
#ifdef test_case
	cin >> t;
#endif

	for(int tt = 0; tt < t; tt++)
		solve();
}
// while not used s[i]
// find all paths 
// take best path
// O(N * N)