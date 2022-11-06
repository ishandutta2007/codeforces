#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    set<int> s, b, u;
    int n; scanf("%d", &n);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        char t[10];
        int p;
        scanf("%s %d", t, &p);
        if (t[1] == 'D') {
            if (s.size() && p >= *s.begin()) s.insert(p);
            else if (b.size() && p <= *b.rbegin()) b.insert(p);
            else u.insert(p);
        } else {
            if (s.count(p)) {
                if (p != *s.begin()) return 0 * puts("0");
                s.erase(p);
                for (int x : u) b.insert(x);
                u.clear();
            } else if (b.count(p)) {
                if (p != *b.rbegin()) return 0 * puts("0");
                b.erase(p);
                for (int x : u) s.insert(x);
                u.clear();
            } else {
                (ans *= 2) %= mod;
                for (int x : u) {
                    if (x < p) b.insert(x);
                    else if (x > p) s.insert(x);
                }
                u.clear();
            }
        }
    }
    ans = ans * 1ll * (u.size() + 1) % mod;
    printf("%d\n", ans);
    return 0;
}