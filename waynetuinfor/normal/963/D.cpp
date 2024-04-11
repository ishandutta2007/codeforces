#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int maxn = 1e5 + 5, mod = 1073807359, p = 3137;
char s[maxn], t[maxn];
int hs[maxn], pw[maxn], ans[maxn];
vector<pair<int, int>> qr[maxn];
vector<int> pos[maxn];
cc_hash_table<int, int> rev;

int main() {
    scanf("%s", s);
    int n = strlen(s);
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) pw[i] = pw[i - 1] * 1ll * p % mod;
    hs[0] = s[0];
    for (int i = 1; i < n; ++i) hs[i] = (hs[i - 1] * 1ll * p % mod + s[i]) % mod;
    int q; scanf("%d", &q);
    vector<int> v;
    for (int i = 0; i < q; ++i) {
        int k; scanf("%d", &k);
        scanf("%s", t);
        int h = 0;
        int m = strlen(t);
        for (int j = 0; j < m; ++j) h = (h * 1ll * p % mod + t[j]) % mod;
        qr[strlen(t)].emplace_back(k, i);
        rev[h] = i;
        v.push_back(strlen(t));
    }
    sort(v.begin(), v.end()), v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < v.size(); ++i) {
        int x = v[i], prv = 0;
        for (int j = x - 1; j < n; ++j) {
            int z = (hs[j] - pw[x] * 1ll * prv % mod + mod) % mod;
            if (rev.find(z) != rev.end()) pos[rev[z]].push_back(j);
            prv = hs[j - x + 1];
        }
        for (int j = 0; j < qr[x].size(); ++j) {
            int k, z; tie(k, z) = qr[x][j];
            if (pos[z].size() < k) {
                ans[z] = -1;
                continue;
            }
            ans[z] = maxn;
            for (int p = k - 1; p < pos[z].size(); ++p) ans[z] = min(ans[z], pos[z][p] - pos[z][p - k + 1] + x);
        }
    }
    for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
    return 0;
}