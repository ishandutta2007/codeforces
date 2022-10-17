#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <map>

using namespace std;

using uint = unsigned;
int n, p, q;
uint ans[2000200], binom[150];
map <int, int> vis;

void add(int x, int k) {
    for (int i = 2; i * i <= x; i++) while (x % i == 0) x /= i, vis[i] += k;
    if (x != 1) vis[x] += k;
}

int main() {
    cin >> n >> p >> q;
    binom[0] = 1;
    for (int i = 1; i <= min(p, n - 1); i++) {
        add(n - i + 1, 1);
        add(i, -1);
        binom[i] = 1;
        for (auto j: vis) for (int k = 1; k <= j.second; k++) binom[i] *= j.first;
    }
    uint out = 0;
    for (int m = 1; m <= q; m++) {
        uint cur = 1;
        for (int i = 0; i <= min(p, n - 1); i++, cur *= m)
            ans[m] += cur * binom[i];
        out ^= ans[m] * m;
    }
    printf("%u\n", out);
    return 0;
}