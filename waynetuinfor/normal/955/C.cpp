#include <bits/stdc++.h>
using namespace std;

vector<long long> v;

long long sq(long long t) {
    int d = 31;
    long long ans = 0;
    while (d--) if (ans + (1ll << d) <= 1000000000) {
        if ((ans + (1ll << d)) * (ans + (1ll << d)) <= t) ans += (1ll << d);
    }
    return ans;
}

void init() {
    for (int i = 2; i <= 1000000; ++i) {
        long long t = i * 1ll * i * i;
        while (t <= 1000000000000000000ll) {
            if (sq(t) * sq(t) != t) v.push_back(t);
            if (t * 1.0 * i <= 1000000000000000000ll) t *= i;
            else break;
        }
    }
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
}

long long solve(long long t) {
    return sq(t) + (long long)(upper_bound(v.begin(), v.end(), t) - v.begin());    
}

int main() {
    init();    
    int q; scanf("%d", &q);
    while (q--) {
        long long l, r; scanf("%" PRId64 "%" PRId64, &l, &r);
        printf("%" PRId64 "\n", solve(r) - solve(l - 1));
    }
    return 0;
}