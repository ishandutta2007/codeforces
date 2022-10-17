#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n)), dp(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }
    vector<vector<vector<pair<int,int>>>> g(n, vector<vector<pair<int,int>>>(n));
    vector<ll> ans(n + 1);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            vector<pair<int,int>> b;
            int res = min(i + 1, j + 1);
            if(i > 0) {
                res = min(res, dp[i-1][j] + 1);
                for(auto &p : g[i-1][j]) b.push_back(p);
            }
            if(j > 0) {
                res = min(res, dp[i][j-1] + 1);
                for(auto &p : g[i][j-1]) b.push_back(p);
            }
            if(i > 0 && j > 0) {
                res = min(res, dp[i-1][j-1] + 1);
                for(auto &p : g[i-1][j-1]) b.push_back(p);
            }
            for(auto &p : b) p.second += 1;
            b.push_back({a[i][j], 0});
            sort(b.begin(), b.end());
            int tp = 0;
            for(int k = 0; k < b.size(); ++k) if(k == 0 || b[k-1].first != b[k].first) b[tp++] = b[k];
            b.resize(tp);
            sort(b.begin(), b.end(), [&](auto &i, auto &j) {return i.second < j.second;});
            if(b.size() > q) res = min(res, b[q].second);
            while(b.back().second >= res) b.pop_back();
            g[i][j] = b;
            dp[i][j] = res;
            ans[res] += 1;
        }
    }
    for(int i = n - 1; i >= 1; --i) ans[i] += ans[i+1];
    for(int i = 1; i <= n; ++i) cout << ans[i] << "\n";
}