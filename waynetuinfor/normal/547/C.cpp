#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int a[maxn], mindiv[maxn], c[maxn];
vector<int> pr;
bool v[maxn];

void sieve() {
    bitset<maxn> v;
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i), mindiv[i] = i;
        for (size_t j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            mindiv[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long ans = 0;
    int ins = 0;
    while (q--) {
        int x; cin >> x; --x;
        int now = a[x];
        vector<int> d;
        while (now > 1) {
            int di = mindiv[now];
            while (now % di == 0) now /= di;
            d.push_back(di);
        }
        assert(d.size() <= 6);
        int cur = 0;
        for (int s = 1; s < (1 << d.size()); ++s) {
            int ti = 1;
            for (int i = 0; i < d.size(); ++i) if ((1 << i) & s) ti *= d[i];
            if (__builtin_popcount(s) & 1) cur += c[ti] - (int)v[x];
            else cur -= c[ti] - (int)v[x];
        }
        for (int s = 1; s < (1 << d.size()); ++s) {
            int ti = 1;
            for (int i = 0; i < d.size(); ++i) if ((1 << i) & s) ti *= d[i];
            c[ti] += (v[x] ? -1 : 1);
        }
        cur = ins - cur - (int)v[x];
        ans += cur * (v[x] ? -1 : 1);
        v[x] ? --ins : ++ins;
        v[x] = !v[x];
        cout << ans << endl;
    }
    return 0;
}