#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct union_find {
	vector<int> p;
	union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
	bool operator() (int x, int y) { return e(x) == e(y); }
	int e(int x) {
		if (p[x] == x) return x;
		return p[x] = e(p[x]);
	}
	bool join(int x, int y) {
		x = e(x), y = e(y);
		if (x == y) return false;
		p[x] = y;
		return true;
	}
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    union_find x(n), y(n);
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        x.join(u, v);
    }
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        y.join(u, v);
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!x(i, j) && !y(i, j)) {
                x.join(i, j);
                y.join(i, j);
                ans.push_back({i, j});
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << '\n';
    }
}