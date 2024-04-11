#include <bits/stdc++.h>
using namespace std;

long long sqr(long long x) {
    long long res = pow(x, 0.5);
    while (res * res < x) ++res;
    while (res * res > x) --res;
    return res;
}

long long cbr(long long x) {
    long long res = pow(x, 1. / 3);
    while (res * res * res < x) ++res;
    while (res * res * res > x) --res;
    return res;
}

long long qdr(long long x) {
    long long res = pow(x, 0.25);
    while (res * res * res * res < x) ++res;
    while (res * res * res * res > x) --res;
    return res;
}

int main() {
    int n; scanf("%d", &n);
    map<long long, int> cnt;
    vector<long long> pq;
    for (int i = 0; i < n; ++i) {
        long long x; scanf("%lld", &x);
        long long a = sqr(x), b = cbr(x), c = qdr(x);
        if (c * c * c * c == x) cnt[c] += 4;
        else if (b * b * b == x) cnt[b] += 3;
        else if (a * a == x) cnt[a] += 2;
        else pq.push_back(x);
    }
    vector<long long> v;
    for (int i = 0; i < (int)pq.size(); ++i) {
        long long p = -1, q = -1;
        for (int j = i + 1; j < (int)pq.size(); ++j) {
            if (pq[i] == pq[j]) continue;
            long long g = __gcd(pq[i], pq[j]);
            if (g == 1) continue;
            p = g, q = pq[i] / g;
            break;
        }
        if (~p) {
            ++cnt[p];
            ++cnt[q];
        } else {
            v.push_back(pq[i]);
        }
    }
    map<long long, int> f;
    for (int i = 0; i < (int)v.size(); ++i) {
        long long p = -1, q = -1;
        for (auto it : cnt) {
            if (v[i] % it.first == 0) {
                p = it.first;
                q = v[i] / it.first;
                break;
            }
        }
        if (~p) {
            ++cnt[p];
            ++cnt[q];
        } else {
            ++f[v[i]];
        }
    }
    int ans = 1;
    for (auto it : cnt) ans = 1ll * ans * (it.second + 1) % 998244353;
    for (auto it : f) ans = 1ll * ans * (it.second + 1) % 998244353 * (it.second + 1) % 998244353;
    printf("%d\n", ans);
    fflush(stdout);
}