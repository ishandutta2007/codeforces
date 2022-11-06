#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e6 + 10, mod = 1e9 + 7, inf = mod;
int tp[maxn], md[maxn];

void init();

int main() {
    int t, l, r; cin >> t >> l >> r;
    tp[0] = 1;
    for (int i = 1; i < maxn; ++i) tp[i] = (long long)tp[i - 1] * (long long)t % mod;
    init();
    int ans = 0;
    for (int i = l; i <= r; ++i) {
        int cur = i;
        long long jizz = 0;
        while (cur > 1) {
            long long d = md[cur];
            jizz += cur * (d - 1) / 2;
            jizz %= mod; cur /= d;
        }
        ans = ((long long)ans + (long long)tp[i - l] * jizz % mod) % mod;
    }
    cout << ans << endl;
}

void init() {
    vector<int> prime;
    bitset<maxn> v;
    fill(md, md + maxn, inf);
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) prime.push_back(i), md[i] = i;
        for (int j = 0; i * prime[j] < maxn; ++j) {
            v[i * prime[j]] = true;
            md[i * prime[j]] = min(md[i * prime[j]], prime[j]);
            if (i % prime[j] == 0) break;
        }
    }
}