#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 5;
int p[maxn], c[maxn];
vector<int> v[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d %d", &p[i], &c[i]);
    long long ans = 1e15;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) v[j].clear();
        for (int j = 0; j < n; ++j) v[p[j]].push_back(j);
        long long cur = 0;
        for (int j = 2; j <= m; ++j) {
            sort(v[j].begin(), v[j].end(), [&](int a, int b) { return c[a] > c[b]; });
            while (v[j].size() >= i) {
                int x = v[j].back();
                v[1].push_back(x);
                cur += c[x];
                v[j].pop_back();
            }
        }
        vector<int> all;
        for (int j = 2; j <= m; ++j) {
            for (int k : v[j]) all.push_back(k);
        }
        sort(all.begin(), all.end(), [&](int a, int b) { return c[a] > c[b]; });
        bool ok = true;
        while (v[1].size() < i) {
            if (all.size() == 0) {
                ok = false;
                break;
            }
            cur += c[all.back()];
            v[1].push_back(all.back());
            all.pop_back();
        }
        if (ok) ans = min(ans, cur);
    }
    printf("%lld\n", ans);
}