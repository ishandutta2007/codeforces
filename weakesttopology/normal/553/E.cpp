#include <bits/stdc++.h>
using namespace std;
template<typename T>
complex<T> root_of_unity(int N, complex<T> dummy) {
    return polar<T>(1, 2 * acos(-1) / N);
}
//template<long long P>
//Z<P> root_of_unity(int N, Z<P> dummy) {
//    return Z<P>(3).power((P - 1) / N);
//}
template<typename T>
vector<T> fft(vector<T> p, bool inverse) {
    int N = (int)p.size();
    vector<T> q(N);
    for (int i = 0; i < N; ++i) {
        int rev = 0;
        for (int b = 1; b < N; b <<= 1) {
            rev = (rev << 1) | !!(i & b);
        }
        q[rev] = p[i];
    }
    swap(p, q);
    for (int b = 1; b < N; b <<= 1) {
        T w = root_of_unity(b << 1, T());
        if (inverse) w = T(1) / w;
        for (auto [i, x] = pair(0, T(1)); i < N; ++i, x *= w) {
            q[i] = p[i & ~b] + x * p[i | b];
        }
        swap(p, q);
    }
    if (inverse) {
        T inv = T(1) / T(N);
        for (int i = 0; i < N; ++i) p[i] *= inv;
    }
    return p;
}
template<typename T>
vector<T> operator*(vector<T> p, vector<T> q) {
    int N = int(p.size() + q.size() - 1), M = 1;
    while (M < N) M <<= 1;
    p.resize(M), q.resize(M);
    auto phat = fft(p, false), qhat = fft(q, false);
    for (int i = 0; i < M; ++i) {
        phat[i] *= qhat[i];
    }
    auto r = fft(phat, true);
    r.resize(N);
    return r;
}
using cpx = complex<double>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, T, X;
    cin >> N >> M >> T >> X;
    vector<int> a(M), b(M), c(M);
    vector<vector<double>> p(M), suff(M);
    for (int j = 0; j < M; ++j) {
        cin >> a[j] >> b[j] >> c[j];
        --a[j], --b[j];
        p[j].resize(T + 1);
        for (int t = 1; t <= T; ++t) {
            int x;
            cin >> x;
            p[j][t] = x * 1e-5;
        }
        suff[j] = p[j];
        suff[j].push_back(0);
        partial_sum(rbegin(suff[j]), rend(suff[j]), rbegin(suff[j]));
    }
    vector<int> dist(N, numeric_limits<int>::max() / 2);
    dist[N - 1] = 0;
    for (int it = 0; it < N; ++it) {
        for (int j = 0; j < M; ++j) {
            dist[a[j]] = min(dist[a[j]], dist[b[j]] + c[j]);
        }
    }
    vector<vector<double>> dp(N, vector<double>(T + 2));
    vector<vector<cpx>> dp_edge(M, vector<cpx>(T + 2));
    for (int u = 0; u < N; ++u) {
        fill(begin(dp[u]), end(dp[u]), dist[u] + X);
    }
    fill(begin(dp[N - 1]), begin(dp[N - 1]) + T + 1, 0);
    auto solve = [&](auto &self, int l, int r) -> void {
        if (l >= T) return;
        if (r - l == 1) {
            for (int j = 0; j < M; ++j) {
                double delayed = suff[j][T + 1 - l] * (dist[b[j]] + X);
                dp[a[j]][l] = min(dp[a[j]][l], dp_edge[j][l].real() + delayed + c[j]);
            }
            return;
        }
        int m = (l + r) / 2;
        self(self, m, r);
        vector<vector<cpx>> dphat(N);
        int K = 1, len = r - l;
        while (K < r - m + len - 1) K <<= 1;
        for (int u = 0; u < N; ++u) {
            vector<cpx> right(begin(dp[u]) + m, begin(dp[u]) + r);
            right.resize(K);
            dphat[u] = fft(right, false);
        }
        for (int j = 0; j < M; ++j) {
            vector<cpx> coef(begin(p[j]), begin(p[j]) + len);
            reverse(begin(coef), end(coef));
            coef.resize(K);
            auto coefhat = fft(coef, false);
            vector<cpx> addhat(K);
            for (int i = 0; i < K; ++i) {
                addhat[i] = coefhat[i] * dphat[b[j]][i];
            }
            auto add = fft(addhat, true);
            for (int i = 0; i < K; ++i) {
                int t = i + m - len + 1;
                if (l <= t && t < m) {
                    dp_edge[j][t] += add[i];
                }
            }
        }
        self(self, l, m);
    };
    solve(solve, 0, T + 1);
    cout << setprecision(10) << fixed;
    cout << dp[0][0] << '\n';
    exit(0);
}