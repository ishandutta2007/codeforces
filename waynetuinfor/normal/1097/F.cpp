#pragma GCC optimize("O3")
#pragma GCC target("avx")

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
bitset<7001> bs[maxn];
bitset<7001> mt[7001], dv[7001];
int mu[maxn];

int main() {
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 1; i <= 7000; ++i) {
        for (int j = 1; j * j <= 7000; ++j) {
            if (i % j == 0) {
                dv[i].set(j);
                dv[i].set(i / j);
            }
        }
    }
    for (int i = 1; i <= 7000; ++i) mu[i] = 1;
    for (int i = 1; i <= 7000; ++i) {
        for (int j = 2; j <= 7000; ++j) {
            if (i % (j * j) == 0) mu[i] = 0;
        }
    }
    for (int i = 1; i <= 7000; ++i) {
        for (int j = i; j <= 7000; j += i) {
            if (mu[j / i] == 0) continue;
            mt[i].set(j);
        }
    }
    bitset<7001> p;
    while (q--) {
        int t, x, y; scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            bs[x] = dv[y];
        }
        if (t == 2) {
            int z; scanf("%d", &z);
            bs[x] = (bs[y] ^ bs[z]);
        }
        if (t == 4) {
            printf("%d", (bs[x] & mt[y]).count() & 1);
        }
        if (t == 3) {
            int z; scanf("%d", &z);
            bs[x] = (bs[y] & bs[z]); 
        }
    }
    return 0;
}