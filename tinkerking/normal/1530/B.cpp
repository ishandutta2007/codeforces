#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n, m;
        scanf("%d%d",&n,&m);
        int len = 2 * (n + m) - 4;
        vector<vector<int> > a(n, vector<int>(m, 0));
        a[0][0] = a[n - 1][0] = a[0][m - 1] = a[n - 1][m - 1] = 1;
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        auto ok = [&](int x, int y) {
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny]) return false;
            }
            return true;
        };
        for (int i = 1; i < m - 1; i++) {
            if (ok(0, i)) a[0][i] = 1;
            if (ok(n - 1, i)) a[n - 1][i] = 1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (ok(i, 0)) a[i][0] = 1;
            if (ok(i, m - 1)) a[i][m - 1] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) printf("%d",a[i][j]);
            puts("");
        }
        puts("");
    }
}