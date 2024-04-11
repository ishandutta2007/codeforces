#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; scanf("%d%d", &n, &q);
    set<int> s[2];
    int p = 0;
    while (q--) {
        int r, c; scanf("%d%d", &r, &c);
        r--, c--;
        if (s[r].count(c)) {
            for (int i = -1; i <= 1; ++i) {
                if (s[r ^ 1].count(c + i)) --p;
            }
            s[r].erase(c);
        } else {
            for (int i = -1; i <= 1; ++i) {
                if (s[r ^ 1].count(c + i)) ++p;
            }
            s[r].insert(c);
        }
        if (p > 0) puts("No");
        else puts("Yes");
    }
}