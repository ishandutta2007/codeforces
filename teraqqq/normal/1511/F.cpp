#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

const int MOD = 998244353;

struct Matrix {
    int n;
    vector<vector<int>> w;

    Matrix(const int n) : n(n), w(n, vector<int>(n)) { }

    Matrix operator * (const Matrix& m) const {
        Matrix res(n);

        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (!w[i][j]) continue;
            for (int t = 0; t < n; ++t) {
                res.w[i][t] = (res.w[i][t] + (ll) w[i][j] * m.w[j][t]) % MOD;
            }
        }

        return res;
    }
};

void dfs_forw(int v, const int r, const vector<vector<int>>& w, vector<char>& used) {
    if (used[v]) return;
    used[v] = true;

    for (int i = 0; i < r; ++i) {
        if (w[v][i]) dfs_forw(i, r, w, used);
    }
}

void dfs_back(int v, const int r, const vector<vector<int>>& w, vector<char>& used) {
    if (used[v]) return;
    used[v] = true;

    for (int i = 0; i < r; ++i) {
        if (w[i][v]) dfs_back(i, r, w, used);
    }
}

void solve() {
    int n, m; cin >> n >> m;

    map<string, int> id;
    id[""] = 0;
    int vc = 1;

    vector<string> v(n), phi { "" };
    for (string& s : v) {
        cin >> s;
        for (int i = 1; i <= size(s); ++i) {
            auto t = s.substr(0, i);
            if (!id.count(t)) {
                id[t] = vc++;
                phi.push_back(t);
            }
        }
    }

    const int k = size(id);
    const int r = k * k;
    vector w(r, vector<int>(r));

    for (int ia = 0; ia < k; ++ia)
    for (int ib = 0; ib < k; ++ib) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            auto ta = phi[ia] + ch; const int sa = id.count(ta) ? id[ta] : -1;
            auto tb = phi[ib] + ch; const int sb = id.count(tb) ? id[tb] : -1;

            for (int ja = 0; ja < n; ++ja) {
                if (ta != v[ja]) continue;
                for (int jb = 0; jb < n; ++jb) {
                    if (tb != v[jb]) continue;
                    w[ia*k+ib][0]++;
                }

                if (sb != -1) w[ia*k+ib][sb]++;
            }

            for (int jb = 0; jb < n; ++jb) {
                if (sa != -1 && tb == v[jb]) w[ia*k+ib][sa*k]++;
            }

            if (sa != -1 && sb != -1) w[ia*k+ib][sa*k+sb]++;
        }
    }

    vector<char> u1(r), u2(r);
    int us = 0;

    dfs_forw(0, r, w, u1);
    dfs_back(0, r, w, u2);

    vector<int> tid;

    for (int i = 0; i < r; ++i) {
        if (u1[i] && u2[i]) {
            tid.push_back(i);
        }
    }

    const int p = size(tid);

    Matrix ans(p), mul(p);

    for (int i = 0; i < p; ++i)
    for (int j = 0; j < p; ++j) {
        mul.w[i][j] = w[tid[i]][tid[j]];
    }

    for (int i = 0; i < p; ++i) ans.w[i][i] = 1;

    for (; m != 0; m >>= 1) {
        if (m & 1) ans = ans * mul;
        mul = mul * mul;
    }

    cout << ans.w[0][0] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}

// dp[0] = 1
// dp[1] = 1
// dp[2] = 2
// dp[3] = 3
// dp[4] = 5