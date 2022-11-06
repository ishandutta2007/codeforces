#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
char s[kN];
int cnt[kN][26];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) cnt[i + 1][j] = cnt[i][j];
        cnt[i + 1][s[i] - 'a']++;
    }
    int q; scanf("%d", &q);
    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        if (l == r) {
            puts("Yes");
            continue;
        }
        int c = 0;
        for (int i = 0; i < 26; ++i) c += cnt[r][i] - cnt[l - 1][i] > 0;
        if (c >= 3 || c == 2 && s[l - 1] != s[r - 1]) puts("Yes");
        else puts("No");
    }
}