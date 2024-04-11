#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
vector<int> g[maxn];
int a[maxn], b[maxn], d[maxn], ans[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            d[i] = 0;
            ans[i] = -1;
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] > 0) --a[i];
        }
        for (int i = n - 1, j = 0; i >= 0; --i) {
            if (a[i] < n && a[i] >= 0) {
                g[a[i]].push_back(i);
                ++d[i];
            }

            while (j > 0 && b[j - 1] < a[i]) {
                --j;
                g[i].push_back(b[j]);
                ++d[b[j]];
            }
            b[j++] = i;
        }

        queue<int> q;
        int v = n;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0) 
                q.push(i);
        }

        while (!q.empty()) {
            int x = q.front(); q.pop();
            ans[x] = v--;
            for (int i = 0; i < (int)g[x].size(); ++i) {
                int u = g[x][i];
                if (--d[u] == 0)
                    q.push(u);
            }
        }

        bool valid = true;
        for (int i = 0; i < n; ++i)
            valid &= ans[i] >= 0;

        if (!valid) {
            puts("-1");
        } else {
            for (int i = 0; i < n; ++i)
                printf("%d ", ans[i]);
            puts("");
        }
    }
    return 0;
}