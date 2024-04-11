#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int MN = 0;

struct Segment{
    ll l, r;
    bool operator<(const Segment &rhs) const{
        return tie(l, r) < tie(rhs.l, rhs.r);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector<ll> a; vector<Segment> b;
        for (int i = 1; i <= n; ++i){
            ll x; cin >> x;
            a.push_back(x);
        }
        a.push_back(-1e12); a.push_back(1e12);
        sort(a.begin(), a.end());
        for (int i = 1; i <= m; ++i){
            ll l, r; cin >> l >> r;
            if (*lower_bound(a.begin(), a.end(), l) <= r) continue;
            b.push_back({l, r});
        }
        sort(b.begin(), b.end());
        vector<vector<ll>> dp(a.size() + 1, vector<ll>(2, inf));
        dp[0][1] = dp[0][0] = 0;
        int p = 0;
        // 0  = no put back
        // 1 = put back
        for (int i = 1; i < a.size(); ++i){
            vector<Segment> cur;
            while (p < b.size() && b[p].r < a[i]) cur.push_back(b[p++]);
            if (cur.empty()){
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][0];
                continue;
            }
            for (int i = cur.size() - 2; i >= 0; --i) cur[i].r = min(cur[i].r, cur[i + 1].r);

            // suf clears all
            dp[i][0] = a[i] - cur[0].r + dp[i - 1][0];
            dp[i][1] = (a[i] - cur[0].r) * 2 + dp[i - 1][0];

            // pre up to j, suf from j + 1
            for (int j = 0; j < cur.size() - 1; ++j){
                // use last second
                dp[i][0] = min(dp[i][0], dp[i - 1][1] + (cur[j].l - a[i - 1]) + (a[i] - cur[j + 1].r));
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + (cur[j].l - a[i - 1]) + (a[i] - cur[j + 1].r) * 2);
                
                // use last first
                dp[i][0] = min(dp[i][0], dp[i - 1][0] + (cur[j].l - a[i - 1]) * 2 + (a[i] - cur[j + 1].r));
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + (cur[j].l - a[i - 1]) * 2 + (a[i] - cur[j + 1].r) * 2);
            }
            // pre clears all
            // use last second
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + cur.back().l - a[i - 1]);
            // use last first
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + (cur.back().l - a[i - 1]) * 2);
            dp[i][0] = min(dp[i][0], dp[i][1]);
            // cout << " -> " << dp[i][0] << " " << dp[i][1] << '\n';
        }
        cout << min(dp[a.size() - 1][0], dp[a.size() - 1][1]) << '\n';
    }
}