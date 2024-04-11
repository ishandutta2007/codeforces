#include <bits/stdc++.h>
using namespace std;

const int kN = 300'000 + 5;
vector<int> b[kN];
int uf[kN * 2], sz[kN * 2], must[kN * 2];
char s[kN];

int Find(int x) {
    if (x == uf[x]) return x;
    return uf[x] = Find(uf[x]);
}

void Merge(int x, int y) {
    if ((x = Find(x)) == (y = Find(y))) return;
    uf[x] = y;
    sz[y] += sz[x];
    must[y] |= must[x];
}

int main() {
    int n, k; scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < k; ++i) {
        int c; scanf("%d", &c);
        for (int j = 0; j < c; ++j) {
            int x; scanf("%d", &x);
            b[x - 1].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) assert(b[i].size() < 3);
    for (int i = 0; i < n; ++i) {
        if (b[i].empty()) assert(s[i] == '1');
    }
    for (int i = 0; i < k + k; ++i) {
        uf[i] = i;
        if (i < k) sz[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i].size() == 1) {
            int j = b[i][0];
            if (!must[Find(j)] && !must[Find(j + k)]) {
                ans -= min(sz[Find(j)], sz[Find(j + k)]);
                if (s[i] == '1') {
                    must[Find(j + k)] = true;
                    ans += sz[Find(j + k)];
                } else {
                    must[Find(j)] = true;
                    ans += sz[Find(j)];
                }
            }
        } else if (b[i].size() == 2) {
            int u = b[i][0], v = b[i][1];
            if (must[Find(u)]) ans -= sz[Find(u)];
            else if (must[Find(u + k)]) ans -= sz[Find(u + k)];
            else ans -= min(sz[Find(u)], sz[Find(u + k)]);
            if (Find(v) != Find(u) && Find(v) != Find(u + k)) {
                if (must[Find(v)]) ans -= sz[Find(v)];
                else if (must[Find(v + k)]) ans -= sz[Find(v + k)];
                else ans -= min(sz[Find(v)], sz[Find(v + k)]);
            }
            if (s[i] == '0') {
                Merge(u, v + k);
                Merge(u + k, v);
            } else {
                Merge(u, v);
                Merge(u + k, v + k);
            }
            if (must[Find(u)]) ans += sz[Find(u)];
            else if (must[Find(u + k)]) ans += sz[Find(u + k)];
            else ans += min(sz[Find(u)], sz[Find(u + k)]);
        }
        printf("%d\n", ans);
    }
    return 0;
}