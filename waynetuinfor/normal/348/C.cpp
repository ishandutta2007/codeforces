#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, threshold = 500;
long long a[maxn];
int h[maxn];
vector<int> deg[maxn], vu[maxn];

struct hset {
    int idx, sz;
    long long ans, tag;
    vector<int> dat;
    int cont[maxn];
    hset(int x): idx(x), ans(0), tag(0), sz(0) {
        memset(cont, 0, sizeof(cont));
        dat.clear();
    }
};

int main() {
    int n, m, q; scanf("%lld %lld %lld", &n, &m, &q);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    vector<hset> v;
    memset(h, -1, sizeof(h));
    for (int i = 1; i <= m; ++i) {
        int k; scanf("%d", &k);
        if (k > threshold) h[i] = v.size(), v.emplace_back(i);
        for (int j = 0; j < k; ++j) {
            int s; scanf("%d", &s);
            if (~h[i]) v[h[i]].dat.push_back(s), ++v[h[i]].sz, v[h[i]].ans += a[s];
            else vu[i].push_back(s);
            deg[s].push_back(i);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].dat.size(); ++j) {
            for (int k : deg[v[i].dat[j]]) ++v[i].cont[k];
        }
    }
    while (q--) {
        char s[2]; scanf("%s", s);
        if (s[0] == '?') {
            int k; scanf("%d", &k);
            if (~h[k]) {
                printf("%lld\n", v[h[k]].ans + v[h[k]].sz * 1ll * v[h[k]].tag);
                continue;
            }
            long long ans = 0;
            for (int i = 0; i < vu[k].size(); ++i) ans += a[vu[k][i]];
            for (int i = 0; i < v.size(); ++i) ans += v[i].cont[k] * 1ll * v[i].tag;
            printf("%lld\n", ans);
            continue;
        }
        int k, x; scanf("%d %d", &k, &x);
        if (~h[k]) {
            v[h[k]].tag += x;
            for (int i = 0; i < v.size(); ++i) if (i != h[k]) v[i].ans += x * 1ll * v[h[k]].cont[v[i].idx];
            continue;
        }
        for (int i = 0; i < vu[k].size(); ++i) a[vu[k][i]] += x;
        for (int i = 0; i < v.size(); ++i) v[i].ans += v[i].cont[k] * 1ll * x;
    }
    return 0;
}