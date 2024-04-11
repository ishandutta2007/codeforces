#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<vector<ll>> v(n);
        rep(i, 0, n) {
            int m, p;
            cin >> m >> p;
            v[m].emplace_back(p);
        }
        priority_queue<int, vector<int>, greater<int>> q;
        ll res = 0;
        int cnt = 0, pref = n;
        for (int i = n - 1; i >= 0; i--) {
            pref -= v[i].size();
            int need = i - pref;
            for (auto x : v[i])
                q.push(x);
            while (cnt < need) {
                cnt++;
                res += q.top();
                q.pop();
            }
        }
        cout << res << endl;
    }
}