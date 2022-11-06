#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<pair<int, int>> graf[maxn];
long long a[maxn], b[maxn];
long long p, q;

long long dfs(int now) {
    long long s = 0;
    for (auto u : graf[now]) {
        long long t = dfs(u.first);
        if (t == 0) continue;
        if (t > 0) s += t;
        else {
            long double tmp = t * u.second;
            tmp += p;
            if (tmp < q) puts("NO"), exit(0);
            p += t * u.second;
            s += t * u.second;
        }      
    }
    b[now] += s;
    return b[now] - a[now];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]), p += b[i];
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), q += a[i];
    for (int i = 2; i <= n; ++i) {
        int x, k; scanf("%d %d", &x, &k);
        graf[x].emplace_back(i, k);
    }
    if (dfs(1) >= 0) puts("YES");
    else puts("NO");
    return 0;
}