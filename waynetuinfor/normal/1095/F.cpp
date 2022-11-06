#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
long long a[maxn];
int fa[maxn];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    vector<tuple<long long, int, int>> ed;
    for (int i = 0; i < m; ++i) {
        int x, y; long long w; 
        scanf("%d%d%lld", &x, &y, &w);
        ed.emplace_back(w, x - 1, y - 1);
    }
    int s = min_element(a, a + n) - a;
    for (int i = 0; i < n; ++i) {
        if (i == s) continue;
        ed.emplace_back(a[i] + a[s], i, s);
    }
    sort(ed.begin(), ed.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) fa[i] = i;
    for (int i = 0; i < (int)ed.size(); ++i) {
        long long w; int x, y;
        tie(w, x, y) = ed[i];
        if ((x = find(x)) == (y = find(y))) continue;
        ans += w;
        fa[x] = y;
    }
    printf("%lld\n", ans);
    return 0;
}