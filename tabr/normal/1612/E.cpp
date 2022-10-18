#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int z = (int) 2e5 + 10;
    vector<vector<int>> c(z, vector<int>(21));
    for (int i = 0; i < n; i++) {
        int m, k;
        cin >> m >> k;
        c[m][k]++;
    }
    pair<long long, long long> mx;
    mx.second = 1;
    vector<int> ans;
    for (int k = 1; k <= 20; k++) {
        vector<pair<long long, long long>> p(z);
        for (int i = 0; i < z; i++) {
            for (int j = 1; j <= 20; j++) {
                p[i].first += c[i][j] * min(j, k);
                p[i].second = k;
            }
        }
        vector<int> order(z);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int x, int y) { return p[x].first * p[y].second > p[y].first * p[x].second; });
        pair<long long, long long> t;
        vector<int> d;
        for (int i = 0; i < k; i++) {
            t.first += p[order[i]].first;
            t.second = p[order[i]].second;
            d.emplace_back(order[i]);
        }
        debug(k, t);
        if (t.first * mx.second > mx.first * t.second) {
            mx = t;
            swap(ans, d);
        }
    }
    {
        vector<long long> p(z);
        for (int i = 0; i < z; i++) {
            for (int j = 1; j <= 20; j++) {
                p[i] += c[i][j] * j;
            }
        }
        vector<int> order(z);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int x, int y) { return p[x] > p[y]; });
        for (int i = 1; i < z; i++) {
            p[order[i]] += p[order[i - 1]];
        }
        for (int i = 0; i < z; i++) {
            p[order[i]] /= i + 1;
        }
        int id = -1;
        for (int i = 20; i < z; i++) {
            if (p[order[i]] * mx.second > mx.first * (i + 1)) {
                id = i;
                mx.first = p[order[i]];
                mx.second = i + 1;
            }
        }
        if (id != -1) {
            ans.clear();
            for (int i = 0; i < z; i++) {
                ans.emplace_back(order[i]);
                if (order[i] == id) {
                    break;
                }
            }
        }
    }
    debug(mx);
    cout << ans.size() << '\n';
    for (int i : ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}