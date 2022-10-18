#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<pair<long long, int>> factor(long long n) {
    vector<pair<long long, int>> res;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            pair<long long, int> p;
            p.first = i;
            while (n % i == 0) {
                n /= i;
                p.second++;
            }
            res.emplace_back(p);
        }
    }
    if (n != 1) {
        res.emplace_back(n, 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vector<pair<ll, int>> p = factor(a[i]);
        for (auto e : p) {
            mp[e.first].emplace_back(e.second);
        }
    }
    ll ans = 1;
    for (auto e : mp) {
        vector<int> v = e.second;
        if (v.size() < n - 1) {
            continue;
        }
        if (v.size() == n - 1) {
            v.emplace_back(0);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v[1]; i++) {
            ans *= e.first;
        }
    }
    cout << ans << '\n';
    return 0;
}