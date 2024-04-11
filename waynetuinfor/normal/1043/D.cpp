#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[20][maxn], nxt[20][maxn];
int pos[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]), --a[i][j];
    }
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n - 1; ++j) nxt[i][a[i][j]] = a[i][j + 1];
    }
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        bool ok = (nxt[0][i] != -1);
        for (int j = 1; j < m; ++j) ok &= (nxt[j][i] == nxt[0][i] && nxt[j][i] != -1);
        if (ok) p.push_back(i);
    }
    for (int i = 0; i < n; ++i) pos[a[0][i]] = i;
    sort(p.begin(), p.end(), [&](int i, int j) { return pos[i] < pos[j]; });
    long long ans = n;
    // for (int i = 0; i < p.size(); ++i) printf("%d ", p[i]); puts("");
    for (int i = 0; i < (int)p.size(); ) {
        int j = i, c = pos[p[i]];
        while (j < (int)p.size() && pos[p[j]] == c) ++j, ++c;
        int len = j - i;
        ans += len * 1ll * (len + 1) / 2;
        i = j;
    }
    printf("%lld\n", ans);
    return 0;
}