#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
pair <int, int> dp[N];
vector <int> g[N];
vector <int> childs[N];
vector <int> ordered;

void dfs(int v, int par = -1) {
    for (int u : g[v]) {
        if (u != par) {
            childs[v].push_back(u);
            dfs(u, v);
        }
    }
    ordered.push_back(v);
}

pair <int, int> calc_dp(int lam) {
    for (int v : ordered) {
        if (childs[v].empty()) {
            dp[v] = {1 + lam, 1};
        } else {
            pair <int, int> maxi = {-2 * N, 0};
            for (int u : childs[v]) {
                if (dp[u] > maxi) {
                    maxi = dp[u];
                }
            }
            if (maxi.first < 0) {
                dp[v] = {maxi.first + 1, maxi.second};
            } else {
                dp[v] = {1, 0};
                for (int u : childs[v]) {
                    if (dp[u].first >= 0) {
                        dp[v].first += dp[u].first;
                        dp[v].second += dp[u].second;
                    }
                }
            }
        }
        //cout << lam << ' ' << v << ' ' << dp[v].first << endl;
    }
    if (dp[ordered.back()].first < 0)
        return {0, 0};
    return dp[ordered.back()];
}

int get(int n, int b) {
    b = min(b, (n + 1) / 2);
    return b * (b - n);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (childs[i].empty())
            c++;
    }
    if (c <= k) {
        k = min(k, (n + 1) / 2);
        cout << k * (n - k) << "\n";
        return 0;
    }
    int l = -N, r = 0, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        //cout << mid << ' ' << calc_dp(mid).second << endl;
        if (calc_dp(mid).second >= k)
            r = mid;
        else
            l = mid;
    }
    auto [ans_r, t_r] = calc_dp(r);
    ans_r = ans_r - r * t_r;
    auto [ans_l, t_l] = calc_dp(l);
    ans_l = ans_l - l * t_l;
    assert(ans_r >= 0 && ans_r <= n);
    assert(ans_l >= 0 && ans_l <= n);
    if (t_r == k) {
        cout << k * (n - k) + get(n, n - ans_r) << "\n";
    } else {
        assert((ans_r - ans_l) % (t_r - t_l) == 0);
        int ans = ans_l + ((ans_r - ans_l) / (t_r - t_l)) * (k - t_l);
        cout << k * (n - k) + get(n, n - ans) << "\n";
    }
    return 0;
}