#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 500;
int n, p[N], c[N];
vector<int> g[N];

int main() {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
                scanf("%d%d", &p[i], &c[i]);
                if (p[i])
                        g[p[i]].push_back(i);
        }
        set<int> all;
        for (int i = 1; i <= n; i++) {
                if (c[i] == 1) {
                        bool ok = 1;
                        for (int j : g[i])
                                ok &= c[j];
                        if (ok)
                                all.insert(i);
                }
        }
        if (all.empty())
                printf("-1");
        for (int i : all)
                printf("%d ", i);
        return 0;
}