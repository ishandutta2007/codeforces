#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++)\
cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto& _ : it)\
cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;

const int S = 4;
const int N = 205;
const pii NOPE;

pii dp[S][S][N][N];

bool is_win(int sa, int sb, int a, int b) {
    return (a == 0 && b == 0 && sa == 0 && sb == 0) || dp[sa][sb][a][b] != NOPE;
}

void go_xy(int sa, int sb, int a, int b, int x, int y) {
    if (a + x >= N || b + y >= N) {
        return;
    }

    a += x;
    b += y;
    if (x > y) {
        ++sa;
    } else {
        ++sb;
    }

    dp[sa][sb][a][b] = {x, y};
}

void go(int sa, int sb, int a, int b) {
    if (!is_win(sa, sb, a, b)) {
        return;
    }

    if (max(sa, sb) == 3) {
        return;
    }

    int lim = 25;
    if (sa + sb == 4) {
        lim = 15;
    }

    for (int x = 0; x <= lim - 2; ++x) {
        go_xy(sa, sb, a, b, x, lim);
    }
    for (int y = 0; y <= lim - 2; ++y) {
        go_xy(sa, sb, a, b, lim, y);
    }
    for (int x = lim; a + x < N; ++x) {
        go_xy(sa, sb, a, b, x, x - 2);
    }
    for (int y = lim; b + y < N; ++y) {
        go_xy(sa, sb, a, b, y - 2, y);
    }
}

void init() {
    for (int sa = 0; sa < S; ++sa) {
        for (int sb = 0; sb < S; ++sb) {
            for (int a = 0; a < N; ++a) {
                for (int b = 0; b < N; ++b) {
                    go(sa, sb, a, b);
                }
            }
        }
    }
}

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);

    int best_sa = -1, best_sb = -1;
    for (int sa = 0; sa < S; ++sa) {
        for (int sb = 0; sb < S; ++sb) {
            if (sa != S - 1 && sb != S - 1)
                continue;
            if (!is_win(sa, sb, a, b)) {
                continue;
            }
            if (best_sa == -1 || best_sa - best_sb < sa - sb) {
                best_sa = sa;
                best_sb = sb;
            }
        }
    }

    if (best_sa == -1) {
        puts("Impossible");
        return;
    }

    printf("%d:%d\n", best_sa, best_sb);

    vector<pii> path;
    while (best_sa > 0 || best_sb > 0) {
        int x, y;
        tie(x, y) = dp[best_sa][best_sb][a][b];
        path.emplace_back(x, y);
        a -= x;
        b -= y;
        if (x > y) {
            --best_sa;
        } else {
            --best_sb;
        }
    }

    reverse(path.begin(), path.end());
    for (const auto& val : path) {
        printf("%d:%d ", val.first, val.second);
    }
    printf("\n");
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}