#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int p[maxn], v[maxn];
bool used[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < 2 * n; ++i) scanf("%d", &p[i]);
    memset(v, -1, sizeof(v));
    vector<pair<int, int>> e;
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        --a, --b;
        v[a] = b;
        v[b] = a;
        e.emplace_back(a, b);
    }
    int t; scanf("%d", &t);
    vector<int> u;
    for (int i = 0; i < 2 * n; ++i) if (v[i] == -1) u.push_back(i);
    sort(u.begin(), u.end(), [&](int i, int j) { return p[i] > p[j]; });
    if (t == 1) {
        for (int i = 0; i < m; ++i) {
            int x = e[i].first, y = e[i].second;
            if (p[x] < p[y]) swap(x, y);
            printf("%d\n", x + 1);
            fflush(stdout);
            int res; scanf("%d", &res);
            assert(res - 1 == y);
        }
        int j = 0;
        for (int i = 0; i < n - m; ++i) {
            while (j < (int)u.size() && used[u[j]]) ++j;
            printf("%d\n", u[j] + 1);
            fflush(stdout);
            int res; scanf("%d", &res);
            used[u[j]] = true;
            used[res - 1] = true;
        }
    } else {
        int q = 0;
        for (int i = 0; i < n; ++i) {
            int x; scanf("%d", &x); --x;
            q++;
            used[x] = true;
            if (v[x] == -1) {
                for (int j = 0; j < m; ++j) {
                    int x = e[j].first, y = e[j].second;
                    if (p[x] < p[y]) swap(x, y);
                    if (used[x]) continue;
                    printf("%d\n", x + 1);
                    q++;
                    fflush(stdout);
                    int res; scanf("%d", &res);
                    q++;
                    assert(res - 1 == y);
                    used[x] = used[res - 1] = true;
                }
                int j = 0;
                while (q < 2 * n) {
                    while (j < (int)u.size() && used[u[j]]) ++j;
                    if (j == u.size()) break;
                    printf("%d\n", u[j] + 1);
                    fflush(stdout);
                    q++;
                    if (q == 2 * n) break;
                    int res; scanf("%d", &res);
                    used[u[j]] = used[res - 1] = true;
                    q++;
                }
                break;
            } else {
                printf("%d\n", v[x] + 1);
                used[v[x]] = true;
                fflush(stdout);
                q++;
            }
        }        
    }
    return 0;
}