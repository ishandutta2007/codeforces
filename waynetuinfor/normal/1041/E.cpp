#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int c[maxn];
bool u[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        if (b < n) {
            puts("NO");
            return 0;
        }
        ++c[a];
    }
    vector<pair<int, int>> ed;
    for (int i = n - 1; i >= 1; --i) {
        if (c[i] == 0) continue;
        int v = n;
        for (int j = i - 1; j >= 1 && c[i] > 1; --j) {
            if (c[j] > 0) continue;
            if (u[j]) continue;
            ed.emplace_back(j, v);
            u[j] = true;
            v = j;
            --c[i];
        }
        if (c[i] > 1) {
            puts("NO");
            return 0;
        }
        u[i] = true;
        ed.emplace_back(i, v);
    }
    puts("YES");
    assert((int)ed.size() == n - 1);
    for (int i = 0; i < ed.size(); ++i) printf("%d %d\n", ed[i].first, ed[i].second);
    return 0;
}