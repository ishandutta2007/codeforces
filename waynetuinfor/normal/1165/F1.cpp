#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
vector<int> s[maxn], e[maxn];
int n, m, sum, k[maxn], last[maxn], lf[maxn];

bool check(int d) {
    for (int i = 0; i < 2 * sum; ++i) e[i].clear();
    for (int i = 0; i < n; ++i) {
        int p = lower_bound(s[i].begin(), s[i].end(), d) - s[i].begin();
        if (p > 0) last[i] = s[i][p - 1];
        else last[i] = d;

        e[last[i]].push_back(i);
    }

    int quota = 0;
    for (int i = 0; i < n; ++i) lf[i] = k[i];
    for (int i = 0; i < d; ++i) {
        ++quota;
        for (int p = 0; p < (int)e[i].size(); ++p) {
            int c = k[e[i][p]];
            int x = min(quota, c);
            lf[e[i][p]] = c - x;
            quota -= x;
        }
    }

    int t = 0;
    for (int i = 0; i < n; ++i) t += 2 * lf[i];
    return t <= quota;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &k[i]);

    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        s[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        sort(s[i].begin(), s[i].end());
        s[i].resize(unique(s[i].begin(), s[i].end()) - s[i].begin());
    }

    sum = accumulate(k, k + n, 0);
    int ans = 2 * sum;

    for (int d = 20; d >= 0; --d) {
        if (ans - (1 << d) >= 1) {
            if (check(ans - (1 << d)))
                ans -= (1 << d);
        }
    }

    printf("%d\n", ans);
    return 0;
}