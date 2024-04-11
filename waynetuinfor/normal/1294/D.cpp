#include <bits/stdc++.h>
using namespace std;

const int kN = 400'000 + 5;
int cnt[kN];

int main() {
    int q, x; scanf("%d%d", &q, &x);
    set<pair<int, int>> s;
    for (int i = 0; i < x; ++i) s.insert(make_pair(0, i));
    while (q--) {
        int y; scanf("%d", &y);
        s.erase(make_pair(cnt[y % x], y % x));
        ++cnt[y % x];
        s.insert(make_pair(cnt[y % x], y % x));
        auto ans = *s.begin();
        printf("%d\n", ans.first * x + ans.second);
    }
}