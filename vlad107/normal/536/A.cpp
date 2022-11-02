#include <stdio.h>
#include <iostream>

using namespace std;

bool ok(long long u, long long v, long long l, long long r, long long t, long long m) {
    if (u + v * r > t) return false;
    long long sum = (u + v * l) * (r - l + 1);
    long long s2 = (r - l) * (r - l + 1) / 2;
    sum += s2 * v;
    sum = (sum + m - 1) / m;
    return sum <= t;
}

int main() {
//  freopen("input.txt", "r", stdin);
    int u, v, n;
    scanf("%d%d%d", &u, &v, &n);
    for (int i = 0; i < n; i++) {
        int l, t, m;
        scanf("%d%d%d", &l, &t, &m);
        --l;
        long long ll = l - 1;
        long long rr = 1e12;
        while (ll < rr - 1) {
            long long mid = (ll + rr) / 2;
            if (ok(u, v, l, mid, t, m)) {
                ll = mid;
            } else {
                rr = mid;
            }
        }
        if (ll < l) ll = -1; else ll++;
        cout << ll << "\n";
    }
}