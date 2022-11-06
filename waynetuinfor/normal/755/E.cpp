#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    if (k > 3 || k == 1) return 0 * puts("-1");
    if (k == 3) {
        if (n < 4) return 0 * puts("-1");
        vector<pair<int, int>> ed;
        for (int i = 2; i <= 4; ++i) ed.emplace_back(i - 1, i);
        for (int i = 5; i <= n; ++i) ed.emplace_back(i, 3);
        printf("%d\n", ed.size());
        for (int i = 0; i < ed.size(); ++i) printf("%d %d\n", ed[i].first, ed[i].second);
    } else {
        if (n <= 4) return 0 * puts("-1");
        vector<pair<int, int>> ed;
        for (int i = 2; i <= n; ++i) ed.emplace_back(i - 1, i);
        printf("%d\n", ed.size());
        for (int i = 0; i < ed.size(); ++i) printf("%d %d\n", ed[i].first, ed[i].second);
    }
    return 0;
}