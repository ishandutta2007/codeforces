#include <bits/stdc++.h>
using namespace std;

pair<int, int> qry(set<int>& s) {
	cout << "?";
	for (auto i : s) {
		cout << " " << i;
	}
	cout << endl;

	pair<int, int> res;
	cin >> res.first >> res.second;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	set<int> cur;
	int a = 0, ndx_a = 0, b = 0, ndx_b = 0;
	for (int i = 1; i <= n; ++i) {
		cur.insert(i);
		if (i >= k) {
			auto res = qry(cur);
			if (!ndx_a) {
				tie(ndx_a, a) = res;
			} else if (!ndx_b) {
				tie(ndx_b, b) = res;
			}
			cur.erase(res.first);
		}
	}

	if (a > b) {
		swap(a, b);
		swap(ndx_a, ndx_b);
	}

	int ans = 1;
	set<int> chk = cur;
	chk.insert(ndx_a);
	chk.insert(ndx_b);
	for (auto i : cur) {
		chk.erase(i);
		ans += (qry(chk).first == ndx_b);
		chk.insert(i);
	}
	cout << "! " << ans << endl;
}