#include <bits/stdc++.h>
using namespace std;

const int maxn = 1500 + 1;
const int pr = 239;
bool v[maxn];
bitset<pr> mask[maxn];
vector<int> p;

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) p.push_back(i);
        for (int j = 0; i * p[j] < maxn; ++j) {
            v[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}

bitset<pr> min(const bitset<pr> &a, const bitset<pr> &b) {
    int pos = (a ^ b)._Find_first();
    if (pos == pr) return a;
    if (a[pos]) return b;
    return a;
}

int main() {
    sieve();
    for (int i = 1; i < maxn; ++i) {
        int x = i;
        for (int j = 0; j < p.size(); ++j) {
            while (x % p[j] == 0) x /= p[j], mask[i].flip(p.size() - j - 1);
        }
    }
    vector<bitset<pr>> v;
    int n; scanf("%d", &n);
    vector<int> ds;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        ds.push_back(x);
    }
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < ds.size(); ++i) {
        bitset<pr> t = mask[ds[i]];
        for (auto j : v) t = min(t, t ^ j);
        if (t.count()) v.push_back(t);
        assert(v.size() <= pr);
    }
    int ans = 1;
    for (int i = 0; i < n - v.size(); ++i) ans = ans * 2 % 1000000007;
    (ans += 1000000006) %= 1000000007;
    printf("%d\n", ans);
}