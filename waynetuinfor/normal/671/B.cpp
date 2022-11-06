#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10, inf = 1e9 + 1;
int c[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    long long s = 0;
    for (int i = 0; i < n; ++i) cin >> c[i], s += c[i];
    if (n == 1) return cout << "0" << endl, 0;
    sort(c, c + n);
    int d = 30, lw = 0;
    while (d--) if (lw + (1 << d) < inf) {
        long long dlt = 0;
        for (int i = 0; i < n; ++i) if (c[i] < lw + (1 << d)) dlt += lw + (1 << d) - c[i];
        if (dlt <= k) lw += (1 << d);
    }
    d = 30; int hg = inf;
    while (d--) if (hg - (1 << d) >= 0) {
        long long dlt = 0;
        for (int i = 0; i < n; ++i) if (c[i] > hg - (1 << d)) dlt += c[i] - (hg - (1 << d));
        if (dlt <= k) hg -= (1 << d);
    }
    if (hg > lw) cout << hg - lw << endl;
    else cout << (s % n ? 1 : 0) << endl;
    return 0;
}