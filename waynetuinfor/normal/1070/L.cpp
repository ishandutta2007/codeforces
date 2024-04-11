#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
int r[maxn], ans[maxn];
vector<int> g[maxn];
bitset<maxn> b[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            --x, --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        bool z = true;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() & 1) z = false;
        }
        if (z) {
            puts("1");
            for (int i = 0; i < n; ++i) printf("1 ");
            puts("");
            continue;
        }
        for (int i = 0; i < n; ++i) b[i].reset(), r[i] = 0;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() & 1) {
                b[i][i] = 1;
                for (const int &u : g[i]) b[i][u] = 1;
                r[i] = 1;
            } else {
                for (const int &u : g[i]) b[i][u] = 1;
                r[i] = 0;
            }
        }
        int last = 0;
        for (int i = 0; i < n; ++i) {
            int p = -1;
            for (int j = last; j < n; ++j) {
                if (b[j][i]) p = j;
            }
            if (p == -1) continue;
            swap(r[last], r[p]);
            swap(b[last], b[p]);
            for (int j = last + 1; j < n; ++j) {
                if (b[j][i]) {
                    b[j] ^= b[last];
                    r[j] ^= r[last];
                }
            }
            ++last;
        }
        for (int i = n - 1; i >= 0; --i) {
            int p = -1;
            for (int j = 0; j < n && !~p; ++j) {
                if (b[i][j]) p = j;
            }
            if (p == -1) continue;
            swap(b[p], b[i]);
            swap(r[p], r[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (b[i][i] == 0) {
                ans[i] = 0;
                continue;
            }
            int k = 0;
            for (int j = i + 1; j < n; ++j) if (b[i][j]) k ^= ans[j];
            ans[i] = (r[i] ^ k);
        } 
        puts("2");
        for (int i = 0; i < n; ++i) printf("%d ", ans[i] + 1);
        puts("");
    }
    return 0;
}