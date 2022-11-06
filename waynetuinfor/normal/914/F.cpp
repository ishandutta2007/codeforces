#include <bits/stdc++.h>
using namespace std;

const int kN = 100'000;
bitset<kN> pos[26];
char s[kN + 1], t[kN + 1];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) pos[s[i] - 'a'].set(i);
    int q; scanf("%d", &q);
    while (q--) {
        int tp; scanf("%d", &tp);
        if (tp == 1) {
            int i; char c[2];
            scanf("%d%s", &i, c);
            --i;
            pos[s[i] - 'a'].reset(i);
            s[i] = c[0];
            pos[s[i] - 'a'].set(i);
        } else {
            int l, r; scanf("%d%d%s", &l, &r, t);
            --l, --r;
            int m = strlen(t);
            if (r - l + 1 < m) {
                puts("0");
                continue;
            }
            r -= m - 1;
            bitset<kN> ans;
            ans.set();
            for (int i = 0; i < m; ++i) ans &= pos[t[i] - 'a'] >> i;
            bitset<kN> x = ans, y = ans;
            x >>= r + 1;
            y <<= kN - l;
            int res = ans.count() - x.count() - y.count();
            printf("%d\n", res); 
        }
    }
    return 0;
}