#include <bits/stdc++.h>
using namespace std;

const int maxd = 61;
long long tpow[maxd], tag[maxd];

int ilog(long long x) {
    int z = 0;
    for (; (1ll << z) <= x; ++z);
    return --z;
}

long long fmul(long long a, long long b, long long p) {
    if (a < 0) a += p;
    long long r = 0;
    for (; b; b >>= 1, a = (a + a) % p) if (b & 1) r = (r + a) % p;
    return r;
}

int main() {
    int q; scanf("%d", &q);
    tpow[0] = 1;
    for (int i = 1; i < maxd; ++i) tpow[i] = tpow[i - 1] * 2ll;
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            long long x, k; scanf("%lld %lld", &x, &k);
            int d = ilog(x);
            tag[d] = (tag[d] + k) % tpow[d];
            tag[d] += tpow[d];
            tag[d] %= tpow[d];
        }
        if (t == 2) {
            long long x, k; scanf("%lld %lld", &x, &k);
            int d = ilog(x);
            for (int i = d; i < maxd; ++i) tag[i] = (tag[i] + fmul(k, tpow[i - d], tpow[i])) % tpow[i];
        }
        if (t == 3) {
            long long x; scanf("%lld", &x);
            int d = ilog(x);
            x = x + tag[d] % tpow[d] - tpow[d];
            for (; d >= 0; --d) {
                long long z = ((x - tag[d]) % tpow[d] + tpow[d]) % tpow[d] + tpow[d];
                printf("%lld ", z);
                x >>= 1;
            }
            puts("");
        } 
    }
    return 0;
}