#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

#define x real
#define y imag

template<typename T>
T dot(complex<T> a, complex<T> b) { return (conj(a) * b).x(); }

template<typename T>
T cross(complex<T> a, complex<T> b) { return (conj(a) * b).y(); }

template<typename T>
istream& operator>>(istream& in, complex<T>& p) {
    T x, y;
    in >> x >> y;
    p.x(x), p.y(y);
    return in;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    using cpx = complex<ll>;
    vector<cpx> stones(k), monsters(n);
    for (auto& p : stones) cin >> p;
    for (auto& p : monsters) cin >> p;

    vector<vector<vector<int>>> path(k);
    for (int j = 0; j < k; ++j) {
        path[j].resize(n);
        for (int i = 0; i < n; ++i) {
            cpx c = monsters[i] - stones[j];
            for (int l = 0; l < n; ++l) {
                cpx d = monsters[l] - stones[j];
                if (cross(c, d) == 0 && 0 < dot(c, d) && dot(c, d) < dot(c, c)) {
                    path[j][i].push_back(l);
                }
            }
            sort(all(path[j][i]), [&](cpx p, cpx q){ return dot(p, c) < dot(q, c); });
        }
    }

    vector<int> J(k);
    iota(all(J), 0);
    vector<bool> dead(n, false);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        fill(all(dead), false);
        iota(all(J), 0);

        vector<int> P;
        do {
            int ptr = 0;
            auto dfs = [&](auto&& self, int i) -> bool {
                if (ptr == k) return false;
                int j = J[ptr++];
                for (auto l : path[j][i]) {
                    if (not dead[l] && not self(self, l)) return false;
                }
                dead[i] = true;
                P.push_back(i);
                return true;
            };
            if (dfs(dfs, i)) {
                res += 1;
                break;
            }
            for (auto l : P) dead[l] = false;
            P.clear();
        } while (next_permutation(all(J)));
    }

    cout << res << endl;

    exit(0);
}