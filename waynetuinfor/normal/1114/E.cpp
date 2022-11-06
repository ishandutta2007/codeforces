#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], d, x1, xn;

mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

int randrange(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

void prepare(int n) {
    // d = rand() % 1000000000;
    d = 1;
    x1 = randrange(0, 1000000000);
    for (int i = 1; i <= n; ++i) a[i] = x1 + (i - 1) * d;
    xn = a[n];
    shuffle(a + 1, a + n + 1, rng);
}

int query2(int x) {
#ifdef LOCAL
    if (xn > x) return 1;
    else return 0;
#else
    printf("> %d\n", x);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
#endif
}

int query1(int i) {
#ifdef LOCAL
    return a[i];
#else
    printf("? %d\n", i);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
#endif
}

int main() {
    int n; scanf("%d", &n);
#ifdef LOCAL
    prepare(n);
#endif
    int ans = 0;
    int query = 60;
    for (int d = 29; d >= 0; --d) {
        int t = ans + (1 << d);
        if (t > 1000000000) continue;
        int res = query2(t);
        --query;
        if (res == 1) ans = t;
    }
    ++ans;
    vector<int> ask;
    for (int i = 1; i <= n; ++i) ask.push_back(i);
    shuffle(ask.begin(), ask.end(), rng);
    vector<int> v;
    for (int i = 0; i < min(query, (int)ask.size()); ++i) {
        int res = query1(ask[i]);
        v.push_back(res);
    }
    int g = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
        for (int j = i + 1; j < (int)v.size(); ++j)
            g = __gcd(g, abs(v[i] - v[j]));
    }
    printf("! %d %d\n", ans - (n - 1) * g, g);
    fflush(stdout);
#ifdef LOCAL
    assert(g == d);
    assert(ans - (n - 1) * g == x1);
#endif
}