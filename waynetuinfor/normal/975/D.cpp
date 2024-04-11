#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
long long x[maxn], vx[maxn], vy[maxn];
map<long long, int> cc;
map<pair<long long, long long>, int> pc;

long long c2(long long x) { return x * (x - 1) / 2; }

int main() { 
    int n; long long a, b;
    scanf("%d %lld %lld", &n, &a, &b);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &x[i], &vx[i], &vy[i]);
        cc[a * vx[i] - vy[i]]++;
        pc[make_pair(vx[i], vy[i])]++;
        // printf("%lld\n", a * vx[i] - vy[i]);
    }
    long long ans = 0;
    for (auto it : cc) ans += c2(it.second);
    for (auto it : pc) ans -= c2(it.second);
    printf("%lld\n", ans * 2);
    return 0;
}