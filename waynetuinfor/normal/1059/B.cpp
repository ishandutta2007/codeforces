#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
char s[maxn][maxn], t[maxn][maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) t[i][j] = '.';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 3 > n || j + 3 > m) continue;
            bool b = false;
            for (int k = i; k < i + 3; ++k) {
                for (int l = j; l < j + 3; ++l) {
                    if (k - i == 1 && l - j == 1) continue;
                    if (s[k][l] == '.') b = true;
                }
            }
            if (!b) {
                for (int k = i; k < i + 3; ++k) {
                    for (int l = j; l < j + 3; ++l) {
                        if (k - i == 1 && l - j == 1) continue;
                        t[k][l] = '#';
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] != t[i][j]) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}