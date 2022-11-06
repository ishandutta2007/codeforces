#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
vector<int> graf[maxn];
int deg[maxn];
bool v[maxn];
map<pair<int, int>, int> ed;

int main() {
    int n, p; scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        ++deg[a], ++deg[b];
        graf[a].push_back(b), graf[b].push_back(a);
        ed[minmax(a, b)]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int u : graf[i]) if (!v[u]) {
            v[u] = true;
            if (deg[i] + deg[u] - ed[minmax(i, u)] >= p) ++ans;
            if (deg[u] + deg[i] >= p) --ans;
        }
        for (int u : graf[i]) v[u] = false;
    }
    for (int i = 1; i <= n; ++i) if (deg[i] + deg[i] >= p) --ans;
    sort(deg + 1, deg + n + 1);
    for (int i = 1; i <= n; ++i) ans += n - (lower_bound(deg + 1, deg + n + 1, p - deg[i]) - deg) + 1;
    ans >>= 1;
    printf("%lld\n", ans);
    return 0;
}