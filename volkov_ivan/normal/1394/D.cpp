#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7, INF = 1e12 + 7;
int dp[N][2];
int t[N], h[N];
vector <int> g[N];
int best = INF;

void dfs(int v, int par = -1) {
    deque <pair <int, int>> ll, rr;
    for (int u : g[v]) {
        if (u != par) {
            dfs(u, v);
            if (h[u] < h[v]) {
                ll.push_back({INF, dp[u][0]});
            }
            if (h[u] > h[v]) {
                rr.push_back({INF, dp[u][1]});
            }
            if (h[u] == h[v]) {
                if (dp[u][0] < dp[u][1]) {
                    ll.push_back({dp[u][1] - dp[u][0], dp[u][0]});
                } else {
                    rr.push_back({dp[u][0] - dp[u][1], dp[u][1]});
                }
            }
        }
    }
    sort(ll.begin(), ll.end());
    sort(rr.begin(), rr.end());
    int res = 0;
    dp[v][0] = dp[v][1] = INF;
    while (!ll.empty() && !rr.empty()) {
        res += ll.back().second + rr.back().second + t[v];
        ll.pop_back();
        rr.pop_back();
    }
    int summ = 0;
    for (auto elem : ll) summ += elem.second;
    for (auto elem : rr) summ += elem.second;
    if (ll.empty() && rr.empty()) {
        dp[v][0] = dp[v][1] = res + t[v];
        if (par == -1) best = res;
        return;
    }
    if (!ll.empty()) {
        dp[v][0] = res + summ + t[v] * ll.size();
        dp[v][1] = dp[v][0] + t[v];
        if (par == -1) best = dp[v][0];
    } else {
        dp[v][1] = res + summ + t[v] * rr.size();
        dp[v][0] = dp[v][1] + t[v];
        if (par == -1) best = dp[v][1];
    }
    //return;
    while (!ll.empty()) {
        if ((int) ll.size() == 1) {
            dp[v][0] = min(dp[v][0], res + summ + t[v]);
            dp[v][1] = min(dp[v][1], res + summ + t[v] + min(t[v], ll[0].first));
            if (par == -1) best = min(best, dp[v][0]);
            return;
        }
        dp[v][0] = min(dp[v][0], res + summ + (int) (t[v] * ll.size()));
        dp[v][1] = min(dp[v][1], res + summ + (int) (t[v] * ll.size() + t[v]));
        if (par == -1) best = min(best, dp[v][0]);
        //cout << ll.front().first << endl;
        res += ll.front().second + ll.back().second + ll.front().first + t[v];
        summ -= ll.front().second + ll.back().second;
        ll.pop_front();
        ll.pop_back();
    }
    if (ll.empty() && rr.empty()) {
        assert(summ == 0);
        dp[v][0] = min(dp[v][0], res + t[v]);
        dp[v][1] = min(dp[v][1], res + t[v]);
        if (par == -1) best = min(best, res);
    }
    //return;
    while (!rr.empty()) {
        if ((int) rr.size() == 1) {
            dp[v][1] = min(dp[v][1], res + summ + t[v]);
            dp[v][0] = min(dp[v][0], res + summ + t[v] + min(t[v], rr[0].first));
            if (par == -1) best = min(best, dp[v][1]);
            return;
        }
        dp[v][1] = min(dp[v][1], res + summ + (int) (t[v] * rr.size()));
        dp[v][0] = min(dp[v][0], res + summ + (int) (t[v] * rr.size() + t[v]));
        if (par == -1) best = min(best, dp[v][1]);
        res += rr.front().second + rr.back().second + rr.front().first + t[v];
        summ -= rr.front().second + rr.back().second;
        rr.pop_front();
        rr.pop_back();
    }
    if (rr.empty()) {
        dp[v][0] = min(dp[v][0], res + t[v]);
        dp[v][1] = min(dp[v][1], res + t[v]);
        if (par == -1) best = min(best, res);
    }
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1);
    best = min(best, min(dp[1][0], dp[1][1]));
    cout << best << endl;
}