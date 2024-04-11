#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int r[maxn], deg[maxn];
int ans[maxn];
vector<int> g[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &r[i]);
    while (k--) {
        int x, y; scanf("%d %d", &x, &y); --x, --y;
        if (r[x] < r[y]) ++deg[y];
        if (r[y] < r[x]) ++deg[x];
    }
    vector<int> o(n); iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [](const int &i, const int &j) { return r[i] < r[j]; });
    int p = 0;
    for (int i = 0; i < n; ++i) {
        int x = o[i];
        while (p < n && r[o[p]] < r[x]) ++p;
        ans[x] = p - deg[x];
    }
    for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
    puts("");
    return 0;
}