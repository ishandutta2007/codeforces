#include <bits/stdc++.h>
using namespace std;

long long n, a, b;

int query(long long x, long long y) {
#ifndef LOCAL
    printf("%lld %lld\n", x, y);
    fflush(stdout);
    int ans; scanf("%d", &ans);
    return ans;
#else
    printf("query x = %lld y = %lld\n", x, y);
    if (x == a && y == b) return 0;
    vector<int> q;
    if (x < a) q.push_back(1);
    if (y < b) q.push_back(2);
    if (x > a || y > b) q.push_back(3);
    random_shuffle(q.begin(), q.end());
    return q[0];
#endif
}

int main() {
    scanf("%lld", &n);
#ifdef LOCAL
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> dis(1, n);
    a = dis(gen), b = dis(gen);
    printf("a = %lld b = %lld\n", a, b);
#endif
    long long x = 0, y = 0, dx = 1, dy = 1;
    int cnt = 0;
    while (true) {
        ++cnt;
        assert(cnt <= 600);
        long long qx = min(x + dx, n), qy = min(y + dy, n);
        int ans = query(qx, qy);
        if (ans == 0) break;
        if (ans == 1) x = qx, dx <<= 1;
        if (ans == 2) y = qy, dy <<= 1;
        if (ans == 3) {
            if (dx > 1) dx >>= 1;
            if (dy > 1) dy >>= 1;
        }
    }
}