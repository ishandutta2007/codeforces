#include <bits/stdc++.h>

using namespace std;

int const N = 123456;

vector<int> edges[N];
int d[N], q[N], color[N], pv[N], comp[N];

int get(int v) {
    return pv[v] == v ? v : (pv[v] = get(pv[v]));
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) pv[i] = i;
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        --v;
        --u;
        edges[v].push_back(u);
        edges[u].push_back(v);
        pv[get(v)] = get(u);
    }
    for (int start = 0; start < n; start++) {
        fill(d, d + n, -1);
        fill(color, color + n, -1);
        d[start] = 0;
        int head = 0;
        int tail = 0;
        q[tail++] = start;
        color[start] = 0;
        while (head < tail) {
            int v = q[head++];
            comp[get(start)] = max(comp[get(start)], d[v]);
            for (int i : edges[v]) {
                if (d[i] == -1) {
                    d[i] = d[v] + 1;
                    color[i] = color[v] ^ 1;
                    q[tail++] = i;
                } else if (color[v] == color[i]) {
                    puts("-1");
                    return 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) if (get(i) == i) ans += comp[i];
    printf("%d\n", ans);
}