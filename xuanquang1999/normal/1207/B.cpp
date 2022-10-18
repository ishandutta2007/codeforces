#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int n, m, a[MAXN][MAXN], b[MAXN][MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);

    vector<pair<int, int>> ans;
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            if (a[i][j] && a[i-1][j] && a[i][j-1] && a[i-1][j-1]) {
                b[i][j] = b[i-1][j] = b[i][j-1] = b[i-1][j-1] = 1;
                ans.push_back({i, j});
            }
        }
    }

    bool ok = true;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if (a[i][j] != b[i][j])
                ok = false;

    if (!ok)
        puts("-1");
    else {
        printf("%d\n", ans.size());
        for(pair<int, int> p: ans)
            printf("%d %d\n", p.first, p.second);
    }

    return 0;
}