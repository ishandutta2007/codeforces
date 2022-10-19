#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, T;
int G[200005], C[200005], D[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> T;
    for (int i = 1; i <= n; ++i) {
        cin >> G[i] >> C[i];
    }
    ll sum = 0;
    for (int i = 2; i <= n; ++i) {
        cin >> D[i];
        sum += D[i];
        D[i] += D[i - 1];
        D[i] %= T;
        C[i] += D[i];
        C[i] %= T;
    }
    map<int, ll> ans;
    ans.erase(0);
    for (int i = 1; i <= n; ++i) {
        int s = (T - C[i]) % T, e = (T - C[i] + G[i]) % T;
        ans[s] = 0;
        ans[e - 1] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int s = (T - C[i]) % T, e = (T - C[i] + G[i]) % T;
        vector<int> R;
        if (s < e) {
            for (auto it = ans.lower_bound(e); it != ans.end(); ++it) R.push_back(it->first);
            for (auto it = ans.begin(); it != ans.end() && it->first < s; ++it) R.push_back(it->first);
        }
        else {
            for (auto it = ans.lower_bound(e); it != ans.end() && it->first < s; ++it) R.push_back(it->first);
        }
        if (R.empty()) continue;
        ll mn = 1e18;
        for (int x : R) {
            auto it = ans.find(x);
            ll cost = it->second;
            if (x < s) cost += s - x;
            else cost += s + T - x;
            mn = min(mn, cost);
            ans.erase(it);
        }
        auto it = ans.find(s);
        if (it == ans.end()) ans[s] = mn;
        else it->second = min(it->second, mn);
    }
    ll mn = 1e18;
    for (auto [_, y] : ans) mn = min(mn, y);
    printf("%lld\n", mn + sum);
    return 0;
}