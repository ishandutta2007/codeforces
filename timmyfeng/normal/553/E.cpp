#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;

using point = complex<double>;

const int T = 1 << 16;

point root[T];

void fft(vector<point>& a) {
    int n = a.size();

    vector<int> reverse(n);
    for (int i = 0; i < n; ++i) {
        reverse[i] = (reverse[i / 2] + (i % 2) * n) / 2;
        if (i < reverse[i]) {
            swap(a[i], a[reverse[i]]);
        }
    }

    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j < n; j += 2 * i) {
            for (int k = 0; k < i; ++k) {
                point l = a[j + k];
                point r = a[i + j + k] * root[i + k];
                a[j + k] = l + r;
                a[i + j + k] = l - r;
            }
        }
    }
}

vector<point> mul(vector<point> a, vector<point> b) {
    int n = 1, m = a.size() + b.size();
    while (n < m) {
        n *= 2;
    }

    a.resize(n), b.resize(n);
    fft(a), fft(b);

    for (int i = 0; i < n; ++i) {
        a[i] *= b[i];
    }
    fft(a);

    for (auto &i : a) {
        i /= n;
    }
    reverse(a.begin() + 1, a.end());

    a.resize(m - 1);
    return a;
}

const int M = 100;
const int N = 50;

double prob[M][T], expect[M][T], ans[N][T];
array<int, 3> edges[M];
long long dist[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(6);

    for (int i = 1; i < T; i *= 2) {
        for (int j = 0; j < i; ++j) {
            root[i + j] = polar(1.0, j * M_PI / i);
        }
    }

    int n, m, t, x;
    cin >> n >> m >> t >> x;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u - 1, v - 1, w};

        for (int j = 1; j <= t; ++j) {
            int p;
            cin >> p;
            prob[i][j] = p / 100000.0;
        }
    }

    fill(dist, dist + n - 1, LLONG_MAX);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            auto [u, v, w] = edges[j];
            if (dist[v] < LLONG_MAX) {
                dist[u] = min(dist[u], dist[v] + w);
            }
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        fill(ans[i], ans[i] + t + 1, HUGE_VAL);
    }

    for (int i = 0; i < m; ++i) {
        auto [u, v, w] = edges[i];

        double sum = 0.0;
        for (int j = t; j >= 0; --j) {
            expect[i][j] = w + sum * (dist[v] + x);
            sum += prob[i][j];
        }

        ans[u][0] = min(ans[u][0], expect[i][0]);
    }

    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < m; ++j) {
            auto [u, v, w] = edges[j];

            for (int k = 1; i % k == 0; k *= 2) {
                vector<point> poly = mul(
                    vector<point>(ans[v] + i - k, ans[v] + i),
                    vector<point>(prob[j] + k, prob[j] + min(2 * k, t + 1))
                );

                for (int l = 0; l <= t - i && l <= (int) poly.size(); ++l) {
                    expect[j][l + i] += poly[l].real();
                }
            }

            ans[u][i] = min(ans[u][i], expect[j][i]);
        }
    }

    cout << ans[0][t] << "\n";
}