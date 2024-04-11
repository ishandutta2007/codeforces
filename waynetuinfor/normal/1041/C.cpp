#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int ans[maxn];

int main() {
    int n, m, d; scanf("%d %d %d", &n, &m, &d);
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        s.insert(make_pair(x, i));
    }
    int p = 0;
    while (s.size()) {
        int x = s.begin()->first;
        ans[s.begin()->second] = p;
        s.erase(s.begin());
        while (true) {
            auto it = s.lower_bound(make_pair(x + d + 1, -1));
            if (it == s.end()) break;
            ans[it->second] = p;
            x = it->first;
            s.erase(it);
        }
        ++p;
    }
    printf("%d\n", p);
    for (int i = 0; i < n; ++i) printf("%d ", ans[i] + 1);
    puts("");
    return 0;
}