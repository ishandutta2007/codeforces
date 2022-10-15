#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr int nmax = 14, mmax = 100;
int tower_cost[1 << nmax][nmax], quest_cost[1 << nmax][mmax];
int tower_dp[1 << nmax][mmax + 1], quest_dp[1 << nmax][mmax];

using cpx = complex<int>;
int dist(cpx a, cpx b) {
    a -= b;
    return abs(a.real()) + abs(a.imag());
}

template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }
template<typename T>
bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<cpx> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = cpx(x, y);
    }
    vector<pair<int, cpx>> quests(m);
    for (auto& [t, pt] : quests) {
        int x, y;
        cin >> x >> y >> t;
        pt = cpx(x, y);
    }
    sort(all(quests), [&](auto p, auto q){ return p.first < q.first; });
    vector<int> t(m);
    for (int j = 0; j < m; ++j) tie(t[j], b[j]) = quests[j];

    for (int mask = 0; mask < (1 << n); ++mask) {
        fill(all(tower_dp[mask]), INF);
        fill(all(quest_dp[mask]), -INF);
        for (int i = 0; i < n; ++i) {
            tower_cost[mask][i] = INF;
            for (int p = 0; p < n; ++p) {
                if (mask >> p & 1) chmin(tower_cost[mask][i], dist(a[i], a[p]));
            }
        }
        for (int j = 0; j < m; ++j) {
            quest_cost[mask][j] = INF;
            for (int p = 0; p < n; ++p) {
                if (mask >> p & 1) chmin(quest_cost[mask][j], dist(b[j], a[p]));
            }
        }
    }
    for (int i = 0; i < n; ++i) tower_dp[1 << i][0] = 0;
    for (int j = 0; j < m; ++j) quest_dp[0][j] = 1;

    int ans = 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        // tower -> quest
        for (int x = 0; x < m; ++x) {
            for (int j = x; j < m; ++j) {
                int nt = tower_dp[mask][x] + quest_cost[mask][j];
                if (nt <= t[j]) chmax(quest_dp[mask][j], x + 1);
            }
        }
        for (int j = 0; j < m; ++j) {
            int done = quest_dp[mask][j];
            if (done < 0) continue;
            chmax(ans, done);
            // quest -> quest
            for (int k = j + 1; k < m; ++k) {
                int nt = t[j] + min(dist(b[j], b[k]), quest_cost[mask][k]);
                if (nt <= t[k]) chmax(quest_dp[mask][k], done + 1);
            }
            // quest -> tower
            for (int i = 0; i < n; ++i) {
                int nt = t[j] + min(dist(b[j], a[i]), tower_cost[mask][i]);
                chmin(tower_dp[mask | 1 << i][done], nt);
            }
        }
        // tower -> tower
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) continue;
            for (int x = 0; x < m; ++x) {
                chmin(tower_dp[mask | 1 << i][x], tower_dp[mask][x] + tower_cost[mask][i]);
            }
        }
    }

    cout << ans << endl;

    exit(0);
}