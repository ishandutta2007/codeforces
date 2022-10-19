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

bool judge(const vector<ll> &v) {
    int n = sz(v);
    if (n == 3) return (v[0] - v[1]) * (v[1] - v[2]) < 0;

    rep(x, 4) {
        vector<int> tmp;
        rep(y, 4) {
            if (y != x) tmp.eb(y);
        }
        sort(all(tmp));
        int i = tmp[0], j = tmp[1], k = tmp[2];
        if ((v[i] - v[j]) * (v[j] - v[k]) >= 0) return false;
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<ll> a(N);
        rep(i, N) cin >> a[i];

        if (N == 1) {
            cout << "1\n";
            continue;
        }

        ll ans = N + (N - 1);

        rep2(i, 0, N - 3) {
            if (judge(vector<ll>(begin(a) + i, begin(a) + i + 3))) ans++;
        }
        rep2(i, 0, N - 4) {
            if (judge(vector<ll>(begin(a) + i, begin(a) + i + 4))) ans++;
        }

        cout << ans << '\n';
    }
}