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

        map<int, vector<int>> mp;

        vector<int> res(N * M);

        rep(i, N * M) {
            int x;
            cin >> x;
            mp[x].eb(i);
        }

        int p = 0;

        each(e, mp) {
            reverse(all(e.second));
            each(u, e.second) { res[p++] = u; }
        }

        vector<int> cnt(N * M, 0);

        ll ans = 0;

        rep(i, N * M) {
            rep(j, res[i]) ans += cnt[j];
            cnt[res[i]]++;
        }

        cout << ans << '\n';
    }
}