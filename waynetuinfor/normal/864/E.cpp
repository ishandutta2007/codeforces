#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, maxt = 2000 + 10;
int dp[maxn][maxt];
pair<int, int> t[maxn][maxt];

struct data {
    int t, d, p, id;
    bool operator<(const data& rhs) const {
        return d == rhs.d ? p > rhs.p : d < rhs.d;
    }
} a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].t >> a[i].d >> a[i].p, a[i].id = i;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < a[i].d; ++j) {
            dp[i][j] = dp[i - 1][j]; t[i][j] = make_pair(i - 1, j);
            if (j && dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                t[i][j] = make_pair(i, j - 1);
            }
            if (j - a[i].t >= 0) {
                if (dp[i - 1][j - a[i].t] + a[i].p > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - a[i].t] + a[i].p;
                    t[i][j] = make_pair(i - 1, j - a[i].t);
                }
            }
        }
    }
    cout << dp[n][a[n].d - 1] << endl;
    pair<int, int> cur = make_pair(n, a[n].d - 1);
    vector<int> ans;
    while (cur.first) {
        // cout << cur.first << ' ' << cur.second << endl;
        int f = t[cur.first][cur.second].first, s = t[cur.first][cur.second].second;
        if (f != cur.first && s != cur.second) ans.push_back(a[cur.first].id);
        cur = make_pair(f, s);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}