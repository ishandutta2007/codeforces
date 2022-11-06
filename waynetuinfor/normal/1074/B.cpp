#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
vector<int> g[maxn];
bool a[maxn], b[maxn];
int d[maxn];

int query(char c, int x) {
    printf("%c %d\n", c, x + 1);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res - 1;
}

void answer(int x) {
    printf("C %d\n", x);
    fflush(stdout);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) g[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            --x, --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        memset(a, false, sizeof(a));
        memset(b, false, sizeof(b));
        int s; 
        scanf("%d", &s);
        for (int i = 0; i < s; ++i) {
            int x; scanf("%d", &x);
            a[x - 1] = true;
        }
        scanf("%d", &s);
        for (int i = 0; i < s; ++i) {
            int x; scanf("%d", &x);
            b[x - 1] = true;
        }
        int p = -1;
        for (int i = 0; i < n; ++i) {
            if (b[i]) p = i;
        }
        int f = query('B', p);
        memset(d, -1, sizeof(d));
        queue<int> qu;
        d[f] = 0, qu.push(f);
        while (qu.size()) {
            int x = qu.front(); qu.pop();
            for (const int &u : g[x]) {
                if (d[u] != -1) continue;
                d[u] = d[x] + 1;
                qu.push(u);
            }
        }
        int q = -1;
        for (int i = 0; i < n; ++i) {
            if (!a[i]) continue;
            if (q == -1 || d[i] < d[q]) q = i;
        }
        int k = query('A', q);
        if (b[k]) answer(q + 1);
        else answer(-1);
    }
}