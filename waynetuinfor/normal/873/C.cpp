#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int mt[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> mt[i][j];
    }
    int ans = 0, p = 0;
    for (int c = 1; c <= m; ++c) {
        int got = 0, ind = 1, now = 0;
        for (int i = 1; i <= k; ++i) now += mt[i][c];
        got = now;
        for (int i = k + 1; i <= n; ++i) {
            now -= mt[i - k][c]; now += mt[i][c];
            if (now > got) got = now, ind = i - k + 1;
        }
        for (int i = 1; i < ind; ++i) if (mt[i][c] == 1) ++p;
        ans += got;
    }
    cout << ans << ' ' << p << endl;
    return 0;
}