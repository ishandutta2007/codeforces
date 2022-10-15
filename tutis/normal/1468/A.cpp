#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif
struct Node {
	Node *left = NULL, *right = NULL;
	int from, to;
	long long ma1 = 0, ma1t = 0, ma2 = 0, lazy = -1, lazyt;
	long long op = 0;
	Node(int from, int to): from(from), to(to) {
		if (from == to) {
			return;
		}

		left = new Node(from, (from + to) / 2);
		right = new Node((from + to) / 2 + 1, to);
	}
	void fix() {
		if (ma1 < lazy) {
			ma1 = lazy;
			ma1t = lazyt;
		}

		if (ma1t < op) {
			ma2 = max(ma2, ma1 + 1);
		}

		if (op and from != to) {
			left->op = max(left->op, op);
			right->op = max(right->op, op);
		}

		if (from != to) {
			if (lazy > left->lazy) {
				left->lazy = lazy;
				left->lazyt = lazyt;
			}
			if (lazy > right->lazy) {
				right->lazy = lazy;
				right->lazyt = lazyt;
			}
		}

		lazy = -1;
		lazyt = -1;
		op = false;
	}
	long long get1(int fr, int t) {
		fix();

		if (fr <= from and to <= t) {
			return ma1;
		}

		if (t < from or to < fr) {
			return -100000000000000000ll;
		}

		return max(left->get1(fr, t), right->get1(fr, t));
	}
	long long get2(int fr, int t) {
		fix();

		if (fr <= from and to <= t) {
			return ma2;
		}

		if (t < from or to < fr) {
			return -100000000000000000ll;
		}

		return max(left->get2(fr, t), right->get2(fr, t));
	}
	void update(int fr, int t, long long val, int l) {
		fix();

		if (t < from or to < fr) {
			return;
		}

		if (fr <= from and to <= t) {
			lazy = val;
			lazyt = l;
			fix();
		}
		else {
			left->update(fr, t, val, l);
			right->update(fr, t, val, l);
			ma1 = max(left->ma1, right->ma1);
			ma2 = max(left->ma2, right->ma2);
		}
	}
	void do_op(int fr, int t, int l) {
		fix();

		if (t < from or to < fr) {
			return;
		}

		if (fr <= from and to <= t) {
			op = l;
			fix();
		}
		else {
			left->do_op(fr, t, l);
			right->do_op(fr, t, l);
			ma1 = max(left->ma1, right->ma1);
			ma2 = max(left->ma2, right->ma2);
		}
	}
	~Node() {
		if (left) {
			delete left;
			delete right;
		}
	}
};
/*input
4
8
1 2 7 3 2 1 2 3
2
2 1
7
4 1 5 2 6 3 7
7
4 1 5 3 7 2 6

*/
/*input
1
15
15 6 14 15 15 6 13 15 7 11 3 13 8 10 14
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> x(n);

		for (auto &&i : x) {
			cin >> i;
		}

		Node medis(0, n + 1);
		int l = 1;

		for (int i : x) {
			int b1mi = medis.get1(i, i);
			int b2mi = medis.get2(i, i);

			medis.do_op(0, i, l + 1);
			medis.update(i, n, b1mi + 1, l + 2);
			medis.update(i, n, b2mi + 1, l + 2);
			l += 2;
			// for (int j = 0; j < n; ++j) {
			// 	cout << medis.get1(j, j) << " ";
			// }
			//
			// cout << endl;
			//
			// for (int j = 0; j < n; ++j) {
			// 	cout << medis.get2(j, j) << " ";
			// }
			//
			// cout << endl;
		}

		cout << medis.get1(0, n) << "\n";
	}

}