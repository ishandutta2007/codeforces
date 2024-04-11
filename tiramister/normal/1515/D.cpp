#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> lcnt(n, 0), rcnt(n, 0);
    for (int i = l; i--;) {
        int x;
        cin >> x;
        ++lcnt[--x];
    }
    for (int i = r; i--;) {
        int x;
        cin >> x;
        ++rcnt[--x];
    }

    int rem = n / 2;
    vector<int> ls, rs;
    for (int c = 0; c < n; ++c) {
        auto m = min(lcnt[c], rcnt[c]);
        lcnt[c] -= m, rcnt[c] -= m, rem -= m;

        if (lcnt[c] > 0) ls.push_back(lcnt[c]);
        if (rcnt[c] > 0) rs.push_back(rcnt[c]);
    }

    if (l > r) {
        swap(l, r);
        swap(ls, rs);
    }
    // r >= l

    int ans = 0, d = (r - l) / 2;
    for (auto x : rs) {
        while (x >= 2 && d > 0) {
            ++ans;
            x -= 2;
            --d;
            --rem;
        }
    }
    ans += rem + d;

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}