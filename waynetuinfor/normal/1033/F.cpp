#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, n, m; scanf("%d%d%d", &w, &n, &m);
    vector<int> cnt(1 << w);
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        cnt[a]++;
    }
    vector<int> pw(w + 1, 1);
    for (int i = 1; i <= w; ++i) pw[i] = pw[i - 1] * 3;
    vector<long long> pr(pw[w]);
    for (int i = 0; i < (1 << w); ++i) {
        for (int j = 0; j < (1 << w); ++j) {
            int a = i, b = j, c = 0;
            for (int k = 0; k < w; ++k) {
                if ((a & 1) == (b & 1) && (a & 1) == 1) c += 2 * pw[k];
                else if ((a & 1) != (b & 1)) c += pw[k];
                a >>= 1;
                b >>= 1;
            }
            pr[c] += 1LL * cnt[i] * cnt[j];
        }
    }
    for (int i = 0; i < m; ++i) {
        static char s[20];
        scanf("%s", s);
        reverse(s, s + w);

        function<long long(int, int)> Dfs = [&](int p, int v) {
            if (p == w) return pr[v];
            if (s[p] == 'A') return Dfs(p + 1, v) + Dfs(p + 1, v + pw[p]);
            if (s[p] == 'O') return Dfs(p + 1, v);
            if (s[p] == 'X') return Dfs(p + 1, v) + Dfs(p + 1, v + 2 * pw[p]);
            if (s[p] == 'a') return Dfs(p + 1, v + 2 * pw[p]);
            if (s[p] == 'o') return Dfs(p + 1, v + pw[p]) + Dfs(p + 1, v + 2 * pw[p]);
            if (s[p] == 'x') return Dfs(p + 1, v + pw[p]);
        };

        printf("%lld\n", Dfs(0, 0));
    }
}