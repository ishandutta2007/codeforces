#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> last(n, -1), prv(n, -1), nxt(n, n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        if (last[x] != -1) nxt[last[x]] = i;
        prv[i] = last[x];
        last[x] = i;
    }

    ll cost = 0;
    int lcur = 0, rcur = 0;

    auto removeleft = [&]() {
        if (nxt[lcur] <= rcur) cost -= nxt[lcur] - lcur;
        ++lcur;
    };
    auto removeright = [&]() {
        if (prv[rcur] >= lcur) cost -= rcur - prv[rcur];
        --rcur;
    };
    auto insertleft = [&]() {
        --lcur;
        if (nxt[lcur] <= rcur) cost += nxt[lcur] - lcur;
    };
    auto insertright = [&]() {
        ++rcur;
        if (prv[rcur] >= lcur) cost += rcur - prv[rcur];
    };
    auto C = [&](int l, int r) {
        while (l < lcur) insertleft();
        while (rcur < r) insertright();
        while (lcur < l) removeleft();
        while (r < rcur) removeright();
        return cost;
    };

    vector<ll> dp(n, LINF), dpnxt(n, LINF);
    auto solve = [&](auto&& self, int l, int r, int optl, int optr) -> void {
        if (r < l) return;
        int mid = l + (r - l) / 2, opt = optl;
        for (int i = optl; i <= min(mid, optr); ++i) {
            if (chmin(dpnxt[mid], (i ? dp[i - 1] : 0) + C(i, mid))) opt = i;
        }
        self(self, l, mid - 1, optl, opt);
        self(self, mid + 1, r, opt, optr);
    };

    for (int j = 0; j < k; ++j) {
        solve(solve, 0, n - 1, 0, n - 1);
        fill(all(dp), LINF), swap(dp, dpnxt);
    }

    cout << dp.back() << endl;

    exit(0);
}