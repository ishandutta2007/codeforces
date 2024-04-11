#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int m = n * n;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
    vector<int> cnt(1001);
    for (int i = 0; i < m; ++i) ++cnt[a[i]];
    vector<int> odd;
    for (int i = 0; i < 1001; ++i) {
        if (cnt[i] & 1) odd.push_back(i);
    }
    if (n % 2 == 1 && (int)odd.size() != 1 || n % 2 == 0 && (int)odd.size() != 0) {
        puts("NO");
        return 0;
    } 
    vector<vector<int>> ans(n, vector<int>(n));
    if (n % 2 == 1) {
        ans[n / 2][n / 2] = odd[0];
        --cnt[odd[0]];
    }
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            int k = -1;
            for (int p = 0; p < 1001; ++p) {
                if (k == -1 || cnt[p] > cnt[k])
                    k = p;
            }
            if (cnt[k] < 4) {
                puts("NO");
                return 0;
            }
            ans[i][j] = k;
            ans[n - i - 1][j] = k;
            ans[i][n - j - 1] = k;
            ans[n - i - 1][n - j - 1] = k;
            cnt[k] -= 4;
        }
    }
    if (n % 2 == 1) {
        for (int i = 0; i < n / 2; ++i) {
            int k = -1;
            for (int p = 0; p < 1001; ++p) {
                if (k == -1 || cnt[p] > cnt[k])
                    k = p;
            }
            if (cnt[k] < 2) {
                puts("NO");
                return 0;
            }
            ans[i][n / 2] = k;
            ans[n - i - 1][n / 2] = k;
            cnt[k] -= 2;
        }
        for (int i = 0; i < n / 2; ++i) {
            int k = -1;
            for (int p = 0; p < 1001; ++p) {
                if (k == -1 || cnt[p] > cnt[k])
                    k = p;
            }
            if (cnt[k] < 2) {
                puts("NO");
                return 0;
            }
            ans[n / 2][i] = k;
            ans[n / 2][n - i - 1] = k;
            cnt[k] -= 2;
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf("%d ", ans[i][j]);
        puts("");
    }
}