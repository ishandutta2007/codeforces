#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<set<pair<int, ll>>> dp(n);
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<vector<tuple<int,int,int,int>>> e(n);
        for(int i = 0; i < k; ++i) {
            int x1, y1, x2, y2, h;
            cin >> x1 >> y1 >> x2 >> y2 >> h;
            --x1, --y1, --x2, --y2;
            e[x1].push_back({y1, x2, y2, h});
        }
        dp[0].insert({0, 0});
        for(int i = 0; i < n - 1; ++i) {
            if(dp[i].empty()) continue;
            for(auto [y1, x2, y2, h] : e[i]) {
                auto it = dp[i].lower_bound({y1, -1e18});
                ll c = 1e18;
                if(it != dp[i].end()) {
                    c = min(c, 1ll * abs(y1 - it->first) * a[i] + it->second - h);
                }
                if(it != dp[i].begin()) {
                    --it;
                    c = min(c, 1ll * abs(y1 - it->first) * a[i] + it->second - h);
                }
                it = dp[x2].lower_bound({y2, -1e18});
                int ok = 1;
                if(it != dp[x2].end()) {
                    if(1ll * abs(y2 - it->first) * a[x2] + it->second <= c) {
                        ok = 0;
                    }
                }
                if(it != dp[x2].begin()) {
                    --it;
                    if(1ll * abs(y2 - it->first) * a[x2] + it->second <= c) {
                        ok = 0;
                    }
                }
                if(ok == 0) continue;
                dp[x2].insert({y2, c});
                it = ++dp[x2].find({y2, c});
                while(it != dp[x2].end()) {
                    if(1ll * abs(y2 - it->first) * a[x2] + c <= it->second) {
                        it = dp[x2].erase(it);
                    } else {
                        break;
                    }
                }
                it = dp[x2].find({y2, c});
                while(it != dp[x2].begin()) {
                    --it;
                    if(1ll * abs(y2 - it->first) * a[x2] + c <= it->second) {
                        it = dp[x2].erase(it);
                    } else {
                        break;
                    }
                }
            }
        }
        if(dp[n - 1].empty()) {
            cout << "NO ESCAPE\n";
        } else {
            auto it = dp[n - 1].lower_bound({m - 1, -1e18});
            ll c = 1e18;
            if(it != dp[n - 1].end()) {
                c = min(c, 1ll * abs(m - 1 - it->first) * a[n - 1] + it->second);
            }
            if(it != dp[n - 1].begin()) {
                --it;
                c = min(c, 1ll * abs(m - 1 - it->first) * a[n - 1] + it->second);
            }
            cout << c << '\n';
        }
    }
}