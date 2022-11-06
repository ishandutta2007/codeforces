#include <bits/stdc++.h>
using namespace std;

const int kN = 100'000 + 5;
char s[kN], t[kN];
int nxt[kN][26], pos[26];

int Solve() {
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    for (int i = 0; i < 26; ++i) {
        pos[i] = n;
        nxt[n][i] = n;
    }
    for (int i = n - 1; i >= 0; --i) {
        pos[s[i] - 'a'] = i;
        for (int j = 0; j < 26; ++j) nxt[i][j] = pos[j];
    }
    for (int i = 0; i < m; ++i) {
        if (pos[t[i] - 'a'] == n) return -1;
    }
    int res = 0;
    for (int i = 0; i < m; res++) {
        for (int j = pos[t[i++] - 'a']; i < m && nxt[j + 1][t[i] - 'a'] < n; j = nxt[j + 1][t[i++] - 'a']);
    }
    return res;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%d\n", Solve());
    return 0;
}