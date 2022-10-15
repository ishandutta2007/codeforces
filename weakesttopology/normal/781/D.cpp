#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr int N = 500;
using Matrix = array<bitset<N>, N>;

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    Matrix res, rhst;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rhst[i][j] = rhs[j][i];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if ((lhs[i] & rhst[j]).any()) res[i][j] = true;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if (m == 0) {
        cout << 0 << endl;
        exit(0);
    }

    array<Matrix, 2> P;

    for (int j = 0; j < m; ++j) {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        P[t][u][v] = true;
    }

    ll res = 1, inf = 1e18;

    stack<pair<ll, array<Matrix, 2>>> stk;
    while ((P[0] * P[1])[0].any() && res <= inf) {
        stk.emplace(res, P);
        P = {P[0] * P[1], P[1] * P[0]};
        res *= 2;
    }

    int t = 1;
    while (not empty(stk) && res <= inf) {
        auto [add, Q] = stk.top();
        stk.pop();
        if ((P[0] * Q[t])[0].any()) {
            P[0] = P[0] * Q[t];
            res += add;
            t ^= 1;
        }
    }

    if (res > inf) res = -1;
    cout << res << endl;

    exit(0);
}