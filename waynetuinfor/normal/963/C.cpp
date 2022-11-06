#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int mod[] = { 1000000009, 1000000007, 1000000123, 1000000087 };
long long w[maxn], h[maxn], c[maxn];
vector<pair<long long, long long>> v[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld %lld %lld", &w[i], &h[i], &c[i]);
    vector<long long> ds;
    for (int i = 0; i < n; ++i) ds.push_back(w[i]);
    sort(ds.begin(), ds.end()), ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    vector<int> o(n); iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return h[i] < h[j]; });
    for (int i = 0; i < n; ++i) {
        int dw = lower_bound(ds.begin(), ds.end(), w[o[i]]) - ds.begin();
        if (v[dw].size() && v[dw].back().first == h[o[i]]) v[dw].back().second += c[o[i]];
        else v[dw].emplace_back(h[o[i]], c[o[i]]);
    }
    for (int i = 0; i < ds.size(); ++i) {
        if (v[i].size() != v[0].size()) return 0 * puts("0");
        for (int j = 0; j < v[0].size(); ++j) {
            if (v[i][j].first != v[0][j].first) return 0 * puts("0");
        } 
        for (int j = 0; j < v[i].size(); ++j) {
            bool z = true;
            for (int p = 0; p < 4; ++p) {
                int a = v[0][0].second % mod[p], b = v[i][0].second % mod[p];
                int c = v[0][j].second % mod[p], d = v[i][j].second % mod[p];
                if (a * 1ll * d % mod[p] != b * 1ll * c % mod[p]) z = false;
            } 
            if (!z) return 0 * puts("0");
        } 
    }
    long long g = 0;
    for (int i = 0; i < ds.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) g = __gcd(g, v[i][j].second);
    }
    int ans = 0;
    for (int i = 1; i * 1ll * i <= g; ++i) if (g % i == 0) {
        ++ans;
        if (i * 1ll * i < g) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}