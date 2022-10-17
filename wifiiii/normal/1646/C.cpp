#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e12;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<ll> a;
    for(ll i = 1; i <= N; i *= 2) a.push_back(i);
    for(ll i = 1, j = 1; j <= N; ++i, j *= i) a.push_back(j);
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    vector<ll> l(a.begin(), a.begin() + 22), r(a.begin() + 22, a.end());
    vector<int> dp(233333, 1e9);
    dp[0] = 0;
    for(ll x : l) {
        for(int i = 120000; i >= x; --i) {
            dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    int m = r.size() / 2;
    vector<pair<ll,int>> la, ra;
    for(int i = 0; i < 1 << m; ++i) {
        ll x = 0;
        for(int j = 0; j < m; ++j) {
            if(i >> j & 1) {
                x += r[j];
            }
        }
        la.push_back({x, __builtin_popcount(i)});
    }
    int s = r.size();
    for(int i = 0; i < 1 << (s - m); ++i) {
        ll x = 0;
        for(int j = 0; j < (s - m); ++j) {
            if(i >> j & 1) {
                x += r[m + j];
            }
        }
        ra.push_back({x, __builtin_popcount(i)});
    }
    sort(la.begin(), la.end());
    sort(ra.begin(), ra.end());
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int ans = 1e9;
        for(auto [x, b] : ra) {
            if(x > n) break;
            auto p = upper_bound(la.begin(), la.end(), pair<ll,int>{n - x, 1e9});
            if(p != la.begin()) --p;
            while(1) {
                ll res = n - x - p->first;
                if(res > 120000) break;
                ans = min(ans, p->second + b + dp[res]);
                if(p == la.begin()) break; --p;
            }
        }
        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }
}