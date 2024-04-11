#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 5;
int f[maxn], v[maxn], g[maxn];
vector<vector<int>> cache;

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &f[i]);
        --f[i];
    }

    int to_cycle = 0;
    long long l = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) g[j] = -1;
        int z = i, c = 0;
        while (g[z] == -1) {
            g[z] = c++;
            z = f[z];
        }
        to_cycle = max(to_cycle, g[z]);
        int p = c - g[z];
        l = l / __gcd(l, 1LL * p) * p;
    }
    // printf("to_cycle = %d l = %d\n", to_cycle, l);
    if (to_cycle == 0) printf("%lld\n", l);
    else printf("%lld\n", (to_cycle + l - 1) / l * l);
    return 0;
}