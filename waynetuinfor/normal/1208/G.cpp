#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int phi[maxn], dv[maxn];

void sieve() {
    vector<int> pr;
    for (int i = 2; i < maxn; ++i) {
        if (!dv[i]) {
            dv[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] < maxn; ++j) {
            dv[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}

int main() {
    sieve();
    int n, k; scanf("%d%d", &n, &k);
    if (k == 1) {
        puts("3");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        int x = i;
        phi[i] = 1;
        while (x > 1) {
            int d = dv[x], c = 0, mult = 1;
            while (x % d == 0) ++c, mult *= d, x /= d;
            phi[i] *= mult - mult / d;
        }
    }
    sort(phi + 1, phi + n + 1);
    printf("%lld\n", accumulate(phi + 1, phi + k + 3, 0LL));
}