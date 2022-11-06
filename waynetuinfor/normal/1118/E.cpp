#include <bits/stdc++.h>
using namespace std;

int b[10], g[10];
bool ok = false;

void dfs(int x, int y, int z, int n, int k) {
    if (ok) return;
    if (x == n) {
        bool z = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (b[i] == b[j] && g[i] == g[j]) z = false;
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (b[i] == b[i + 1] || g[i] == g[i + 1]) z = false;
        }
        if (z) {
            ok = true;
        }
        return;
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i == j) continue;
            if (i == y || j == z) continue;
            b[x] = i;
            g[x] = j;
            dfs(x + 1, b[x], g[x], n, k);
        }
    }
}

void solve(int n, int k) {
    dfs(0, 0, 0, n, k);
    if (ok) puts("OK");
    else puts("NO");
}

int main() {
    int n, k; scanf("%d%d", &n, &k);
    if (k * 1ll * k - k < n) {
        puts("NO");
        return 0;
    } 
    puts("YES");
    int x = 2;
    while (x * 1ll * x - x < n) ++x;
    vector<pair<int, int>> v;
    set<pair<int, int>> s, t;
    int p = 0;
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j < i; ++j) {
            if (p < n) printf("%d %d\n", i, j);
            ++p;
            if (p < n) printf("%d %d\n", j, i);
            ++p;
        }
    }
     
}