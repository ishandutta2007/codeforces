#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
    set<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
        int dx = x[i] - x[(i + 1) % n];
        int dy = y[i] - y[(i + 1) % n];
        p.insert(make_pair(dx, dy));
    }
    for (auto it : p) {
        auto op = make_pair(-it.first, -it.second);
        if (!p.count(op)) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}