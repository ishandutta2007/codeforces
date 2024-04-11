#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

struct ST {
	vector<int> t;
	ST(int n) {
		t.resize(4 * n + 10);
		build(1, 1, n);
	}
	void build(int v, int l, int r) {
		if (l == r) {
			t[v] = 1;
			return;
		}
		int mid = (l + r) / 2;
		build(2 * v, l, mid);
		build(2 * v + 1, mid + 1, r);
		t[v] = t[2 * v] + t[2 * v + 1];
	}
	void update(int v, int l, int r, int need) {
		if (l == r) {
			t[v] = 0;
			return;
		}
		int mid = (l + r) / 2;
		if (need <= mid) {
			update(2 * v, l ,mid, need);
		}
		else {
			update(2 * v + 1, mid + 1, r, need);
		}
		t[v] = t[2 * v] + t[2 * v + 1];
	}
	int get_sum(int v, int l, int r, int a, int b) {
		if (l > b || r < a) {
			return 0;
		}
		if (l >= a && r <= b) {
			return t[v];
		}
		int mid = (l + r) / 2;
		return get_sum(2 * v, l, mid, a, b) + get_sum(2 * v + 1, mid + 1, r, a, b);
	}
	int get_kth(int v, int l, int r, int need) {
		if (l == r) {
			return l;
		}
		int mid = (l + r) / 2;
		if (t[2 * v] >= need) {
			return get_kth(2 * v, l, mid, need);
		}
		else {
			return get_kth(2 * v + 1, mid + 1, r, need - t[2 * v]);
		}
	}
};

signed main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &it : a) {
		cin >> it;
		it++;
	}
	for (auto &it : b) {
		cin >> it;
		it++;
	}
	ST tree1(n), tree2(n);
	vector<int> calc(n);
	for (int i = 0; i < n; i++) {
		calc[i] = tree2.get_sum(1, 1, n, 1, b[i] - 1);
		//cout << calc[i] << ' ';
		tree2.update(1, 1, n, b[i]);
	}
	//cout << '\n';
	ST tree3(n);
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int vl = (tree1.get_sum(1, 1, n, 1, a[i] - 1) + calc[i]);
		//cout << vl << '\n';
		if (vl >= n - i && !ans.empty()) {
			for (int j = SZ(ans) - 1; j >= 0; j--) {
				if (ans[j] + 1 == n - i + SZ(ans) - j) {
					ans[j] = 0;
				}
				else {
					ans[j]++;
					break;
				}
			}
		}
		vl = vl % (n - i);
		//cout << tree1.get_sum(1, 1, n, 1, a[i] - 1) << ' ' << calc[i] << ' ' << vl << '\n';
		tree1.update(1, 1, n, a[i]);
		ans.pb(vl);
		//int cur = tree3.get_kth(1, 1, n, vl);
		//cout << cur - 1 << ' ';
		//tree3.update(1, 1, n, cur);
		/*for (auto it : ans) {
			cout << it << ' ';
		}
		cout << '\n';*/
	}
	for (auto it : ans) {
		int cur = tree3.get_kth(1, 1, n, it + 1);
		cout << cur - 1 << ' ';
		tree3.update(1, 1, n, cur);
	}
	cout << '\n';
}