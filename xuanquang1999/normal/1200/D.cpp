#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

int n, k, d[MAXN][MAXN];
char s[MAXN][MAXN];

int update(int x1, int y1, int x2, int y2) {
    ++d[x1][y1];
    --d[x2+1][y1];
    --d[x1][y2+1];
    ++d[x2+1][y2+1];
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i)
        scanf("%s", s[i]);

    for(int i = 0; i < n; ++i) {
        int l = 0, r = n - 1;
        while (l < n && s[i][l] == 'W')
            ++l;
        while (r >= 0 && s[i][r] == 'W')
            --r;

        if (l == n)
            update(0, 0, n-k, n-k);
        else if (r - l < k){
            int x1 = max(0, r - k + 1);
            int x2 = min(n - k, l);
            int y1 = max(0, i - k + 1);
            int y2 = min(n - k, i);
            update(x1, y1, x2, y2);
        }
    }

    for(int j = 0; j < n; ++j) {
        int l = 0, r = n - 1;
        while (l < n && s[l][j] == 'W')
            ++l;
        while (r >= 0 && s[r][j] == 'W')
            --r;

        if (l == n)
            update(0, 0, n-k, n-k);
        else if (r - l < k){
            int x1 = max(0, j - k + 1);
            int x2 = min(n - k, j);
            int y1 = max(0, r - k + 1);
            int y2 = min(n - k, l);
            update(x1, y1, x2, y2);
        }
    }

    for(int i = 0; i <= n-k; ++i) {
        for(int j = 0; j <= n-k; ++j) {
            if (i > 0) d[i][j] += d[i-1][j];
            if (j > 0) d[i][j] += d[i][j-1];
            if (i > 0 && j > 0) d[i][j] -= d[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i = 0; i <= n-k; ++i)
        for(int j = 0; j <= n-k; ++j)
            ans = max(ans, d[i][j]);

    printf("%d", ans);

    return 0;
}