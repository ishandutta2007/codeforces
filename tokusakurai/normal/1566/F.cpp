#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, x, n) for (int i = x; i <= n; i++)
#define rep3(i, x, n) for (int i = x; i >= n; i--)
#define each(e, v) for (auto &e : v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}
template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<ll> a(N);
        rep(i, N) cin >> a[i];
        sort(all(a));

        vector<ll> l(M), r(M);
        rep(i, M) cin >> l[i] >> r[i];

        vector<int> v(M);
        iota(all(v), 0);
        sort(all(v), [&](int i, int j) {
            if (r[i] != r[j]) return r[i] < r[j];
            return l[i] > l[j];
        });

        vector<ll> L, R;
        vector<int> tmp;

        each(e, v) {
            if (empty(tmp))
                tmp.eb(e);
            else {
                int k = tmp.back();
                if (l[e] > l[k]) tmp.eb(e);
            }
        }

        each(e, tmp) L.eb(l[e]), R.eb(r[e]);
        M = sz(tmp);

        vector<int> p(N); // i[0,p[i])
        rep(i, N) p[i] = upper_bound(all(L), a[i]) - begin(L);

        vector<ll> dp(M + 1, INF);
        dp[0] = 0;

        rep(i, N) {
            int lx = (i == 0 ? 0 : p[i - 1]), rx = p[i];
            int ly = p[i], ry = (i == N - 1 ? M : p[i + 1]);

            vector<ll> dx, c1, c2;
            rep2(x, lx, rx) {
                ll d = (x == rx ? 0 : max(0LL, a[i] - R[x]));
                dx.eb(-d), c1.eb(dp[x] + d), c2.eb(dp[x] + 2 * d);
            }

            int T = rx - lx + 1;
            rep2(j, 1, T - 1) chmin(c1[j], c1[j - 1]);
            rep3(j, T - 2, 0) chmin(c2[j], c2[j + 1]);

            rep2(y, ly, ry) {
                ll dy = (y == ly ? 0 : L[y - 1] - a[i]);
                int k = lower_bound(all(dx), -dy) - begin(dx);
                if (k > 0) chmin(dp[y], c1[k - 1] + 2 * dy);
                if (k < T) chmin(dp[y], c2[k] + dy);
            }
        }

        cout << dp[M] << '\n';
    }
}