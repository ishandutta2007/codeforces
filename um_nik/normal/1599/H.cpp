#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int ask(int x, int y) {
    assert(1 <= x && x <= 1e9 && 1 <= y && y <= 1e9);
    cout << "? " << x << " " << y << endl;
    int t; cin >> t;
    if (t == -1) {
        exit(0);
    }
    return t;
}

void solve() {
    int d1 = ask(1, 1);
    int l = 1;
    int r = 1e9;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        int t = ask(mid, 1);
        if (d1 - (mid - 1) == t) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int x1 = l;
    int y1 = (d1 + 2) - x1;
    int d2 = ask(1, 1e9);
    // (x1 - 1) + (1e9 - y2) == d2
    int y2 = (int)1e9 - 1 - d2 + x1;
    int d3 = ask(1e9, 1);
    int x2 = (int)1e9 - 1 - d3 + y1;
    cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}