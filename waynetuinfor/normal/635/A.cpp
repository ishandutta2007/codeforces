#include <bits/stdc++.h>
using namespace std;

const int maxn = 10 + 5;
vector<pair<int, int>> vec;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r, c, n, k; cin >> r >> c >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y; --x, --y;
        vec.push_back(make_pair(x, y));
    }
    int ans = 0;
    for (int i = 0; i < r; ++i) for (int j = i; j < r; ++j) {
        for (int a = 0; a < c; ++a) for (int b = a; b < c; ++b) {
            int cnt = 0;
            for (auto p : vec) if (p.first >= i && p.first <= j && p.second >= a && p.second <= b) ++cnt;
            if (cnt >= k) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}