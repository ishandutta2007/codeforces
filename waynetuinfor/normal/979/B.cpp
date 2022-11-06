#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
char s[3][maxn];
int cnt[maxn], ans[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < 3; ++i) scanf("%s", s[i]);
    for (int i = 0; i < 3; ++i) {
        int m = strlen(s[i]);
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < m; ++j) ++cnt[s[i][j]];
        for (char j = 'a'; j <= 'z'; ++j) {
            int cc = cnt[j], ncc = m - cnt[j];
            if (ncc >= n) ans[i] = max(ans[i], cc + n);
            else if (n == 1 && cc == m) ans[i] = max(ans[i], m - 1);
            else ans[i] = max(ans[i], m);
        }
        for (char j = 'A'; j <= 'Z'; ++j) {
            int cc = cnt[j], ncc = m - cnt[j];
            if (ncc >= n) ans[i] = max(ans[i], cc + n);
            else if (n == 1 && cc == m) ans[i] = max(ans[i], m - 1);
            else ans[i] = max(ans[i], m);
        }
    }
    if (ans[0] > ans[1] && ans[0] > ans[2]) puts("Kuro");
    else if (ans[1] > ans[0] && ans[1] > ans[2]) puts("Shiro");
    else if (ans[2] > ans[0] && ans[2] > ans[1]) puts("Katie");
    else puts("Draw");
    return 0;
}