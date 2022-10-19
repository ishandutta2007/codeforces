#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> lft(n * n, -1), rgt(n * n, -1), up(n * n, -1), dwn(n * n, -1);
    int cnt_colors = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            x--;
            if (lft[x] == -1) {
                cnt_colors++;
                lft[x] = j;
                up[x] = i;
            } else {
                lft[x] = min(lft[x], j);
            }
            rgt[x] = max(rgt[x], j);
            dwn[x] = max(dwn[x], i);
        }
    }
    if (cnt_colors <= k) {
        cout << k - cnt_colors << '\n';
        return 0;
    }

    vector<vector<int>> sum(n, vector<int>(n));

    for (int square_len = 1; square_len <= n; square_len++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] = 0;
            }
        }
        for (int color = 0; color < n * n; color++) {
            if (lft[color] == -1 || rgt[color] - lft[color] + 1 > square_len || dwn[color] - up[color] + 1 > square_len) {
                continue;
            }
            int lj = max(0, rgt[color] - square_len + 1), rj = min(lft[color], n - square_len);
            int li = max(0, dwn[color] - square_len + 1), ri = min(up[color], n - square_len);

            sum[li][lj]++;
            if (rj + 1 < n) {
                sum[li][rj + 1]--;
            }
            if (ri + 1 < n) {
                sum[ri + 1][lj]--;
            }
            if (rj + 1 < n && ri + 1 < n) {
                sum[ri + 1][rj + 1]++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                sum[i][j] += sum[i][j - 1];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] += sum[i - 1][j];
            }
        }
        for (int i = 0; i + square_len - 1 < n; i++) {
            for (int j = 0; j + square_len - 1 < n; j++) {
                if (cnt_colors - sum[i][j] == k || cnt_colors - sum[i][j] == k - 1) {
                    cout << 1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << 2 << '\n';
    return 0;
}